#ifndef SFML_GAME_APPLICATION_HPP
#define SFML_GAME_APPLICATION_HPP

#include "ResourceIdentifiers.hpp"
#include "Player.hpp"
#include "StateStack.hpp"

class Application {
public:
    Application();
    void run();


private:
    void registerStates();
    void processInput();
    void update(sf::Time dt);
    void render();
    void updateStatistics(sf::Time dt);
private:
    static const sf::Time TimePerFrame;

    sf::RenderWindow mWindow;
    TextureHolder mTextures;
    FontHolder mFonts;
    Player mPlayer;

    StateStack mStateStack;

    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;

};


#endif //SFML_GAME_APPLICATION_HPP
