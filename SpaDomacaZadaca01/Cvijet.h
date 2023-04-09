#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

class Cvijet
{
	sf::CircleShape sredina;
	std::array<sf::CircleShape, 5> latice;
	sf::RectangleShape stabljika;
	sf::ConvexShape list;
	sf::RenderWindow* prozor;

public:
	Cvijet(sf::RenderWindow& prozor);
	void draw();
	sf::Vector2f sredinaCvijeta();
	sf::Vector2f sredinaStabljike();
};

