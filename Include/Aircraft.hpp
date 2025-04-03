#ifndef SFML_GAME_AIRCRAFT_HPP
#define SFML_GAME_AIRCRAFT_HPP


#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"
#include "DataTables.hpp"
#include "TextNode.hpp"
#include "CommandQueue.hpp"
#include "Projectile.hpp"


class Aircraft : public Entity{
public:
    enum Type{
        Eagle,
        Raptor,
        Avenger,
        TypeCount
    };

public:
    Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);
    unsigned int getCategory() const override;
    float getMaxSpeed() const;
    void fire();
    void launchMissile();
    sf::FloatRect getBoundingRect() const override;
    bool isMarkedForRemoval() const override;
    bool isAllied() const;
    void increaseFireRate();
    void increaseSpread();
    void collectMissiles(unsigned int count);


private:
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
    void updateCurrent(sf::Time dt, CommandQueue& commands) override;
    void updateMovementPattern(sf::Time dt);
    void checkPickupDrop(CommandQueue& commands);
    void checkProjectileLaunch(sf::Time dt, CommandQueue& commands);
    void createBullets(SceneNode& node, const TextureHolder& textures) const;
    void createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;
    void createPickup(SceneNode& node, const TextureHolder& textures) const;
    void updateTexts();




private:
    Type mType;
    sf::Sprite mSprite;
    TextNode* mHealthDisplay;
    float mTravelledDistance;
    std::size_t	mDirectionIndex;
    Command mFireCommand;
    Command mMissileCommand;
    sf::Time mFireCountdown;
    bool mIsFiring;
    bool mIsLaunchingMissile;
    bool mIsMarkedForRemoval;
    int mFireRateLevel;
    int	mSpreadLevel;
    int mMissileAmmo;
    Command mDropPickupCommand;
    TextNode* mMissileDisplay;

};

#endif
