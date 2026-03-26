#include <SFML/Graphics.hpp>
#include <vector>

#pragma once
struct Hydrangea {
	std::vector<sf::CircleShape> sepals;
	sf::CircleShape center;
	sf::RectangleShape stem;

	sf::Vector2f pos;
	std::vector<sf::Vector2f> sepal_pos;

	sf::Color color;

	float stem_rotation;

};