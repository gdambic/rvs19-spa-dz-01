#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	int x_res = 150; //800
	int y_res = 300; //600
	int framerate = 60;
	auto frameDelay = sf::milliseconds(100 / framerate);

	sf::RenderWindow window(sf::VideoMode(x_res, y_res), "Hello, bees!");
	window.setFramerateLimit(framerate);
	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw((float)x_res / 2, (float)y_res / 2);
		window.display();
		sf::sleep(frameDelay);
		window.clear();
	}

	return 0;
}