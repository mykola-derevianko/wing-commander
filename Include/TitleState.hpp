#ifndef SFML_GAME_TITLESTATE_HPP
#define SFML_GAME_TITLESTATE_HPP

#include "State.hpp"
#include <Graphics/Sprite.hpp>
#include <Graphics/Text.hpp>
#include <Graphics/RenderWindow.hpp>
class TitleState : public State{
public:
    TitleState(StateStack& stack, Context context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;

private:
    sf::Sprite mBackgroundSprite;
    sf::Text mText;
    bool mShowText;
    sf::Time mTextEffectTime;

};


#endif //SFML_GAME_TITLESTATE_HPP
