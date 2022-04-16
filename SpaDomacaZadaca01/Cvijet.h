#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw();
	void draw_flower(float x, float y);
	void draw_environment();
	void scene_animation();
private:
	sf::RenderWindow *window;
	sf::Clock clock;
};

