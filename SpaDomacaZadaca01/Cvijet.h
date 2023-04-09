#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow *window;
	sf::RectangleShape branch;
	sf::ConvexShape convex;
	sf::CircleShape circle;
	sf::CircleShape circle2;
	sf::ConvexShape leaf;
	sf::RectangleShape grass1;
	sf::RectangleShape grass2;
	sf::RectangleShape grass3;
	sf::RectangleShape grass4;
	sf::RectangleShape grass5;
	sf::RectangleShape grass6;
	sf::CircleShape raindrop;
	int y;

public:
	Cvijet(sf::RenderWindow *window);
	void draw();
};

