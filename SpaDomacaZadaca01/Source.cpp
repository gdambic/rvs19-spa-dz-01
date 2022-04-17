#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 400), "SFML Lovro Pavlov");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;

		window.clear(sf::Color::Color(50,50,50));

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::MouseMoved)
				window.clear(sf::Color::Magenta);
		}

		cvijet.draw();
		window.display();
	}

	return 0;
}