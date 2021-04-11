#include <iostream>
#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "upis_objekata.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Cvijet <3");
	window.setFramerateLimit(60);

	Cvijet cvijet(&window);

	upis_sunca(cvijet);
	upis_cvijeta(cvijet);

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
		window.display();
	}

	return 0;
}