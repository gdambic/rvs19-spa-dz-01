#include <SFML/Graphics.hpp>
#include "cvijetic.h"
#include <vector>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijetic cvijetic(window);
	cvijetic.set_ran(false);
	sf::Clock clock;
	//Cvijet cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		cvijetic.anim(clock);
		std::cout << clock.getElapsedTime().asSeconds() << "\n";

		window.clear();

		window.draw(cvijetic.get_stabljika());
		for (int i = 0; i < 5; i++)
		{
			window.draw(cvijetic.get_latice().at(i));
		}
		window.draw(cvijetic.get_list());
		window.draw(cvijetic.get_tucak());
		
		window.display();
	}

	return 0;
}