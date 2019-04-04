#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
private:
	sf::RenderWindow *window;
	int boja, red = 0, blue = 255;
	float x = 0.0f, y = 0.0f;
public:
	double duration;

public:
	Cvijet(sf::RenderWindow *window);
	void flower();
	void draw();
};