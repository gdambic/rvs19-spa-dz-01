#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cvijet.h"
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!", sf::Style::Close, settings);
	window.setFramerateLimit(60);

	Cvijet cvijet(&window);

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

		window.display();
	}

	return 0;
}