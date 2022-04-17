#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Cvijet.h"


//argc = argument count argv = argument values
int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pseudocvjetic Sare Poric");
	window.setFramerateLimit(60);

	Cvijet cvijet(sf::Color::Red, 10, 80, 80); //konstruktor cvijet prima boju, broj latica, radijus cvijeta i radijus latica
	cvijet.setPosition(sf::Vector2f(400, 300));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(cvijet);
		window.display();
	}

	return 0;
}