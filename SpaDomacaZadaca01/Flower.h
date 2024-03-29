#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Flower {
private:
	sf::RenderWindow* window;
	sf::CircleShape sun;
	sf::CircleShape center;
	sf::RectangleShape stem;
	sf::ConvexShape leaf;
	sf::RectangleShape ground;
	std::vector<sf::CircleShape> petal;
	sf::CircleShape eyes[2];
	sf::RectangleShape mouth;
	sf::Clock clock[2];
public:
	Flower(sf::RenderWindow* window);
	void draw();
};

