#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow * window;
	sf::CircleShape* sun;
	sf::CircleShape* flowerHead;
	sf::CircleShape* flowerCore;
	sf::RectangleShape* flowerStem;
	sf::ConvexShape* leaf;
public:
	void draw();
	Cvijet(sf::RenderWindow* window);
	void move();
	~Cvijet();
};

