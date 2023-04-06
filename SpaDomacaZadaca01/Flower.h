#pragma once
#include <SFML/Graphics.hpp>
class Flower
{

private:
	sf::RenderWindow* window;
	sf::CircleShape Moon;
	sf::CircleShape FlowerHead;
	sf::ConvexShape Stem;
	sf::ConvexShape Leaf;
	sf::Clock frameClock;
	sf::CircleShape Octagon;
	float constant;


public:

	Flower(sf::RenderWindow* window);
	void draw();
	sf::CircleShape get_Moon() const;
	void set_Moon(const sf::CircleShape Moon);
	sf::CircleShape get_FlowerHead() const;
	void set_FlowerHead(const sf::CircleShape FlowerHead);
	sf::ConvexShape get_Stem() const;
	void set_Stem(const sf::ConvexShape Stem);
	sf::ConvexShape get_Leaf() const;
	void set_Leaf(const sf::ConvexShape Leaf);
	//getter
	float get_const() const;
	//setter
	void set_const();
	sf::CircleShape get_Octagon() const;
	void set_Octagon(const sf::CircleShape Octagon);




};

