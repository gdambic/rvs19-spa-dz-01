#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RectangleShape Korijen;
	sf::CircleShape Krug;
	sf::CircleShape KrugDva;
	sf::ConvexShape list;
	sf::CircleShape sunce;
	sf::RenderWindow* p;
public:
	Cvijet(sf::RenderWindow& w);
	void crtaj();
};

