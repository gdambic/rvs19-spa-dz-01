#include <SFML/Graphics.hpp>
#include "Flower.h"

int main()
{

	//create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Procedural Flower Generator");
	window.setFramerateLimit(60);

	
	Flower flower; 




	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		window.clear();
		flower.draw(window); // Draw the flower
		window.display();
	
	}

	return 0;
}