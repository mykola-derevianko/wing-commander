#include "../Include/DataTables.hpp"
#include "../Include/Aircraft.hpp"

std::vector<AircraftData> initializeAircraftData(){
    std::vector<AircraftData> data(Aircraft::TypeCount);

    data[Aircraft::Eagle].hitpoints = 100;
    data[Aircraft::Eagle].speed = 200.f;
    data[Aircraft::Eagle].texture = Textures::Eagle;

    data[Aircraft::Raptor].hitpoints = 20;
    data[Aircraft::Raptor].speed = 80.f;
    data[Aircraft::Raptor].texture = Textures::Raptor;
    data[Aircraft::Raptor].directions.emplace_back( 45, 80);
    data[Aircraft::Raptor].directions.emplace_back(-45, 160);
    data[Aircraft::Raptor].directions.emplace_back( 45, 80);

    data[Aircraft::Avenger].hitpoints = 40;
    data[Aircraft::Avenger].speed = 50.f;
    data[Aircraft::Avenger].texture = Textures::Avenger;
    data[Aircraft::Avenger].directions.emplace_back(+45, 50);
    data[Aircraft::Avenger].directions.emplace_back( 0, 50);
    data[Aircraft::Avenger].directions.emplace_back(-45, 100);
    data[Aircraft::Avenger].directions.emplace_back( 0, 50);
    data[Aircraft::Avenger].directions.emplace_back(+45, 50);

    return data;
}

