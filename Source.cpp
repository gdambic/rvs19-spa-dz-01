#include <SFML/Graphics.hpp>
#include"Cvijet.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	sf::Texture texture;
	texture.loadFromFile("nebo.jpg");
	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 600));
	Cvijet cvijet (&window);

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		cvijet.crtaj();
		window.display();

	}
	return 0;
}