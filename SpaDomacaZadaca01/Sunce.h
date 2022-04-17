#pragma once
#include <SFML/Graphics.hpp>
class Sunce
{
private:
	sf::RenderWindow* window;
	float x = 0;
	float y = 0;
public:
	Sunce(sf::RenderWindow* window);
	void draw();
};