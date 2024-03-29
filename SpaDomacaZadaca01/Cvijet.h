#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	void Draw();
private:
	void RotirajList(float deg);
	void GoreDolje();
	int counter = 0;
	int list_dir = -1;
	sf::RenderWindow* window;
	sf::Vector2f position;
	sf::CircleShape sunce;
	sf::CircleShape shape0;
	sf::CircleShape shape1;
	sf::RectangleShape stabljika;
	sf::ConvexShape list;

};

