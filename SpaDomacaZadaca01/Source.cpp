#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <iostream>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Clock frameClock;
		while(window.isOpen()){

			window.clear();
			cvijet.draw(frameClock);
			window.display();
		
		}
	}

	return 0;
}