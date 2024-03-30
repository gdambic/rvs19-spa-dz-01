#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock clock;
	sf::Time elapsed;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

