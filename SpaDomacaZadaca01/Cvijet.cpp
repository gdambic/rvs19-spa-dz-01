#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	drawFlower();
	//Zrake
	RectangleShape line1(Vector2f(100, 10));
	RectangleShape line2(Vector2f(100, 10));
	RectangleShape line3(Vector2f(100, 10));
	line1.setFillColor(Color(255, 255, 0));
	line2.setFillColor(Color(255, 255, 0));
	line3.setFillColor(Color(255, 255, 0));
	line1.rotate(0);
	line2.rotate(45);
	line3.rotate(90);
	line1.setPosition(130, 40);
	line2.setPosition(130, 100);
	line3.setPosition(75, 130);
	//Sunce
	CircleShape sun(50);
	sun.setFillColor(Color(255, 255, 0));
	window->draw(sun);
	//Animacija
	Time counter = frameClock.getElapsedTime();
	Time stop = seconds(1.00f);
	Time stop2 = seconds(2.00f);
	cout << counter.asSeconds() << endl;
	if (counter >= stop) {
		window->clear();
		drawFlower();
		sun.setRadius(75);
		window->draw(line1);
		window->draw(line2);
		window->draw(line3);
		window->draw(sun);
	}
	if (counter >= stop2) {
		window->clear();
		drawFlower();
		sun.setRadius(50);
		window->draw(sun);
		frameClock.restart();
	}
}

void Cvijet::drawFlower()
{
	//Gornji dio cvijeta
	CircleShape circle(75);
	circle.setFillColor(Color(255, 255, 0));
	circle.setOutlineColor(Color(255, 0, 0));
	circle.setOutlineThickness(20);
	circle.setPosition(300, 200);
	window->draw(circle);
	//Grancica
	RectangleShape line(Vector2f(250, 20));
	line.setFillColor(Color(0, 255, 0));
	line.rotate(90);
	line.setPosition(385, 370);
	window->draw(line);
	//List
	ConvexShape list;
	list.setPointCount(5);
	list.setFillColor(Color(0, 255, 0));
	list.setPosition(380, 400);
	list.setPoint(0, Vector2f(0, 0));
	list.setPoint(1, Vector2f(150, 10));
	list.setPoint(2, Vector2f(100, 200));
	list.setPoint(3, Vector2f(100, 100));
	list.setPoint(4, Vector2f(0, 150));
	window->draw(list);
}
