#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello,from the other side ");
	window.setFramerateLimit(60);
	Cvijet cvijet(window);
	cvijet.draw();
	return 0;
}