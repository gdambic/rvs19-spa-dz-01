#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Welcome to Bruno's world");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	

	// run the program as long as the window is open
	while (window.isOpen())
	{
		sf::Event event;
		// check all the window's events that were triggered since the last iteration of the loop
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}