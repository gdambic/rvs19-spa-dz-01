#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window; 
	sf::CircleShape circle;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

