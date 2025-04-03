#ifndef SFML_GAME_PLAYER_HPP
#define SFML_GAME_PLAYER_HPP

#include <SFML/Window/Event.hpp>
#include "CommandQueue.hpp"
#include "Aircraft.hpp"

class Player {

public:
    Player();
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commandQueue);

public:
    enum Action{
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        Fire,
        LaunchMissile,
        ActionCount
    };
    enum MissionStatus{
        MissionRunning,
        MissionSuccess,
        MissionFailure
    };
    void assignKey(Action action,sf::Keyboard::Key key);
    sf::Keyboard::Key getAssignedKey(Action action) const;

    void setMissionStatus(MissionStatus status);
    MissionStatus getMissionStatus() const;

private:
    void initializeActions();
    static bool isRealtimeAction(Action action);
    std::map<sf::Keyboard::Key, Action> mKeyBinding;
    std::map<Action, Command> mActionBinding;
    MissionStatus mCurrentMissionStatus;
};


#endif //SFML_GAME_PLAYER_HPP
