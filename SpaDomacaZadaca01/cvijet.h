#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Cvijet {

public:
	Cvijet(sf::RenderWindow *window);
	void draw();

	sf::CircleShape shape;
	sf::CircleShape shape_one;
	sf::CircleShape shape_two;
	sf::CircleShape line;
	sf::CircleShape circle;
	sf::CircleShape circle_1;
	sf::CircleShape circle_2;
	sf::CircleShape circle_3;
	sf::CircleShape circle_4;


private:
	sf::RenderWindow *window;
	sf::Clock frameClock;
};

