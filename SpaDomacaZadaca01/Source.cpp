#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	// dodano tako da scena izgleda ljepse
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tulipan - Vladimir Sindler, 1RP2", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	// Posto SFML vec sadrzi timer, iskoristio sam njega umjesto chrono.
	sf::Clock clock;

	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		cvijet.draw(clock.getElapsedTime());
		window.display();
	}

	return 0;
}