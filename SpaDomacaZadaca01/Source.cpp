#include <SFML/Graphics.hpp>
#include "cvijet.h";

int main()
{
	sf::Clock animacija;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Moj cvijetak!");
	window.setFramerateLimit(60);
	cvijet cvijet(&window);

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
		cvijet.crtaj(&animacija);
		window.display();
		
		}

	return 0;
}