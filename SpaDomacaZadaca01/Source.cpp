#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Sunce.h"

int main()
{
	//INICIJALIZIRAJ PROZOR
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML - Iscrtavanje cijeta!");
	window.setFramerateLimit(60);
	
	//INICIJALIZIRAJ OBJEKTA
	Cvijet cvijet(&window);
	Sunce sunce(&window, 20.f);

	//GLAVNA PETLJA
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		//NACRTAJ OBJEKTE
		cvijet.draw();
		sunce.draw();

		window.display();
	}

	return 0;
}