#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <ctime>

sf::Color COLORS[] = { sf::Color(200,150,250), sf::Color(150,200,250), sf::Color(250,180,200), sf::Color(180,250,200) };

sf::Color rnd_color() {
	return COLORS[rand() % 4];
}

int main()
{
	srand(time(nullptr));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);

	Cvijet cvijet(&window, rnd_color(), sf::Vector2f(380.f, 260.f), 12.5, 6);


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
	}

	return 0;
}