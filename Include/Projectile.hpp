#ifndef SFML_GAME_PROJECTILE_HPP
#define SFML_GAME_PROJECTILE_HPP


#include <System/Vector2.hpp>
#include <Graphics/Rect.hpp>
#include <Graphics/Sprite.hpp>
#include "ResourceIdentifiers.hpp"
#include "CommandQueue.hpp"
#include "Entity.hpp"

class Projectile : public Entity{
public:
    enum Type{
        AlliedBullet,
        EnemyBullet,
        Missile,
        TypeCount
    };

public:
    Projectile(Type type, const TextureHolder& textures);

    void guideTowards(sf::Vector2f position);
    bool isGuided() const;
    unsigned int getCategory() const override;
    sf::FloatRect getBoundingRect() const override;
    float getMaxSpeed() const;
    int getDamage() const;
private:
    virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Type mType;
    sf::Sprite mSprite;
    sf::Vector2f mTargetDirection;
};


#endif //SFML_GAME_PROJECTILE_HPP
