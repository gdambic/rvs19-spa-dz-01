#pragma once
#include <SFML/Graphics.hpp>

class cvijet
{
public:
	cvijet(sf::RenderWindow* window) :MojProzor(window) {};
	void draw();
	void crtaj(sf::Clock* animacija);

private:

	sf::RenderWindow* MojProzor;
	sf::CircleShape circle;
	sf::CircleShape sun;
	sf::RectangleShape line;
	sf::ConvexShape convex;


	void Circle();
	void Line();
	void Convex();
	void Sun();

};