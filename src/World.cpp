#include <valarray>
#include <set>
#include <limits>
#include "../Include/World.hpp"
#include "../Include/SpriteNode.hpp"
#include "../Include/Pickup.hpp"
#include "../Include/Utility.hpp"
World::World(sf::RenderWindow &window, FontHolder &fonts)
        : mWindow(window), mWorldView(window.getDefaultView()), mFonts(fonts), mTextures(), mSceneGraph(),
          mSceneLayers(), mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
          mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f),
          mScrollSpeed(-50.f), mPlayerAircraft(nullptr), mEnemySpawnPoints(), mActiveEnemies() {
    loadTextures();
    buildScene();

    mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures(){
    mTextures.load(Textures::Eagle, "Media/Textures/Eagle.png");
    mTextures.load(Textures::Raptor, "Media/Textures/Raptor.png");
    mTextures.load(Textures::Avenger, "Media/Textures/Avenger.png");
    mTextures.load(Textures::Desert, "Media/Textures/Desert.png");

    mTextures.load(Textures::Bullet, "Media/Textures/Bullet.png");
    mTextures.load(Textures::Missile, "Media/Textures/Missile.png");

    mTextures.load(Textures::HealthRefill, "Media/Textures/HealthRefill.png");
    mTextures.load(Textures::MissileRefill, "Media/Textures/MissileRefill.png");
    mTextures.load(Textures::FireSpread, "Media/Textures/FireSpread.png");
    mTextures.load(Textures::FireRate, "Media/Textures/FireRate.png");
}

void World::buildScene()
{
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        Category::Type category = (i == Air) ? Category::SceneAirLayer : Category::None;

        SceneNode::Ptr layer(new SceneNode(category));
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    sf::Texture& texture = mTextures.get(Textures::Desert);
    sf::IntRect textureRect(mWorldBounds);
    texture.setRepeated(true);

    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
    mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

    std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, mTextures, mFonts));
    mPlayerAircraft = player.get();
    mPlayerAircraft->setPosition(mSpawnPosition);
    mSceneLayers[Air]->attachChild(std::move(player));

    addEnemies();
}

void World::draw() {
    mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt)
{
    mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
    mPlayerAircraft->setVelocity(0.f, 0.f);

    destroyEntitiesOutsideView();
    guideMissiles();

    while (!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    adaptPlayerVelocity();

    handleCollisions();

    mSceneGraph.removeWrecks();
    spawnEnemies();

    mSceneGraph.update(dt, mCommandQueue);
    adaptPlayerPosition();
}

CommandQueue &World::getCommandQueue() {
    return mCommandQueue;
}

void World::correctPlayerPosition() {
    sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
    const float borderDistance = 40.f;

    sf::Vector2f position = mPlayerAircraft->getPosition();
    position.x = std::max(position.x, viewBounds.left + borderDistance);
    position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
    position.y = std::max(position.y, viewBounds.top + borderDistance);
    position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
    mPlayerAircraft->setPosition(position);
}


void World::correctPlayerVelocity() {
    sf::Vector2f velocity = mPlayerAircraft->getVelocity();
    if (velocity.x != 0.f && velocity.y != 0.f)
        mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));
    mPlayerAircraft->accelerate(0.f, mScrollSpeed);
}

void World::spawnEnemies() {
    while (!mEnemySpawnPoints.empty() && mEnemySpawnPoints.back().y > getBattlefieldBounds().top) {
        SpawnPoint spawn = mEnemySpawnPoints.back();

        std::unique_ptr<Aircraft> enemy(new Aircraft(spawn.type, mTextures, mFonts));
        enemy->setPosition(spawn.x, spawn.y);
        enemy->setRotation(180.f);
        mSceneLayers[Air]->attachChild(std::move(enemy));
        mEnemySpawnPoints.pop_back();
    }
}

sf::FloatRect World::getBattlefieldBounds() const {
    sf::FloatRect bounds = getViewBounds();
    bounds.top -= 100.f;
    bounds.height += 100.f;

    return bounds;
}

