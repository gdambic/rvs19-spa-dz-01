#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Kristijan Bobovec zadaca 1");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	cvijet.setColor(0, sf::Color(245, 245, 66)); // 0 - sredina cvijeta - color
	cvijet.setColor(1, sf::Color(191, 36, 129)); // 1 - latice cvijeta - color
	cvijet.setColor(2, sf::Color(36, 191, 67)); // 2 - stabljika + listovi cvijeta - color
	cvijet.setColor(3, sf::Color(245, 245, 66)); // 3 - sunce color

	sf::Clock clock;

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		cvijet.update(deltaTime);

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}