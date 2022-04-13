#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow& window);
	void Draw(RenderWindow& window);
	void Animate(Clock& clock);
private:
	CircleShape glavaCvijeta, eye1, eye2;
	RectangleShape tijeloCvijeta, mouth;
	ConvexShape list1, list2;
};

