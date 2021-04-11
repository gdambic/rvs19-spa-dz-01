#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Cvijet
{
public:
	Cvijet(sf::RenderWindow& window);
	void draw();


private:
	sf::Clock clock;
	sf::ConvexShape list1;
	sf::CircleShape sunce;
	sf::CircleShape glava;
	sf::CircleShape glava1;
	sf::RectangleShape stabljika;
	sf::RectangleShape pod;
	sf::RenderWindow& window;
};

