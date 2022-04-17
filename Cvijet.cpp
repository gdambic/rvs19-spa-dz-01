#include "cvijet.h"

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
void Cvijet::drawCircle(float radius, float position1, float position2, int R, int G, int B, float outline, int outR, int outG, int outB)
{
	sf::CircleShape circle(radius);
	circle.setPosition(position1, position2);
	circle.setFillColor(sf::Color(R, G, B));
	circle.setOutlineThickness(outline);
	circle.setOutlineColor(sf::Color(outR, outG, outB));
	adresaProzora->draw(circle);
}


void Cvijet::drawRectangle(float dimension1, float dimension2, float position1, float position2, int R, int G, int B)
{
	sf::RectangleShape line(sf::Vector2f(dimension1, dimension2));
	line.setFillColor(sf::Color(R, G, B));
	line.setPosition(position1, position2);
	line.rotate(90.f);
	adresaProzora->draw(line);
}

void Cvijet::drawLeaf(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, int R, int G, int B)
{
	sf::ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(x0, y0));
	leaf.setPoint(1, sf::Vector2f(x1, y1));
	leaf.setPoint(2, sf::Vector2f(x2, y2));
	leaf.setPoint(3, sf::Vector2f(x3, y3));
	leaf.setFillColor(sf::Color(R, G, B));
	adresaProzora->draw(leaf);
}



Cvijet::Cvijet(sf::RenderWindow* adresaProzora)
{
	this->adresaProzora = adresaProzora;
}

void Cvijet::draw()
{
	drawRectangle(250.f, 5.f, 400.f, 260.f, 100, 250, 50);
	drawCircle(30.f, 365.f, 150.f, 255, 255, 0, 50.f, 255, 0, 0);
	drawLeaf(195.f, 270.f, 300.f, 260.f, 400.f, 300.f, 295.f, 305.f, 100, 250, 50);
}

