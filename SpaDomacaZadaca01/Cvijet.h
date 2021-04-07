#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::CircleShape krug;
	float brzina = 7;
	float brzina2 = -4;
	float elipsaX;
	float elipsa2X;
	float elipsa3X;
	float elipsa4X;
	float elipsa5X;
	float elipsa6X;
	float elipsa7X;
	float listR;
	float list2R;
	float r;
	float x;
	//sf::Time dt;
	//sf::RenderWindow window;

public:
	Cvijet(); //sf::RenderWindow& window
	void draw(sf::RenderWindow& window, sf::Time& dt);
};

