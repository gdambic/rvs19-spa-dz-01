#include<iostream>
#include"Cvijet.h"
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

using namespace sf; // include za izbjegavanje sf::

int main()
{
	RenderWindow window(VideoMode(800, 600), "Hello, SFML world!"); 
	window.setFramerateLimit(60);
	Cvijet cvijet(&window); // kreiranje objekta Cvijet

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw(); // iscrtavanje
		window.display();
	}

	return 0;
}