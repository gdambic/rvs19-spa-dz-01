#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;
	
	sf::RectangleShape ground;
	sf::CircleShape sun;

	void draw_flower(float x, float y);
	void draw_petal(float x, float y, float px, float py);
	void draw_cloud(float x, float y, bool r);
	void draw_cloud_part(float x, float y, bool r);

public:
	Cvijet(sf::RenderWindow* window);
	void draw(float radius);
};

