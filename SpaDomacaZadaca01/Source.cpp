#include <SFML/Graphics.hpp>
#include<vector>
#include<iostream>
#include"Cvijet.h"
#include"Kisa.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	Kisa kapljice[174];

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		cvijet.draw();
		for (int i = 0; i < 174; i++)
		{
			kapljice[i].pada();
			window.draw(kapljice[i]);
		}
		window.display();
	}

	return 0;
}
