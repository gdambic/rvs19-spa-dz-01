#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:

	sf::Clock frameClock;

	sf::RenderWindow* window;
	sf::RectangleShape stabljika;
	sf::ConvexShape laticad;
	sf::ConvexShape latical;
	sf::ConvexShape list;
	sf::CircleShape tucak;
	void set_trokut(sf::ConvexShape& trokut, sf::Vector2f point0, sf::Vector2f point1, sf::Vector2f point2, 
		float rotation, sf::Vector2f origin, sf::Vector2f position, sf::Color boja);

public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

