#include "Cvijet.h"
#include <iostream>
using namespace std;

Cvijet::Cvijet(sf::RenderWindow* prozor)
{
	window=prozor;
}


void Cvijet::draw()
{

	//latice 1
	sf::CircleShape triangle(90.f, 3);
	sf::CircleShape triangle1(90.f, 3);
	triangle.setPosition(64, 64);
	triangle1.setPosition(240, 240);
	triangle1.setRotation(180.f);
	triangle.setFillColor(sf::Color(255, 0, 0));
	triangle1.setFillColor(sf::Color(255, 0, 0));
	triangle.setOutlineColor(sf::Color(0, 0, 0));
	triangle1.setOutlineColor(sf::Color(0, 0, 0));
	triangle.setOutlineThickness(1);
	triangle1.setOutlineThickness(1);

	//latice 2
	sf::CircleShape trianglef(90.f, 3);
	sf::CircleShape trianglef1(90.f, 3);
	trianglef.setPosition(120, 30);
	trianglef1.setPosition(183, 280);
	trianglef.setRotation(30);
	trianglef1.setRotation(210.f);
	trianglef.setFillColor(sf::Color(255, 0, 0));
	trianglef1.setFillColor(sf::Color(255, 0, 0));
	trianglef.setOutlineColor(sf::Color(0, 0, 0));
	trianglef1.setOutlineColor(sf::Color(0, 0, 0));
	trianglef.setOutlineThickness(1);
	trianglef1.setOutlineThickness(1);


	//krug
	sf::CircleShape krug(50.f);
	krug.setFillColor(sf::Color(255, 255, 0));
	krug.setPosition(102, 102);

	//crta
	sf::RectangleShape line(sf::Vector2f(300.f, 10.f));
	line.setPosition(155, 125);
	line.rotate(90.f);
	line.setFillColor(sf::Color(0, 255, 0));
	line.setOutlineColor(sf::Color(0, 0, 0));
	line.setOutlineThickness(1);

	//tlo
	sf::RectangleShape tlo(sf::Vector2f(3000.f, 700.f));
	tlo.setPosition(0, 400);
	tlo.setFillColor(sf::Color(150, 50, 0));
	tlo.setOutlineColor(sf::Color(150, 255, 0));
	tlo.setOutlineThickness(10);

	//nebo
	sf::RectangleShape nebo(sf::Vector2f(7000.f, 7000.f));
	nebo.setPosition(0, 0);
	nebo.setFillColor(sf::Color(0, 5, 255));


	//list

	sf::ConvexShape list;
	list.setPointCount(4);

	list.setPoint(0, sf::Vector2f(125.f, 430.f));
	list.setPoint(1, sf::Vector2f(250.f, 250.f));
	list.setPoint(2, sf::Vector2f(225.f, 330.f));
	list.setPoint(3, sf::Vector2f(125.f, 430.f));
	list.setFillColor(sf::Color(0, 255, 0));

	list.setOutlineColor(sf::Color(0, 0, 0));
	list.setOutlineThickness(1);

	

	window->draw(nebo);
	window->draw(list);
	window->draw(line);
	window->draw(tlo);	
	window->draw(triangle);
	window->draw(triangle1);
	window->draw(trianglef);
	window->draw(trianglef1);
	window->draw(krug);

}


