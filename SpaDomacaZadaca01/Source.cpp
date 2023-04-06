#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"
using namespace std;

int main()
{
	int fps = 0;
	cout << "Insert number of frames per second." << endl << "This will affect the speed of the animation (0 = limitless; higher = faster)!" << endl << "> ";
	cin >> fps;
	ContextSettings settings;
	settings.antialiasingLevel = 8; // Added antialiasing
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!", Style::Default, settings); // Changed to add in AA
	window.setFramerateLimit(fps); // Suggestion: increase to higher frames per second (or zero) for faster animations
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