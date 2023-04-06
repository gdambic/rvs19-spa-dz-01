#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Sunce.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	//Cvijet cvijet(&window);

	Cvijet cvijet(&window);
	Sunce sunce(&window);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();
		sunce.draw();
		window.display();
	}

	return 0;
}