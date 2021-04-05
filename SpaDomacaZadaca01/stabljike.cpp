#include "stabljike.h"
#include<iostream>
void stabljike::crtaj(int duljina, int x, int y, sf::RenderWindow& window)
{
	
	
	
}

void stabljike::inicializiraj(int duzina, int debljina, sf::RenderWindow& window, int x0,int y0,int a0, int b0)
{

	sf::RectangleShape line(sf::Vector2f(duzina-(duzina<300)*10-(duzina<200)*10-5, debljina));
	line.rotate(90);
	line.setFillColor(sf::Color::Yellow);	
	sf::Transform transform;
	
	if ((600 - b0) > y0)
		y0 = 600 - b0;

	line.setPosition(sf::Vector2f(x0,y0));
	window.draw(line, transform);
	
}

sf::RectangleShape stabljike::dajLiniju()
{
	return line;
}


