#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace std;

Cvijet::Cvijet(int x,int y,double e,sf::Texture &lopta) : texture(lopta) //za crtanje loptica
{
	setPos(x, y);
	setElasticity(e);
}

Cvijet::Cvijet(sf::RenderWindow& window,sf::Texture& lopta) : texture(lopta)	//za crtanje cvijeta
{
	draw(window);
}

Cvijet& Cvijet::operator=(const Cvijet& source) { //"copy construktor" - sluzi kad vektor pomice objekte po vektoru radi brisanja kuglica koje miruju.
	if (this == &source) {
		return *this;
	}

	this->x = source.x;
	this->y = source.y;
	this->dy = source.dy;
	this->gravity = source.gravity;
	this->elasticity = source.elasticity;
	this->unistiti = source.unistiti;

}

void Cvijet::drawKrug(sf::RenderWindow& window)
{
	sf::CircleShape shape(25);
	//shape.setFillColor(sf::Color(25, 226, 112));
	shape.setTexture(&texture);
	shape.setPointCount(100);
	shape.setPosition(x,y);
	window.draw(shape);
}

void Cvijet::drawSunce(sf::Clock& cukica, sf::RenderWindow& window) {
	sf::Time elapsed = cukica.getElapsedTime();
	x = elapsed.asSeconds();
	x *= 60;
	if (x>=600) {
		cukica.restart();
	}

	sf::CircleShape sunce(200);
	sunce.setFillColor(sf::Color(248, 180, 0));
	sunce.setRadius(40);
	sunce.setPosition(x, y);

	window.draw(sunce);
}

void Cvijet::draw(sf::RenderWindow& window) {
	int c=200;
	sf::CircleShape circle(200);
	circle.setFillColor(sf::Color(248, 180, 0));
	circle.setOutlineThickness(15);
	circle.setOutlineColor(sf::Color(248, 180, 0));
	circle.setRadius(40);
	circle.setPosition(200, 200);

	sf::RectangleShape line(sf::Vector2f(20,250));
	line.setFillColor(sf::Color(18, 91, 80));
	line.setPosition((c/4)+180, c/4+250);

	sf::ConvexShape convex;
	convex.setPointCount(3);
	convex.setPoint(0, sf::Vector2f(0, 0));
	convex.setPoint(2, sf::Vector2f(20, 40));
	convex.setPoint(1, sf::Vector2f(40, 0));
	convex.setOrigin(20,0);
	convex.setPosition(240,200);
	convex.setRotation(180);
	convex.setFillColor(sf::Color(248, 180, 0));

	sf::ConvexShape convex2;
	convex2.setPointCount(3);
	convex2.setPoint(0, sf::Vector2f(0, 0));
	convex2.setPoint(2, sf::Vector2f(20, 40));
	convex2.setPoint(1, sf::Vector2f(40, 0));
	convex2.setOrigin(20, 0);
	convex2.setPosition(280, 240);
	convex2.setRotation(270);
	convex2.setFillColor(sf::Color(248, 180, 0));

	sf::ConvexShape convex1;
	convex1.setPointCount(3);
	convex1.setPoint(0, sf::Vector2f(0, 0));
	convex1.setPoint(2, sf::Vector2f(20, 40));
	convex1.setPoint(1, sf::Vector2f(40, 0));
	convex1.setOrigin(20, 0);
	convex1.setPosition(240, 280);
	convex1.setRotation(360);
	convex1.setFillColor(sf::Color(248, 180, 0));

	sf::ConvexShape convex3;
	convex3.setPointCount(3);
	convex3.setPoint(0, sf::Vector2f(0, 0));
	convex3.setPoint(2, sf::Vector2f(20, 40));
	convex3.setPoint(1, sf::Vector2f(40, 0));
	convex3.setOrigin(20, 0);
	convex3.setPosition(200, 240);
	convex3.setRotation(90);
	convex3.setFillColor(sf::Color(248, 180, 0));

	sf::ConvexShape convex4;
	convex4.setPointCount(3);
	convex4.setPoint(0, sf::Vector2f(0, 0));
	convex4.setPoint(2, sf::Vector2f(20, 40));
	convex4.setPoint(1, sf::Vector2f(40, 0));
	convex4.setOrigin(20, 0);
	convex4.setPosition(260, 220);
	convex4.setRotation(225);
	convex4.setFillColor(sf::Color(248, 180, 0));
	convex4.setOutlineThickness(5);
	convex4.setOutlineColor(sf::Color(0,0,0));

	sf::ConvexShape convex5;
	convex5.setPointCount(3);
	convex5.setPoint(0, sf::Vector2f(0, 0));
	convex5.setPoint(2, sf::Vector2f(20, 40));
	convex5.setPoint(1, sf::Vector2f(40, 0));
	convex5.setOrigin(20, 0);
	convex5.setPosition(260, 260);
	convex5.setRotation(315);
	convex5.setFillColor(sf::Color(248, 180, 0));
	convex5.setOutlineThickness(5);
	convex5.setOutlineColor(sf::Color(0, 0, 0));

	sf::ConvexShape convex6;
	convex6.setPointCount(3);
	convex6.setPoint(0, sf::Vector2f(0, 0));
	convex6.setPoint(2, sf::Vector2f(20, 40));
	convex6.setPoint(1, sf::Vector2f(40, 0));
	convex6.setOrigin(20, 0);
	convex6.setPosition(220,260);
	convex6.setRotation(45);
	convex6.setFillColor(sf::Color(248, 180, 0));
	convex6.setOutlineThickness(5);
	convex6.setOutlineColor(sf::Color(0, 0, 0));

	sf::ConvexShape convex7;
	convex7.setPointCount(3);
	convex7.setPoint(0, sf::Vector2f(0, 0));
	convex7.setPoint(2, sf::Vector2f(20, 40));
	convex7.setPoint(1, sf::Vector2f(40, 0));
	convex7.setOrigin(20, 0);
	convex7.setPosition(220,220);
	convex7.setRotation(135);
	convex7.setFillColor(sf::Color(248, 180, 0));
	convex7.setOutlineThickness(5);
	convex7.setOutlineColor(sf::Color(0, 0, 0));

	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(170.f, 10.f));
	list.setPoint(1, sf::Vector2f(120.f, 70.f));
	list.setPoint(2, sf::Vector2f(30.f, 100.f));
	list.setPoint(3, sf::Vector2f(70.f, 50.f));
	list.setFillColor(sf::Color(18, 91, 80));
	list.setPosition(220, 350);

	window.draw(circle);
	window.draw(convex4);
	window.draw(convex5);
	window.draw(convex6);
	window.draw(convex7);

	window.draw(line);
	window.draw(list);
	window.draw(convex);
	window.draw(convex1);
	window.draw(convex2);
	window.draw(convex3);
	
}

void Cvijet::update()
{
	if (y+50 < 600) {
		y += dy;
		dy += gravity;
	}
	else {
		dy *= -elasticity;
		y += dy*2;
		if (abs(dy) < 1) {
			dy = 0;
			unistiti = true;
		}
	}
}

void Cvijet::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Cvijet::setElasticity(double e) {
	elasticity = e;
}

bool Cvijet::trebaUnistiti() {
	return unistiti;
}

