#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow * window;
	sf::Clock clock;
	float radius;
public:
	Cvijet(sf::RenderWindow *window);
	void draw();
	void set_radius(float radius);
};

