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

	/*CircleShape sun(30);
	sun.setFillColor(Color(255, 255, 0));
	sun.setPosition(0, 0);
	float xVelocity = 3;*/

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();

		/*if (sun.getPosition().x <= window.getSize().x)
		{
			float sunPos = sun.getPosition().x + xVelocity;
			sun.setPosition(sunPos, 0);
			window.draw(sun);
		}
		else
		{
			sun.setPosition(0, 0);
		}*/

		cvijet.draw();
		window.display();


	}

	return 0;
}