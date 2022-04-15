#include <SFML/Graphics.hpp>
#include "Flower.h"
int main()
{
	// Let's add some antialiasing
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	

	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!",sf::Style::Default, settings);
	window.setFramerateLimit(60);
	Flower flower(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		flower.draw();
		window.display();
	}


	return 0;
}

