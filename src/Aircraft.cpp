#include <iostream>
#include <valarray>
#include "../Include/Aircraft.hpp"
#include "../Include/ResourceHolder.hpp"
#include "../Include/Category.hpp"
#include "../Include/Utility.hpp"

Textures::ID toTextureID(Aircraft::Type type)
{
    switch (type)
    {
        case Aircraft::Eagle:
            return Textures::Eagle;

        case Aircraft::Raptor:
            return Textures::Raptor;
    }
    return Textures::Eagle;
}

Aircraft::Aircraft(Aircraft::Type type, const TextureHolder &textures, const FontHolder &fonts) {
    std::cout<<"asd";
}

void Aircraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

unsigned int Aircraft::getCategory() const {
    switch (mType)
    {
        case Eagle:
            return Category::PlayerAircraft;
        default:
            return Category::EnemyAircraft;
    }
}

void Aircraft::updateTexts(){
    mHealthDisplay->setString(toString(getHitpoints()) + " HP");
    mHealthDisplay->setPosition(0.f, 50.f);
    mHealthDisplay->setRotation(-getRotation());
}

void Aircraft::updateMovementPattern(sf::Time dt) {
    const std::vector<Direction>& directions = Table[mType].directions;
    if(!directions.empty()){
        float distanceToTravel = directions[mDirectionIndex].distance;
        if (mTravelledDistance > distanceToTravel){
            mDirectionIndex = (mDirectionIndex + 1) % directions.size();
            mTravelledDistance = 0.f;
        }
        float radians = toRadian(directions[mDirectionIndex].angle + 90.f);
        float vx = getMaxSpeed() * std::cos(radians);
        float vy = getMaxSpeed() * std::sin(radians);
        setVelocity(vx, vy);
        mTravelledDistance += getMaxSpeed() * dt.asSeconds();
    }
}

float Aircraft::getMaxSpeed() const {
    return Table[mType].speed;
}
