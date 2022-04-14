#include <SFML/Graphics.hpp>

#include "Cvijet.h"

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 800;
	const int FPS_LIMIT = 60;
	sf::Color BG_COLOR = sf::Color::Cyan;
	sf::ContextSettings settings;

	settings.antialiasingLevel = 10;

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Matej Ruzic, 1IP1", sf::Style::Default, settings);
	window.setFramerateLimit(FPS_LIMIT);
	Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(BG_COLOR);
		cvijet.draw();
		window.display();
	}

	return 0;
}