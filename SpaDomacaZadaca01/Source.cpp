#include <SFML/Graphics.hpp>
#include "Flower.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Flower!");
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

		sf::Color backgroundColor = sf::Color(173, 216, 230);

		window.clear(backgroundColor);
		flower.draw();
		window.display();

	}

	return 0;
}