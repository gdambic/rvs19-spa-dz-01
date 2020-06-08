#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Don't click please!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	sf::Vector2u prozorDim = window.getSize();

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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window.setTitle("You had to :'(");
		}
		window.display();
	}

	return 0;
}