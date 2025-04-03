#ifndef SFML_GAME_ENTITY_HPP
#define SFML_GAME_ENTITY_HPP
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"
#include "CommandQueue.hpp"

class Entity : public SceneNode
{
public:
    explicit Entity(int points);
    void repair(int points);
    void damage(int points);
    void destroy();

    int getHitpoints() const;
    bool isDestroyed() const override;

private:
    int mHitpoints;

public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;

    void accelerate(sf::Vector2f velocity);
    void accelerate(float vx, float vy);

private:
    sf::Vector2f mVelocity;

protected:
    virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
};



#endif
