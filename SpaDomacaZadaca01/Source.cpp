#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"
using namespace std;
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Clock clock;
	Cvijet cvijet(&window);

	Cvijet cvijet1(&window);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		sf::Time dt = clock.restart();

		cvijet1.drawCvijet();
		cvijet1.drawTriangle();
		cvijet1.drawText("Marlboro.ttf");
		window.display();
	}

	return 0;
}