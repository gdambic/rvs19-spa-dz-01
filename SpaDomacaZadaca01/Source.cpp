#include <SFML/Graphics.hpp>
#include"Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	sf::CircleShape circ;
	sf::Vector2f circlepos(0, 0);
	circ.setPosition(circlepos);
	circ.setRadius(50);

	float xv = 3;
	float yv = 3;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		
		bool hitCorner = false;
		if (circlepos.x < 0 || circlepos.x > 800 - 100)
		{
			xv *= -1; 
			hitCorner = true; 
		}

		
		if (circlepos.y < 0 || circlepos.y > 600 - 100)
		{
			yv *= -1; 
			hitCorner = true; 
		}

		
		if (hitCorner)
		{
			int r = rand() % 256;
			int g = rand() % 256;
			int b = rand() % 256;
			circ.setFillColor(sf::Color(r, g, b));
		}

		circlepos.x += xv;
		circlepos.y += yv;
		circ.setPosition(circlepos);

		window.clear();
		cvijet.draw();
		window.draw(circ);
		window.display();
	}

	return 0;
}