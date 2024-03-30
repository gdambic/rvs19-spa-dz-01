#include <SFML/Graphics.hpp>

#include "Pozadina.h"
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	Pozadina pozadina(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Cyan);
		pozadina.draw();
		cvijet.draw();
		window.display();
	}

	return 0;
}