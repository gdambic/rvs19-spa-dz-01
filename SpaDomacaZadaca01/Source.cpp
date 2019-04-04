#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	sf::CircleShape circle(20.f);
	circle.setFillColor(sf::Color(250, 50, 250));

	circle.setOutlineThickness(50.f);
	circle.setOutlineColor(sf::Color(150, 50, 250));
	circle.setPosition(200, 100);

	sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
	line.rotate(90.f);
	line.setPosition(225, 190);
	line.setFillColor(sf::Color(100, 250, 50));

	sf::CircleShape circle2(20.f);
	circle2.setFillColor(sf::Color(700, 450, 400));
	circle2.setPosition(75, 50);

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		circle2.rotate(2);

		window.clear();
		cvijet.draw();
		window.draw(circle);
		window.draw(line);
		window.draw(circle2);
		window.display();
	}
	

	

	return 0;
}