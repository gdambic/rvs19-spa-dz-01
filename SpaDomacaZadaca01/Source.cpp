#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);

	Cvijet cvijet(&window);
	Cvijet::Bee bee(&window);

	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Presley.ttf")) {
		std::cout << "Greska kod ucitavanja fonta!" << std::endl;
		return 404;
	}

	text.setString("Pollinate any flower!\nUse arrow keys.");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setPosition(300, 200);
	text.setFillColor(sf::Color::Blue);

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

			if (event.type == sf::Event::KeyPressed)
				bee.processEvents(event.key.code, true);

			if (event.type == sf::Event::KeyReleased)
				bee.processEvents(event.key.code, false);
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
		bee.update();
		bee.draw();
		window.draw(text);
		window.display();
	}

	return 0;
}