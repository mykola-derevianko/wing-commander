#ifndef BOOK_PICKUP_HPP
#define BOOK_PICKUP_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"
#include "Command.hpp"
class Aircraft;

class Pickup : public Entity{
public:
    enum Type{
        HealthRefill,
        MissileRefill,
        FireSpread,
        FireRate,
        TypeCount
    };
public:
    Pickup(Type type, const TextureHolder& textures);
    virtual unsigned int getCategory() const;
    virtual sf::FloatRect getBoundingRect() const;
    void apply(Aircraft& player) const;


protected:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Type mType;
    sf::Sprite mSprite;
};

#endif // BOOK_PICKUP_HPP