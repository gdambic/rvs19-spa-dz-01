#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window); //stvara objekt klase cvijet koji prima window kao argument

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		cvijet.draw(); //poziv funkcije ce nacrtati cvijet na window koristeci objekt klase cvijet
		window.display();
	}

	return 0;
}