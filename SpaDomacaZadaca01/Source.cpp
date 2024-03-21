#include <SFML/Graphics.hpp>
#include "Scene.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(Scene::WINDOW_WIDTH, Scene::WINDOW_HEIGHT), "Hello, SFML world!");
	window.setFramerateLimit(60);
	Scene scene(&window);

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time deltaTime = clock.restart();
		scene.update(deltaTime);
		scene.draw();
	}

	return 0;
}
