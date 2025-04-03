#ifndef SFML_GAME_UTILITY_HPP
#define SFML_GAME_UTILITY_HPP


#include <sstream>
#include <Window/Keyboard.hpp>

namespace sf{
    class Sprite;
    class Text;
}

template <typename T>
std::string toString(const T& value);

std::string toString(sf::Keyboard::Key key);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

float toDegree(float radian);
float toRadian(float degree);

int randomInt(int exclusiveMax);

float length(sf::Vector2f vector);
sf::Vector2f unitVector(sf::Vector2f vector);
#include "Utility.inl"

#endif //SFML_GAME_UTILITY_HPP
