#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window; // reference

public:

	Cvijet(sf::RenderWindow* window);
	void draw();

};

