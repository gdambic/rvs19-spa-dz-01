#include <SFML/Graphics.hpp>
#include "Cvijet.h"
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet Cvijet(&window);


	CircleShape sun(10.f);
	sun.setFillColor(sf::Color::Yellow);
	sun.setOrigin(sun.getRadius(), sun.getRadius());
	sun.setPosition(60, 40);

	double max_radius = 20.f;
	double min_radius = 15.f;
	double radius_step = 0.9f;
	double current_radius = min_radius;
	bool animate = true;

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		if (animate)
		{
			current_radius += radius_step;
			if (current_radius >= max_radius)
			{
				current_radius = max_radius;
				animate = false;
			}
		}
		else
		{
			current_radius -= radius_step;
			if (current_radius <= min_radius)
			{
				current_radius = min_radius;
				animate = true;
			}
		}

		sun.setRadius(current_radius);
		sun.setOrigin(current_radius, current_radius);

		

		window.clear();
		Cvijet.draw();
		window.draw(sun);
		window.display();
	}

	return 0;
}