#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public: 
	Cvijet(sf::RenderWindow* window);
		void draw(sf::Time frameTime);

private:
	sf::RenderWindow* m_window;
	sf::RectangleShape m_stem;
	sf::CircleShape m_petal;
	sf::CircleShape m_center;
	sf::RectangleShape m_water;
};

