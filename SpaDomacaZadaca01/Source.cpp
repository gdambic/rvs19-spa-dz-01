#include <SFML/Graphics.hpp>
#include "Flower.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Cvijet", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	//Cvijet cvijet(&window);
	Flower flower(window);
	
	flower.draw();
	//cvijet.draw();
	return 0;
}