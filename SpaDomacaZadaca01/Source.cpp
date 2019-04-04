#include "Cvijet.h"
#include <Windows.h>
#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include "Goran.h"
#include <SFML/Audio.hpp>


using namespace std;



void draw_Background(sf::RenderWindow *window);


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);
	Goran goran(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		draw_Background(&window);
		cvijet.draw();
		cvijet.move();
		goran.spawn();
		window.display();
	}
	return 0;
}

void draw_Background(sf::RenderWindow *window) {

	sf::Texture texture;

	if (!texture.loadFromFile("minecraft1.png"))
	{
		throw exception("Error opening file image [func draw_Background]");
	}

	sf::Sprite background(texture);
	window->draw(background);
}