#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	sf::RenderWindow* m_window;
	sf::Clock m_timer;

	Cvijet(sf::RenderWindow* window)
	{
		m_window = window;
		m_timer.restart();
	}

	void draw();
};