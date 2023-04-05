#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::CircleShape center;
	sf::ConvexShape petal;
	sf::RectangleShape stem;
	sf::RectangleShape cup;
public:
	Cvijet(float x, float y);
	void draw(sf::RenderWindow& window);
	void user_movement(float speed, sf::RenderWindow& window);
	
};
