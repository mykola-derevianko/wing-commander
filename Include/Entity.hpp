#ifndef SFML_GAME_ENTITY_HPP
#define SFML_GAME_ENTITY_HPP
#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"

class Entity : public SceneNode
{
public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);
    sf::Vector2f getVelocity() const;

    void accelerate(sf::Vector2f velocity);
    void accelerate(float vx, float vy);

private:
    sf::Vector2f mVelocity;
    void updateCurrent(sf::Time dt) override;
};



#endif
