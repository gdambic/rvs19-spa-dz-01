#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Unos.h"

int main()
{
	Unos widthHeight; // ne idu zagrade ovdje!!!!
	int width = widthHeight.getWidth();
	int height = widthHeight.getHeight();

	sf::RenderWindow window(sf::VideoMode(width, height), "Cvijet");
	window.setFramerateLimit(60);

	Cvijet cvijet(&window); // inicjalizira cvijet. input je adresa windowa. 
	cvijet.setAnimation(&window); // inicijalizira animaciju sunca

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.updateFlower(&window); // updejta cvijet
		cvijet.draw(&window); // animira sunce

		window.display();
	}

	return 0;
}