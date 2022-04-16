#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;

class Nebo
{
public:

	Nebo(sf::RenderWindow* window);

	void draw();

	sf::RectangleShape get_nebo()const;
	void set_nebo(const sf::RectangleShape nebo);

	sf::CircleShape get_Sunce() const;
	void set_Sunce(const sf::CircleShape sunce);

	int gen_randNum();

private:

	sf::RectangleShape nebo;
	sf::CircleShape sunce;
	sf::RenderWindow* window;

};

