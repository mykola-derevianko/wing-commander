#ifndef SFML_GAME_COMMAND_HPP
#define SFML_GAME_COMMAND_HPP

#include <SFML/System/Time.hpp>
#include <functional>
#include <cassert>
#include <iostream>

class SceneNode;
struct Command{
    typedef std::function<void(SceneNode&, sf::Time)> Action;
    Command();
    Action action;
    unsigned int category;
};

template <typename GameObject, typename Function>
Command::Action derivedAction(Function fn)
{
    return [=] (SceneNode& node, sf::Time dt)
    {

        // Downcast node and invoke function on it
        fn(static_cast<GameObject&>(node), dt);

    };
}

#endif //SFML_GAME_COMMAND_HPP
