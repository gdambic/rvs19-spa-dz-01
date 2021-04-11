#pragma once
#include <SFML/Graphics.hpp>


class Cvijet
{
public:
	Cvijet(sf::RenderTarget* window);
	void draw(sf::Clock&);
private:
	sf::RenderTarget* _window;
	sf::CircleShape sredina;
	sf::CircleShape sunce;
	sf::RectangleShape stabljika;
	sf::ConvexShape list;
	float smjer_povecanja;
};
