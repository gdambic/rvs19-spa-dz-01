#include<SFML/Graphics.hpp>
#include"Cvijet.h"
#include<iostream>
#include<SFML/System/clock.hpp>
#include<SFML/Audio.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Cvijet", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	Cvijet cvijet(&window);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		sf::Time vrijeme = clock.getElapsedTime();

		cvijet.draw(&vrijeme);

		window.display();

		if (event.type == sf::Event::MouseMoved)
		{
			if (event.mouseMove.x <= 200)
			{
				return 0;
				exit(0);
			}
		}
	}

	return 0;
}