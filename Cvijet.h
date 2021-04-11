#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock frameClock;

public:
	Cvijet(sf::RenderWindow* window);
	void SetWindow(sf::RenderWindow* window);
	void Draw();
};