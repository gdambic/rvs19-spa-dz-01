#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Domagoj Sliepcevic SPA DZ1!");
	window.setFramerateLimit(60);
	sf::Texture flowerTexture;
	flowerTexture.loadFromFile("flower.png");
	Cvijet cvijet(window,&flowerTexture, sf::Vector2u(9, 1), 0.13f);
	float deltaTime = 0.0f;
	sf::Clock clock;


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		cvijet.update(0, deltaTime);
		cvijet.draw(window);
		window.display();
	}

	return 0;
}