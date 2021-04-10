#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <iostream>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet");
	window.setFramerateLimit(60);
	cvijet cvijet(&window);
	sf::Clock vrijeme;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		cvijet.draw();

		cvijet.update(&vrijeme);

		window.display();
	}
	
	return 0;
}