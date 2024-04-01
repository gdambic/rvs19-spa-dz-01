#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cvijet.h"

const sf::Color sky_color = sf::Color(0x407185ff);
const sf::Color ground_color = sf::Color(0x243b23ff);

int main()
{
	srand(0);

	// Initialize rendering
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8.0;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Windy", sf::Style::Close, settings);

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	// Initialize flower
	Cvijet::init_vertices(32);
	Cvijet cvijet(window);

	// Initialize timer
	float delta_time = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		delta_time = clock.restart().asSeconds();

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

		window.clear(ground_color);

		sf::RectangleShape sky(sf::Vector2f(32767, 256));
		sky.setFillColor(sky_color);
		window.draw(sky);

		cvijet.update(delta_time);
		cvijet.draw();
		window.display();
	}

	return 0;
}
