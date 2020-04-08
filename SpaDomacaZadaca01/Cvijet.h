#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
public:
	void draw();
	Cvijet(sf::RenderWindow *window);
private:
	sf::RenderWindow *window;
};

