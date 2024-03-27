#pragma once
#include <SFML/Graphics.hpp>
class Sunce
{
private:
	sf::RenderWindow* window;
	float size = 0;
	float x = 20;
	float y = 20;
public:
	Sunce(sf::RenderWindow* window);
	void draw();
};