#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow *window;
public:
	Cvijet(sf::RenderWindow *window);
	void draw(int x,int y);
	void anidraw(sf::Clock frameClock);
};

