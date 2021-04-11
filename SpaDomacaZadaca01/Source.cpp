#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Dominik Arapov - DZ SPA", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			window.close();
		}

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}