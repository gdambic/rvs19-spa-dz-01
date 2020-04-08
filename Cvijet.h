#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
	sf::RenderWindow* window;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	
private:
	sf::RectangleShape stabiljka;
	sf::CircleShape circ1;
	sf::CircleShape circ2;

};

