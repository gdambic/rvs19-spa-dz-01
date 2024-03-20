#include <SFML/Graphics.hpp>
#include "Cvijet.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);

	Cvijet cvijet(&window);

	cvijet.draw(&window, &cvijet);

	sf::Clock clock;

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.update(&cvijet, &dt);
		cvijet.draw(&window, &cvijet);
		window.display();
	}

	return 0;
}