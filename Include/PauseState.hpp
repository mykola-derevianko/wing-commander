#ifndef SFML_GAME_PAUSESTATE_HPP
#define SFML_GAME_PAUSESTATE_HPP


#include <Graphics/Sprite.hpp>
#include <Graphics/Text.hpp>
#include "State.hpp"

class PauseState : public State{
public:
    PauseState(StateStack& stack, Context context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;


private:
    sf::Sprite mBackgroundSprite;
    sf::Text mPausedText;
    sf::Text mInstructionText;
};


#endif //SFML_GAME_PAUSESTATE_HPP
