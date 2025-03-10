#ifndef SFML_GAME_WORLD_HPP
#define SFML_GAME_WORLD_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <array>
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "ResourceHolder.hpp"
#include "CommandQueue.hpp"

class World : private sf::NonCopyable{
public:
    explicit World(sf::RenderWindow& window);
    void update(sf::Time dt);
    void draw();

    CommandQueue& getCommandQueue();

private:
    void loadTextures();
    void buildScene();
    void correctPlayerPosition();
    void correctPlayerVelocity();

    enum Layer{
        Background,
        Air,
        LayerCount
    };
private:
    sf::RenderWindow& mWindow;
    sf::View mWorldView;
    TextureHolder mTextures;

    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers{};

    sf::FloatRect mWorldBounds;
    sf::Vector2f mSpawnPosition;
    float mScrollSpeed;
    Aircraft* mPlayerAircraft;

    CommandQueue mCommandQueue;
};


#endif //SFML_GAME_WORLD_HPP
