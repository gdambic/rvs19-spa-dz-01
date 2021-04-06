#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow &window;
public:
	Cvijet(sf::RenderWindow& window);
	void draw_glava();
	void draw_tijelo();
	void draw_latice();
	void draw_kruna();
	void draw();
};


