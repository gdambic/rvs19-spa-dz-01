#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cvijet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 720), "Hello, SFML world!");
	window.setFramerateLimit(60);

	//sf::SoundBuffer buffer;
	//if (!buffer.loadFromFile("ES_Birds.wav")) {
	//	return -1; // error
	//}

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