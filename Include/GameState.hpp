#ifndef SFML_GAME_GAMESTATE_HPP
#define SFML_GAME_GAMESTATE_HPP


#include "World.hpp"
#include "StateStack.hpp"
#include "Player.hpp"
class GameState : public State{
public:
    GameState(StateStack& stack, Context context);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);
private:
    World mWorld;
    Player& mPlayer;
};


#endif //SFML_GAME_GAMESTATE_HPP
