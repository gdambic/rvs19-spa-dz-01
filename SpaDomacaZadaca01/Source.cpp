#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include<iostream>
using namespace std;



int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "No, I am your flower ;)");
	window.setFramerateLimit(60);
	Cvijet Cvijet(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		Cvijet.draw();
		window.display();
			
		}
		
	}

	return 0;
}