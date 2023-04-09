#include <SFML/Graphics.hpp>
#include "SFML/System/Vector2.hpp"

#include<random>
#include <chrono>
#include <thread>

#include<iostream>

#include "Flowie.h"

//sf::

void display_setup_and_loop() {
	//Code does not work for different window sizes. Do not change.
	sf::RenderWindow main_window(sf::VideoMode(800, 600), "And hello, animation!");
	main_window.setFramerateLimit(60);//This works real nice. Do not change.
	sf::Vector2i default_position = main_window.getPosition();

	sf::RenderWindow window_part2(sf::VideoMode(800, 600), "Hello, SFML world!");
	window_part2.setPosition(sf::Vector2i(default_position.x, default_position.y + 30));

	Flowie flowie(sf::Color::Red, main_window);

	sf::Event event;
	
	window_part2.clear();
	flowie.draw(window_part2);
	window_part2.display();

	//The world at my fingertips
	while (window_part2.isOpen() && main_window.isOpen())
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			std::cout << "SPAAAAAAAAAAACE" << std::endl;

		while (window_part2.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				main_window.close();
		}

		while (main_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				main_window.close();
		}

		main_window.clear();
		flowie.draw(main_window);
		flowie.process();
		main_window.display();
	}
}

int main()
{

	display_setup_and_loop();
	

	return 0;
}