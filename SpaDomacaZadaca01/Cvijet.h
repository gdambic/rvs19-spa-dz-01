#pragma once
#include <SFML/Graphics.hpp>
//deklaracija
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::CircleShape circle2;
	sf::RectangleShape rect;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};




