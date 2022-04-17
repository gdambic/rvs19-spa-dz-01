#include <SFML/Graphics.hpp>
#include "Cvijet.h";

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "OMG, it's growing so nicely");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
			
		}

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}