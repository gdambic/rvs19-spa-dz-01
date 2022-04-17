#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include<SFML/Window.hpp> // library za window
#include<SFML/System.hpp> // sistemski SFML library
using namespace sf;

int main()
{
	
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "Cvijet SPA", Style::Default, settings);
	window.setFramerateLimit(60);
	Cvijet cvijet(window);
	Clock clock, clock2, clock3;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw(window);
		cvijet.animacija(clock, clock2, clock3);
		window.display();
	}

	return 0;
}