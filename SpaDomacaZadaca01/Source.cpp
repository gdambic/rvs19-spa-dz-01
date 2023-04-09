#include <SFML/Graphics.hpp>
#include "Cvijet.h"
using namespace sf;

int main()
{
	const int x = 800;
	const int y = 600;
	RenderWindow window(VideoMode(x, y), "SPA DZ - Matija Lukanic 1RP4 :)");
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


		window.clear(Color(152, 214, 250));
		cvijet.draw();
		window.display();
	}

	return 0;
}