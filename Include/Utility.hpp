#ifndef SFML_GAME_UTILITY_HPP
#define SFML_GAME_UTILITY_HPP


#include <sstream>

template <typename T>
std::string toString(const T& value);

void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);

#include "Utility.inl"

#endif //SFML_GAME_UTILITY_HPP
