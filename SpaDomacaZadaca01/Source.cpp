#include<SFML/Graphics.hpp>
#include"Cvijet.h"
#include<iostream>
#include<SFML/System/clock.hpp>

int main()
{
	std::cout << std::endl << "Animacija by Martin Majeric" << std::endl;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet");
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
	}

	return 0;
}