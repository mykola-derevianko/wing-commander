#ifndef SFML_GAME_SPRITENODE_HPP
#define SFML_GAME_SPRITENODE_HPP


#include "SceneNode.hpp"

class SpriteNode : public SceneNode{
public:
    explicit SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite mSprite;
};


#endif //SFML_GAME_SPRITENODE_HPP
