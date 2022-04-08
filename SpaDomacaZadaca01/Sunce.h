#pragma once
#include <SFML/Graphics.hpp>

class Sunce
{
private:
	sf::RenderWindow* window;
	sf::CircleShape circle;

	float size;
	float x, y;
	short sizeChangingDir;

public:
	Sunce(sf::RenderWindow* window, float x, float y);

	void tick(sf::Time& dt);
	void draw();
	void setPosition(float x, float y);
	float getSize();
};

