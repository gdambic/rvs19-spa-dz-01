#include <SFML/Graphics.hpp>
#include "Flower.h"
#include "iostream"
using namespace std;

int main()
{

	
    Flower f;

    f.menu(); 



	//create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Procedural Flower Generator");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		f.draw(window); // Draw the flower
		window.display();
	}

	return 0;
}