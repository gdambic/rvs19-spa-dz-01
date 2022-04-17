#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Cvijet
{
public:
	Cvijet(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
private:
	sf::CircleShape krug;
	sf::CircleShape sunce;
	sf::CircleShape krug2;
	sf::RectangleShape stabiljka;
};

