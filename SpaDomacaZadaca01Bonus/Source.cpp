#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, This is Algebra!");
	window.setFramerateLimit(60);
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
		cvijet.gravity();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			cvijet.move_character('A');
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			cvijet.move_character('D');
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			cvijet.move_character('W');
		}
		cvijet.draw();
		cvijet.draw_character();
		window.display();
	}

	return 0;
}