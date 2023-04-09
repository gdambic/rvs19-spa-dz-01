#include <SFML/Graphics.hpp>
#include "Cvijet.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	sf::Clock frameClock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time frameTime = frameClock.restart();

		window.clear();
		cvijet.draw(frameTime);
		window.display();
	}

	return 0;
}