#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	
	for (unsigned i = 0; i < 1; i++)
	{
		cout << "CVIJET by MATEA" << endl << endl;
		cout << "Ukoliko zelite sunce, drzite pritisnutu lijevu tipku (klik) misa :)" << endl;
		system("color 5");

	}
	

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