#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"
using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Ustrašeni cvijet");
	window.setFramerateLimit(60);
	Cvijet cvijet(window);
	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.Animate(clock);
		cvijet.Draw(window);
		window.display();
	}

	return 0;
}