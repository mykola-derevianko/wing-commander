#ifndef SFML_GAME_DATATABLES_HPP
#define SFML_GAME_DATATABLES_HPP

#include <vector>
#include "ResourceIdentifiers.hpp"

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
};


std::vector<AircraftData> initializeAircraftData();

#endif //SFML_GAME_DATATABLES_HPP
