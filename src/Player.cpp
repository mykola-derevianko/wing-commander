#include <iostream>
#include "../Include/Player.hpp"
#include "../Include/Category.hpp"
struct AircraftMover{
    AircraftMover(float vx, float vy): velocity(vx,vy){}

    void operator()(Aircraft& aircraft, sf::Time) const{
        aircraft.accelerate(velocity);
    }

    sf::Vector2f velocity;
};

void Player::handleEvent(const sf::Event& event, CommandQueue& commands){
    if (event.type == sf::Event::KeyPressed){
        // Check if pressed key appears in key binding, trigger command if so
        auto found = mKeyBinding.find(event.key.code);
        if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
            commands.push(mActionBinding[found->second]);
    }
}
void Player::handleRealtimeInput(CommandQueue& commands)
{
    for(auto pair: mKeyBinding){
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
            commands.push(mActionBinding[pair.second]);
    }
}

Player::Player() {
    mKeyBinding[sf::Keyboard::Left] = MoveLeft;
    mKeyBinding[sf::Keyboard::Right] = MoveRight;
    mKeyBinding[sf::Keyboard::Up] = MoveUp;
    mKeyBinding[sf::Keyboard::Down] = MoveDown;
    mKeyBinding[sf::Keyboard::Space] = Fire;
    mKeyBinding[sf::Keyboard::M] = LaunchMissile;

    initializeActions();

    //Bind categories to player's aircraft
    for(auto& pair : mActionBinding)
        pair.second.category = Category::PlayerAircraft;
}

void Player::assignKey(Player::Action action, sf::Keyboard::Key key) {
    for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
    {
        if (itr->second == action)
            mKeyBinding.erase(itr++);
        else
            ++itr;
    }
    mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
    for(auto pair : mKeyBinding){
        if (pair.second == action)
            return pair.first;
    }
    return sf::Keyboard::Unknown;
}

void Player::initializeActions(){
    const float playerSpeed = 200.f;

    mActionBinding[MoveLeft].action	 = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
    mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
    mActionBinding[MoveUp].action    = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
    mActionBinding[MoveDown].action  = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
    mActionBinding[Fire].action = derivedAction<Aircraft>(std::bind(&Aircraft::fire, std::placeholders::_1));
    mActionBinding[LaunchMissile].action =derivedAction<Aircraft>(std::bind(&Aircraft::launchMissile, std::placeholders::_1));
}

bool Player::isRealtimeAction(Action action){
    switch (action){
        case MoveLeft:
        case MoveRight:
        case MoveDown:
        case MoveUp:
            return true;

        default:
            return false;
    }
}

void Player::setMissionStatus(MissionStatus status){
    mCurrentMissionStatus = status;
}

Player::MissionStatus Player::getMissionStatus() const{
    return mCurrentMissionStatus;
}

