#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* address);
	void draw();
private:
	sf::RenderWindow* address;
	sf::Clock frameClock;
	sf::RectangleShape nebo;
	sf::RectangleShape livada;
	sf::RectangleShape stabljika;
	sf::RectangleShape stabljika2;
	sf::CircleShape list;
	sf::CircleShape list2;
	sf::CircleShape cvijet;
	sf::CircleShape cvijet2;
	sf::CircleShape cvijet3;
	sf::CircleShape cvijet4;
	sf::CircleShape cvijet5;
};