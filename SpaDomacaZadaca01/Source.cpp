#include <SFML/Graphics.hpp>
#include "Cvijet.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "");
	window.setFramerateLimit(30);
	Cvijet cvijet(&window);
	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);

		cvijet.draw_flower();

		window.display();

	}
	return 0;

}