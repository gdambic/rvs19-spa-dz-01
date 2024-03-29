#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8.0;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Windy", sf::Style::Close, settings);

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	Cvijet cvijet(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "Resize.";
				break;
			}
		}

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}
