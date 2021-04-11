#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Mrtva priroda");
	window.setFramerateLimit(60);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.f, 768.f));
	window.setView(view);
	Cvijet cvijet(&window);


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


		window.display();
	}

	return 0;
}