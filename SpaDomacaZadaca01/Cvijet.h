#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
	bool up = true;
	sf::RenderWindow* window;
	sf::Color green = sf::Color(70, 250, 70);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(800.f, 600.f));
	sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(12.f, 500.f));
	sf::CircleShape circle = sf::CircleShape(50.f, 12.f);
	sf::ConvexShape convex;
	sf::ConvexShape convex2;
	void setup();
public:
	Cvijet(sf::RenderWindow *window);
	void draw();
};

