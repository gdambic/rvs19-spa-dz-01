#include <SFML/Graphics.hpp>
#include "Flower.h"

using namespace sf;

int main() 
{
	RenderWindow window(VideoMode(800, 600), "Flower");
	window.setFramerateLimit(60);

	Flower flower(&window);

	while (window.isOpen()) 
	{
		Event event;

		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();

		window.clear();
		flower.draw();
		window.display();
	}

	return 0;
}