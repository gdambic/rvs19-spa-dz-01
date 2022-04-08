#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Sunce.h"

int main()
{
	// Disabling window resize
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	Cvijet cvijet(&window);
	Sunce sunce(&window, 16, 16);

	// Delta time used for normalizing animations
	// (making sure it's consistent at every framerate)
	sf::Clock deltaClock;
	sf::Time dt = deltaClock.restart();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sunce.tick(dt);

		window.clear();

		cvijet.draw();
		sunce.draw();

		// window.draw(shape);

		window.display();

		dt = deltaClock.restart();
	}

	return 0;
}