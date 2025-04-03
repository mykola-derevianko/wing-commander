#ifndef SFML_GAME_MENUSTATE_HPP
#define SFML_GAME_MENUSTATE_HPP

#include <Graphics/Sprite.hpp>
#include <vector>
#include <Graphics/Text.hpp>
#include "State.hpp"
#include "Container.hpp"

class MenuState : public State{
public:
    MenuState(StateStack& stack, Context& context);

    void draw() override;
    bool update(sf::Time dt) override;
    bool handleEvent(const sf::Event &event) override;

    void updateOptionText();

private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
};


#endif //SFML_GAME_MENUSTATE_HPP
