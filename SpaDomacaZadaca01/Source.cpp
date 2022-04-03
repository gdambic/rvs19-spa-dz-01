#include <SFML/Graphics.hpp>
#include "Cvijet.h"

using namespace sf;

int main()
{
	// dodan antialiasing level da ljepse izgleda
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "Hello, SFML world!", Style::Default , settings);
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}