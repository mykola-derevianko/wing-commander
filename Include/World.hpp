#ifndef SFML_GAME_WORLD_HPP
#define SFML_GAME_WORLD_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <array>
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "ResourceHolder.hpp"
#include "CommandQueue.hpp"

class World : private sf::NonCopyable{
public:
    explicit World(sf::RenderWindow& window, FontHolder& fonts);
    void update(sf::Time dt);
    void draw();

    CommandQueue& getCommandQueue();

private:
    void loadTextures();
    void buildScene();
    void correctPlayerPosition();
    void correctPlayerVelocity();
    void spawnEnemies();
    void addEnemies();
    void addEnemy(Aircraft::Type type, float relX, float relY);
    sf::FloatRect getBattlefieldBounds() const;
    sf::FloatRect getViewBounds() const;
    void adaptPlayerPosition();
    void adaptPlayerVelocity();
    void handleCollisions();

    void destroyEntitiesOutsideView();
    void guideMissiles();

private:
    enum Layer{
        Background,
        Air,
        LayerCount
    };
    struct SpawnPoint{
        SpawnPoint(Aircraft::Type type, float x, float y);
        Aircraft::Type type;
        float x;
        float y;
    };


private:
    sf::RenderWindow& mWindow;
    sf::View mWorldView;
    TextureHolder mTextures;

    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers{};

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Aircraft* mPlayerAircraft;

    CommandQueue mCommandQueue;

    std::vector<SpawnPoint> mEnemySpawnPoints;
    FontHolder& mFonts;
    std::vector<Aircraft*> mActiveEnemies;


};


#endif //SFML_GAME_WORLD_HPP
