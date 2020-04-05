#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Hello, SPA world!");
	window.setFramerateLimit(60);

	Cvijet cvijet(window);

	cvijet.draw();

	return 0;
}