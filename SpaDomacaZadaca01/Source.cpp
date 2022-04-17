#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(window);
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear();
		cvijet.draw(window);
		window.display();
	}
	

	return 0;
}