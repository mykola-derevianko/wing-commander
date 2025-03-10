#ifndef SFML_GAME_COMMANDQUEUE_HPP
#define SFML_GAME_COMMANDQUEUE_HPP


#include <queue>
#include "Command.hpp"

class CommandQueue {
public:
    void push(const Command& command);
    Command pop();
    bool isEmpty() const;
private:
    std::queue<Command> mQueue;
};


#endif //SFML_GAME_COMMANDQUEUE_HPP
