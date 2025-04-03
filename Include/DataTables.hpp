#ifndef SFML_GAME_DATATABLES_HPP
#define SFML_GAME_DATATABLES_HPP

#include "Aircraft.hpp"
#include <vector>
#include "ResourceIdentifiers.hpp"
class Aircraft;
struct Direction{
    Direction(float angle, float distance)
            : angle(angle), distance(distance){}

    float angle;
    float distance;
};

struct AircraftData{
    int hitpoints;
    float speed;
    Textures::ID texture;
    std::vector<Direction> directions;
    sf::Time fireInterval;

};
struct ProjectileData{
    int damage;
    float speed;
    Textures::ID texture;
};

struct PickupData{
    std::function<void(Aircraft&)> action;
    Textures::ID texture;
};

std::vector<AircraftData> initializeAircraftData();
std::vector<ProjectileData> initializeProjectileData();
std::vector<PickupData> initializePickupData();
#endif //SFML_GAME_DATATABLES_HPP
