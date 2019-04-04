#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	sf::Clock frameClock;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time dt = frameClock.restart();
		cvijet.duration += dt.asSeconds();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		cvijet.flower();
		cvijet.draw();

		window.display();
	}

	return 0;
}