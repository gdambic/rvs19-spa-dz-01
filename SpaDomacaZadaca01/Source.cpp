#include <SFML/Graphics.hpp>
#include "Flower.h"
#include <iostream>

using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	sf::Clock clock;
	Flower flower(&window, clock);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		flower.draw_flower();
		window.display();
	}

	return 0;
}