#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"
#include "Elipsa.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	/*sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("vjetar.wav"))
	{
		std::cout << "Greska s audiom!";
		return 1;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();*/
	
	float brzina = 7.0f;

	sf::Clock clock;

	Cvijet cvijet;

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Time dt = clock.restart();

		//window.clear();
		float krug = 400;
		cvijet.draw(window, dt); 

		window.display();
	}

	return 0;
}