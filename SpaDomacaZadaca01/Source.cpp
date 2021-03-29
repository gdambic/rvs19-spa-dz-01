#include <iostream>
#include <SFML/Graphics.hpp>
#include "Nature.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "NATURE - Tomislav Kescec");
	window.setFramerateLimit(60);
	
	Nature nature(&window);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		nature.render();
		window.display();
	}

	return 0;
}