#include <SFML/Graphics.hpp>
#include "Cvijet.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window); // konstruktor

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