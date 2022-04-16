#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <sstream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	sf::Clock clock;
	float lastTime = 0;

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color(100, 250, 50));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();
		window.display();

		float currentTime = clock.restart().asSeconds();
		float fps = 1.f / (currentTime);
		lastTime = currentTime;

		std::stringstream ss;
		ss << fps;
		window.setTitle(ss.str());		

	}
	return 0;
}