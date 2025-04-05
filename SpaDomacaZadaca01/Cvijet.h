#pragma once
#include <SFML/Graphics.hpp>


class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape flower;
	sf::Clock clock;
	sf::CircleShape petal1;
	sf::CircleShape petal2;
	sf::CircleShape petal3;
	sf::CircleShape petal4;
	sf::RectangleShape peteljka;
	sf::ConvexShape list;
	bool boja;

	sf::CircleShape flower2;
	sf::CircleShape petal10;
	sf::CircleShape petal20;
	sf::CircleShape petal30;
	sf::CircleShape petal40;
	sf::CircleShape petal11;
	sf::CircleShape petal22;
	sf::CircleShape petal33;
	sf::CircleShape petal44;

	sf::RectangleShape peteljka2;
	sf::ConvexShape list2;

	sf::CircleShape sunce;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

