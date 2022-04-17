#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
private:
	CircleShape glavaCvijeta;
	RectangleShape tijeloCvijeta;
	
public:
	Cvijet(RenderWindow& window);
	void draw(RenderWindow& window);
	

};

