#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Cvijetovi.h"
#include <iostream>
#include <vector>
int main()	
{
	srand((unsigned)time(0));
	srand(rand());
	const int FPS = 60;
	const int WIDTH = 800;
	const int HEIGHT = 600;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Cvijet - by vanjavk", sf::Style::Default, settings);
	window.setFramerateLimit(FPS);
	Cvijetovi cvijetovi = Cvijetovi(&window);
	//cvijetovi.push_back(Cvijet(window));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// check the type of the event...
			switch (event.type)
			{
				// window closed
			case sf::Event::Closed:
				window.close();
				break;

				// key pressed
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space) {


				}
				else if (event.key.code == sf::Keyboard::A) {
					
				}
				break;

				// we don't process other types of events
			default:
				break;
			}
		}

		window.clear();



		cvijetovi.draw();
		window.display();
	}

	return 0;
}



//i = 0;
//std::cout << FPS / 60.0 * 1000000;
//while (clock.getElapsedTime().asMicroseconds() < 1.0 / FPS * 1000000) {
//	i++;
//}
//std::cout << i << std::endl;
//clock.restart();