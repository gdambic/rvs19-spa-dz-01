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
	sf::RenderWindow main_window(sf::VideoMode(800, 600),
		"Hello, game dev! [WASD, Basic dodge the creeps game. Space to reset.]");
	main_window.setFramerateLimit(60);//This works real nice. Do not change.

	Flowie flowie(sf::Color::Red, main_window);

	sf::Event event;

	//The world at my fingertips
	while (main_window.isOpen())
	{
		while (main_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				main_window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			flowie.RPM_UP();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			flowie.RPM_DOWN();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			flowie.rotate_left();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			flowie.rotate_right();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			flowie.reset(main_window);

		main_window.clear();
		flowie.draw(main_window);
		flowie.process(main_window);
		main_window.display();
	}
}

int main()
{

	display_setup_and_loop();
	

	return 0;
}