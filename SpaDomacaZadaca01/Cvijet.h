#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Cvijet
{public:
	Cvijet(sf::RenderWindow& window);
	void draw();


private:
	sf::Clock clock;
	sf::ConvexShape list1;
	sf::CircleShape oblik;
	sf::CircleShape kruznica;
	sf::RectangleShape stabljika;
	sf::RenderWindow& window;
};

