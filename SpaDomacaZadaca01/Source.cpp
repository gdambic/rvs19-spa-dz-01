#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	window.clear(sf::Color(173, 216, 230));

	float sizedif = 0.3;

	float radius = 40;

	Clock clock;
	Time t1 = microseconds(1000000);

	Time elapsed1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		elapsed1 = clock.getElapsedTime();

		if (elapsed1 < t1) {
			radius += sizedif;
			std::cout << elapsed1.asSeconds() << std::endl;
		}
		else {
			clock.restart();
			radius = 40;
		}

		window.clear(sf::Color(173, 216, 230));
		cvijet.draw(radius);
		window.display();
	}

	return 0;
}