#pragma once
#include <SFML/Graphics.hpp>

class Flower
{
private:
	sf::RenderWindow *m_window;
	sf::Clock m_clock;
	float m_circle_radius;
	bool m_isExpanding;
public:
	Flower(sf::RenderWindow* window);
	void draw();
};

