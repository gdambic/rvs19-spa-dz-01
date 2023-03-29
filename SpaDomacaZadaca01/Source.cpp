#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Character.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	

	//Character person(window.getSize().x / 2, window.getSize().y / 2);

	bool grow = true;
	float radius = 40;
	float speed = 0.2;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			/*if (event.type == sf::Event::KeyPressed)
				person.processEvents(event.key.code, true);

			if (event.type == sf::Event::KeyReleased)
				person.processEvents(event.key.code, false);*/

		}

		if (grow) {
			radius += speed;
			if (radius >= 52)
				grow = false;
		}
		else {
			radius -= speed;
			if (radius <= 40)
				grow = true;
		}

		window.clear(sf::Color::Cyan);
		cvijet.draw(radius);
		//person.update();
		//person.drawTo(window);
		window.display();
	}

	return 0;
}