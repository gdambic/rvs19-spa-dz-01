#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"
using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 300), "Hello, SFML world!");
	window.setFramerateLimit(30);
	Cvijet cvijet(&window);

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

		
	}


	return 0;
}