#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

class Oblak
{
	std::array<sf::CircleShape, 3> latice;
	sf::RenderWindow* prozor;
public:
	Oblak(sf::RenderWindow& prozor);
	void draw();
};

