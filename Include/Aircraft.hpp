#ifndef SFML_GAME_AIRCRAFT_HPP
#define SFML_GAME_AIRCRAFT_HPP


#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"
#include "DataTables.hpp"
#include "TextNode.hpp"

namespace
{
    const std::vector<AircraftData> Table = initializeAircraftData();
}

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
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    unsigned int getCategory() const override;
    float getMaxSpeed() const;


private:
    void updateTexts();
    void updateMovementPattern(sf::Time dt);



private:
    Type mType;
    sf::Sprite mSprite;
    TextNode* mHealthDisplay;
    float mTravelledDistance;
    std::size_t	mDirectionIndex;

};

#endif
