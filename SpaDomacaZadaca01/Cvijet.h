#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow *window);
	void draw();

private:
	sf::RenderWindow *mainwindow;
	sf::Clock clock;

	double animation;
	double animation2;
};

