#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::Clock clock;
	sf::Time prevTime = clock.getElapsedTime();
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Pozdrav, Profesore!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.getElapsedTime() - prevTime;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw(elapsedTime);
		window.display();
	}

	return 0;
}