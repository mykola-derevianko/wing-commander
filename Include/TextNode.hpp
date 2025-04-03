//
// Created by derev on 3/23/2025.
//

#ifndef SFML_GAME_TEXTNODE_HPP
#define SFML_GAME_TEXTNODE_HPP
#include "SceneNode.hpp"
#include "ResourceIdentifiers.hpp"
#include "ResourceHolder.hpp"
class TextNode : public SceneNode{
public:
    explicit TextNode(const FontHolder& fonts, const std::string& text);
    void setString(const std::string& text);
private:
    void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Text mText;
};


#endif //SFML_GAME_TEXTNODE_HPP
