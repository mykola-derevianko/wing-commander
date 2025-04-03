
#include "../Include/TextNode.hpp"
#include "../Include/Utility.hpp"

TextNode::TextNode(Category::Type category, const FontHolder &fonts, const std::string &text) : SceneNode(category) {
    mText.setFont(fonts.get(Fonts::Main));
    mText.setCharacterSize(20);
    setString(text);
}

void TextNode::setString(const std::string &text) {
    mText.setString(text);
    centerOrigin(mText);
}

void TextNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mText, states);
}
