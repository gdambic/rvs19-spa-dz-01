#include <SFML/Graphics.hpp>
#include "Cvijet.h"

#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	sf::Clock clock;
	Cvijet cvijet(&window, clock);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		//std::cout << clock.getElapsedTime().asSeconds() << std::endl; 

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}