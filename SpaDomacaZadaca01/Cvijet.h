#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow& win;
public:
	Cvijet(sf::RenderWindow& window);
	void draw();
};

