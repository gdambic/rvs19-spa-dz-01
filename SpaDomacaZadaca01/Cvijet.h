#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Sunce.h"
#include "Pozadina.h"
using namespace std;
class Cvijet
{
private:
	sf::RenderWindow* window; 
	Sunce sunce;
	Pozadina pozadina;
	sf::CircleShape circle;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void animate(float deltaTime);
};

