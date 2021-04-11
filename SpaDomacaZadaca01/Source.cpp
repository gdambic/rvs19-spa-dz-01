#include <SFML/Graphics.hpp>
#include"Cvijet.h"
#include<random>


int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;


	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijetic", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	

	

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{

			sf::CircleShape shape(50.f);

			shape.setFillColor(sf::Color(100, 250, 50));



			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();
		window.display();
	}

	return 0;
}