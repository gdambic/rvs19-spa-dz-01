#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow& render_window;
public:
	Cvijet(sf::RenderWindow& window);
	sf::RenderWindow& getRenderWindow();
	void draw();
};

