#ifndef SFML_GAME_AIRCRAFT_HPP
#define SFML_GAME_AIRCRAFT_HPP


#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity{
public:
    enum Type
    {
        Eagle,
        Raptor,
    };
    enum Textures{

    };

public:
    explicit Aircraft(Type type, const TextureHolder& textures);
    virtual void drawCurrent(sf::RenderTarget& target,
                             sf::RenderStates states) const;


private:
    Type mType;
    sf::Sprite mSprite;
};

#endif
