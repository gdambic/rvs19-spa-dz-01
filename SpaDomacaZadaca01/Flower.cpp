#include "Flower.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	drawFlower();

	RectangleShape zraka1(Vector2f(100, 10));
	RectangleShape zraka2(Vector2f(100, 10));
	RectangleShape zraka3(Vector2f(100, 10));
	RectangleShape zraka4(Vector2f(100, 10));
	zraka1.setPosition(130, 40);
	zraka2.setPosition(130, 100);
	zraka3.setPosition(75, 130);
	zraka4.setPosition(40, 0);
	zraka1.rotate(0);
	zraka2.rotate(30);
	zraka3.rotate(60);
	zraka4.rotate(15);
	zraka1.setFillColor(Color(238, 241, 78));
	zraka2.setFillColor(Color(238, 241, 78));
	zraka3.setFillColor(Color(238, 241, 78));
	zraka4.setFillColor(Color(238, 241, 78));

	CircleShape sunce(40);
	sunce.setFillColor(Color(238, 241, 78));
	window->draw(sunce);

	Time counter = frameClock.getElapsedTime();
	Time t1 = seconds(1.00f);
	Time t2 = seconds(2.00f);

	cout << counter.asSeconds() << endl;

	if (counter >= t1)
	{
		window->clear();
		drawFlower();
		window->draw(zraka1);
		window->draw(zraka2);
		window->draw(zraka3);
		sunce.setRadius(70);
		window->draw(sunce);


	}
	if (counter >= t2)
	{
		window->clear();
		drawFlower();
		sunce.setRadius(55);
		window->draw(sunce);
		/*window->draw(zraka1);
		window->draw(zraka2);
		window->draw(zraka3);*/
		frameClock.restart();
	}

}

void Cvijet::drawFlower()
{
	RectangleShape line(Vector2f(250, 20));
	line.setPosition(380, 370);
	line.rotate(90);
	line.setFillColor(Color(58, 218, 92));
	window->draw(line);

	CircleShape cvjetic(40);
	cvjetic.setFillColor(Color(255, 255, 0));
	cvjetic.setPosition(330, 240);
	cvjetic.setOutlineThickness(50);
	cvjetic.setOutlineColor(Color(206, 58, 218));
	window->draw(cvjetic);

	ConvexShape leaf;
	leaf.setPointCount(5);
	leaf.setPosition(380, 410);
	leaf.setFillColor(Color(58, 218, 92));
	leaf.setPoint(0, Vector2f(0, 0));
	leaf.setPoint(1, Vector2f(40, 10));
	leaf.setPoint(2, Vector2f(70, -50));
	leaf.setPoint(3, Vector2f(40, 70));
	leaf.setPoint(4, Vector2f(0, 80));
	window->draw(leaf);


}
