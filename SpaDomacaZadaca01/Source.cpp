#include <SFML/Graphics.hpp>
#include "Cvijet.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "mauroh - Domaca Zadaca");
	window.setFramerateLimit(30);
	Cvijet cvijet(&window); //!

	//ovo je samo napravljeno za ukras!!!
	sf::Image icon;
	if (icon.loadFromFile("../images/mh.png")) 
	{ 
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}
	//

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Blue);
		cvijet.draw_flower(); //!
		window.display();
	}

	return 0;
}