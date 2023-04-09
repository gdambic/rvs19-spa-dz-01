#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape circle;
	sf::RectangleShape rect;
	float xVelocity = 3;
	float yVelocity = 3;
	sf::ConvexShape list;
	sf::Vector2f rectanglePosition;
	sf::CircleShape bee;
	sf::CircleShape oko;
	sf::RectangleShape stripe;
	sf::Clock clock;
	int p = 1;
	sf::Vector2f beeposition;
	int x_bee = 600;
	int x_oko = 610;
	int x_stripe = 655;
	
public:
	Cvijet(sf::RenderWindow* window);
	void draw_cvijet();
	void draw_stabiljka();
	void move_stabiljka();
	void draw_list();
	void draw_bee();
	void draw();
};

