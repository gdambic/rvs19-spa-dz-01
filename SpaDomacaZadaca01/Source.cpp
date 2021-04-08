#include <SFML/Graphics.hpp>
#include"Cvijet.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijetak!",sf::Style::Default, settings);
	window.setFramerateLimit(60);
	Cvijet cvijet(window);
	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
	
		window.clear(sf::Color(128,206,237));
		cvijet.draw();
		window.display();
	}
	
	return 0;
}