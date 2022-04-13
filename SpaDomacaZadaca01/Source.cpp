#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	
	sf::Clock clock;
	sf::Color color;
	float elapsedTimef = float();
	int r = 255;
	int b = 0;

	while (window.isOpen())
	{
		sf::Event event;
		sf::Time elapsed = clock.restart();
		elapsedTimef += elapsed.asSeconds();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		cvijet.draw();

		sf::CircleShape sun;
		sun.setRadius(30.f);
		sun.setFillColor(sf::Color(250, 250, 0));
		sun.setPointCount(100);
		sun.setPosition(30, 30);

		color = sf::Color::Red;
		sun.setFillColor(color);

		//DIDN'T MANAGE TO MAKE IT AN INFINITE LOOP :/
		if (elapsedTimef > 0.01f && sun.getFillColor() == sf::Color::Red)
		{
			r -= 1;
			b += 1;
			if (r>0)
			{
				elapsedTimef = 0;
				color = sf::Color(r, 0, b);
				sun.setFillColor(color);
			}
		}

		window.draw(sun);

		window.display();
	}

	return 0;
}