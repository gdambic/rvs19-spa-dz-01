#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet");
	window.setFramerateLimit(60);
	Cvijet cvijet;

	//sf::CircleShape krug(50.f); 

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
		//window.draw(krug);
		window.display();
	}

	return 0;
}