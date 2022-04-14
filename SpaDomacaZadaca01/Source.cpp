#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Flower.h"
#include "Weather.h"
#include "Colors.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	colors c;
	Weather weather(&window, &c);
	Flower flower(&window, &c, &weather);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		weather.drawBackGround();
		weather.updateStars();
		weather.updateSun();
		weather.updateRain();
		flower.draw();
		window.display();
	}

	return 0;
}