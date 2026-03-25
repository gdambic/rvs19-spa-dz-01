#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);

	sf::CircleShape sun(20);
	sun.setFillColor(sf::Color::Yellow);
	sun.setPosition(50, 50);

	Cvijet c1(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		c1.draw();
		window.display();
	}

	return 0;
}