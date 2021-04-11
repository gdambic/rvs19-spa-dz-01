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
};