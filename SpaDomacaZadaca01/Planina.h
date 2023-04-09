#pragma once
#include <SFML/Graphics.hpp>
class Planina
{
private:
	sf::RenderWindow* window;

public:
	Planina(sf::RenderWindow* window);
	void draw();
};
