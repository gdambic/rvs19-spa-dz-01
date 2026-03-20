#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow& window);
	void draw();

private: 
	sf::RenderWindow& window;

	sf::CircleShape center;
	sf::CircleShape petal1;
	sf::CircleShape petal2;
	sf::CircleShape petal3;
	sf::CircleShape petal4;
	sf::RectangleShape stem;

	//animacije
	sf::CircleShape sun;
	sf::Clock frameClock;

	float sunRadius = 20.f;
	bool sunShrinking = true;
};

