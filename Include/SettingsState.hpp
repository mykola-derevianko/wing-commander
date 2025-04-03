#ifndef SFML_GAME_SETTINGSSTATE_HPP
#define SFML_GAME_SETTINGSSTATE_HPP


#include <array>
#include "State.hpp"
#include "Button.hpp"
#include "Container.hpp"
#include "Player.hpp"
#include "Label.hpp"

class SettingsState : public State{
public:
    SettingsState(StateStack& stack, Context context);

    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);


private:
    void updateLabels();
    void addButtonLabel(Player::Action action, float y, const std::string& text, Context context);


private:
    sf::Sprite mBackgroundSprite;
    GUI::Container mGUIContainer;
    std::array<GUI::Button::Ptr, Player::ActionCount> mBindingButtons;
    std::array<GUI::Label::Ptr, Player::ActionCount> mBindingLabels;
};


#endif //SFML_GAME_SETTINGSSTATE_HPP
