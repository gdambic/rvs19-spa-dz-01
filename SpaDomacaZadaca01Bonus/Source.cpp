#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"

int main()
{
	// screen resolution
	unsigned int width = 800;
	unsigned int height = 600;
	
	sf::RenderWindow window(sf::VideoMode(width, height), "Hello, This is Algebra!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window, width, height);

	while (window.isOpen())
	{		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				cvijet.move_character('W');
			}
		}
		
		window.clear();
		cvijet.draw();	
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			cvijet.move_character('A');
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			cvijet.move_character('D');
		}
		
		cvijet.draw_character();
		cvijet.gravity();
		window.display();
	}

	return 0;
}