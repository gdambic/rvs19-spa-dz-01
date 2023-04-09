#include <SFML/Graphics.hpp>
#include "Cvijet.h"
int main()
{
	// Anti-Aliasing optional
	//	sf::ContextSettings settings;
	//settings.antialiasingLevel = 8;
	//sf::RenderWindow window(sf::VideoMode(800, 600), "Happy flower and clouds", sf::Style::Default, settings);
	sf::RenderWindow window(sf::VideoMode(800, 600), "Happy flower and clouds");
	window.setFramerateLimit(60);
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