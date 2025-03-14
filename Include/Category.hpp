
#ifndef SFML_GAME_CATEGORY_HPP
#define SFML_GAME_CATEGORY_HPP

namespace Category
{
    enum Type
    {
        None = 0,
        Scene = 1 << 0,
        PlayerAircraft = 1 << 1,
        AlliedAircraft = 1 << 2,
        EnemyAircraft = 1 << 3,
    };
}

#endif //SFML_GAME_CATEGORY_HPP
