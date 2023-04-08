#include <SFML/Graphics.hpp>
#include "Cvijet.h"

using namespace sf;

int main()
{

	RenderWindow window(VideoMode(800, 600), "Peach three flower");
	window.setFramerateLimit(60);
	Cvijet cvijet(window);

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
		window.display();

	}

	return 0;
}