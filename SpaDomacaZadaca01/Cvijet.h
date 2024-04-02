#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	int seed;
	int flower_position;
	sf::RenderWindow *window;
	sf::ConvexShape ground;
	sf::RectangleShape stem;
	sf::CircleShape flower_center;
	sf::CircleShape flower1;
	sf::CircleShape flower2;
	sf::CircleShape flower3;
	sf::CircleShape flower4;
	sf::ConvexShape leaf1;
	sf::ConvexShape leaf2;
	sf::CircleShape sun;
	sf::CircleShape sun_effect;
	sf::Clock clock;
	void drawGround();
	void drawStem();
	void drawFlower();
	void drawLeaf();
	void drawSun();
	void sunAnimation();

public:
	Cvijet(sf::RenderWindow *window);
	void draw();
	void setSeed(int seed);

};