sf::FloatRect World::getViewBounds() const {
    return sf::FloatRect(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
}

void World::addEnemy(Aircraft::Type type, float relX, float relY) {
    SpawnPoint spawn(type, mSpawnPosition.x + relX, mSpawnPosition.y - relY);
    mEnemySpawnPoints.push_back(spawn);
}

void World::addEnemies() {
    addEnemy(Aircraft::Raptor, 0.f, 500.f);
    addEnemy(Aircraft::Raptor, 0.f, 1000.f);
    addEnemy(Aircraft::Raptor, +100.f, 1100.f);
    addEnemy(Aircraft::Raptor, -100.f, 1100.f);
    addEnemy(Aircraft::Avenger, -70.f, 1400.f);
    addEnemy(Aircraft::Avenger, -70.f, 1600.f);
    addEnemy(Aircraft::Avenger, 70.f, 1400.f);
    addEnemy(Aircraft::Avenger, 70.f, 1600.f);

    std::sort(mEnemySpawnPoints.begin(), mEnemySpawnPoints.end(), [](SpawnPoint lhs, SpawnPoint rhs) {
        return lhs.y < rhs.y;
    });
}

void World::adaptPlayerPosition() {
    sf::FloatRect viewBounds = getViewBounds();
    const float borderDistance = 40.f;
    sf::Vector2f position = mPlayerAircraft->getPosition();
    position.x = std::max(position.x, viewBounds.left + borderDistance);
    position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
    position.y = std::max(position.y, viewBounds.top + borderDistance);
    position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
    mPlayerAircraft->setPosition(position);
}

void World::adaptPlayerVelocity() {
    sf::Vector2f velocity = mPlayerAircraft->getVelocity();
    if (velocity.x != 0.f && velocity.y != 0.f)
        mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));
    mPlayerAircraft->accelerate(0.f, mScrollSpeed);
}

bool matchesCategories(SceneNode::Pair &colliders, Category::Type type1, Category::Type type2) {
    unsigned int category1 = colliders.first->getCategory();
    unsigned int category2 = colliders.second->getCategory();

    if (type1 & category1 && type2 & category2) {
        return true;
    } else if (type1 & category2 && type2 & category1) {
        std::swap(colliders.first, colliders.second);
        return true;
    } else {
        return false;
    }
}

void World::handleCollisions() {
    std::set<SceneNode::Pair> collisionPairs;
    mSceneGraph.checkSceneCollision(mSceneGraph, collisionPairs);

    for (SceneNode::Pair pair: collisionPairs) {
        if (matchesCategories(pair, Category::PlayerAircraft, Category::EnemyAircraft)) {
            auto &player = dynamic_cast<Aircraft &>(*pair.first);
            auto &enemy = dynamic_cast<Aircraft &>(*pair.second);

            // Collision: Player damage = enemy's remaining HP
            player.damage(enemy.getHitpoints());
            enemy.destroy();
        } else if (matchesCategories(pair, Category::PlayerAircraft, Category::Pickup)) {
            auto &player = dynamic_cast<Aircraft &>(*pair.first);
            auto &pickup = dynamic_cast<Pickup &>(*pair.second);

            pickup.apply(player);
            pickup.destroy();
        } else if (matchesCategories(pair, Category::EnemyAircraft, Category::AlliedProjectile)
                   || matchesCategories(pair, Category::PlayerAircraft, Category::EnemyProjectile)) {
            auto &aircraft = dynamic_cast<Aircraft &>(*pair.first);
            auto &projectile = dynamic_cast<Projectile &>(*pair.second);
            aircraft.damage(projectile.getDamage());
            projectile.destroy();
        }
    }
}

void World::destroyEntitiesOutsideView() {
    Command command;
    command.category = Category::Projectile | Category::EnemyAircraft;

    command.action = derivedAction<Entity>([this](Entity &e, sf::Time) {
        if (!getBattlefieldBounds().intersects(e.getBoundingRect()))
            e.destroy();
    });

    mCommandQueue.push(command);
}
float distance(const SceneNode& lhs, const SceneNode& rhs){
    return length(lhs.getWorldPosition() - rhs.getWorldPosition());
}
void World::guideMissiles() {
    Command enemyCollector;
    enemyCollector.category = Category::EnemyAircraft;
    enemyCollector.action = derivedAction<Aircraft>([this](Aircraft &enemy, sf::Time) {
        if (!enemy.isDestroyed())
            mActiveEnemies.push_back(&enemy);
    });

    Command missileGuider;
    missileGuider.category = Category::AlliedProjectile;
    missileGuider.action = derivedAction<Projectile>([this](Projectile &missile, sf::Time) {
        // Ignore unguided bullets
        if (!missile.isGuided())
            return;

        float minDistance = std::numeric_limits<float>::max();
        Aircraft *closestEnemy = nullptr;

        for(Aircraft* enemy : mActiveEnemies)
        {
            float enemyDistance = distance(missile, *enemy);

            if (enemyDistance < minDistance) {
                closestEnemy = enemy;
                minDistance = enemyDistance;
            }
        }

        if (closestEnemy)
            missile.guideTowards(closestEnemy->getWorldPosition());
    });

    // Push commands, reset active enemies
    mCommandQueue.push(enemyCollector);
    mCommandQueue.push(missileGuider);
    mActiveEnemies.clear();
}

World::SpawnPoint::SpawnPoint(Aircraft::Type type, float x, float y): type(type), x(x), y(y){}