#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw(sf::CircleShape shape);
private:
	sf::RenderWindow window;
};