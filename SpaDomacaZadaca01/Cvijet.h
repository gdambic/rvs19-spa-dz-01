#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
	private:
		sf::RenderWindow *window;
		sf::Clock clock;

		int WIDTH, HEIGHT;

	public:
		Cvijet(sf::RenderWindow *window, int WIDTH, int HEIGHT);
		void draw();
};

