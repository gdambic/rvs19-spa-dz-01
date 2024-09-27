#include <SFML/Graphics.hpp>
#include "Cvijet.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Evo moj cvjetko! :)");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
		
		window.clear(Color(25, 189, 255));
		cvijet.draw();
		window.display();
	}

	return 0;
}