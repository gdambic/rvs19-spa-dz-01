#include "cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

using namespace sf; 
using namespace std; 


void cvijet::draw()
{
	draw_background();
	draw_noga();
	draw_latice();
	draw_sunce();
}

void cvijet::draw_latice()
{
	CircleShape shape;
	shape.setRadius(30);
	shape.setFillColor(Color(228, 232, 170));
	shape.move(210, 170);

	CircleShape latice; 
	latice.setRadius(35); 
	latice.move(242, 200); 
	latice.setRotation(0); 

	for (int i = 0; i < 5; i++)
	{
		latice.rotate(72); 
		latice.setFillColor(Color(153,50,204));
		window->draw(latice);
		
	}
	window->draw(shape);
}

void cvijet::draw_noga()
{
	RectangleShape line(Vector2f(190, 8));
	line.rotate(90); 
	line.setFillColor(Color(0,128,0));
	line.move(250, 240);
	window->draw(line); 

	ConvexShape list; 
	list.setFillColor(Color(0, 128, 0));
	list.setPointCount(4); 
	list.setPoint(0, Vector2f(250, 360));
	list.setPoint(1, Vector2f(300, 300));
	list.setPoint(2, Vector2f(400, 280));
	list.setPoint(3, Vector2f(300, 350));
	window->draw(list); 
}

void cvijet::draw_sunce()
{
	CircleShape sunce;
	sunce.setRadius(80);
	sunce.setFillColor(Color(255, 215, 0));
	sunce.setOrigin(80, 80); 
	sunce.setPosition(750, 20); 
	window->draw(sunce);

	auto t = clock.getElapsedTime();
	stringstream ss;
	ss << t.asSeconds();
	int timer;
	ss >> timer;

	vector<RectangleShape> zrake(5);

	zrake[0].rotate(95); 
	zrake[0].setSize(Vector2f(75,5));
	zrake[0].setFillColor(Color(255, 215, 0));
	zrake[0].setPosition(750, 120); 
	if (timer % 2 == 0)zrake[0].setFillColor(Color(255,140,0));

	zrake[1].rotate(115);
	zrake[1].setSize(Vector2f(75, 5));
	zrake[1].setFillColor(Color(255, 215, 0));
	zrake[1].setPosition(720, 110);
	if (timer % 2 == 1)zrake[1].setFillColor(Color(255, 140, 0));

	zrake[2].rotate(135);
	zrake[2].setSize(Vector2f(75, 5));
	zrake[2].setFillColor(Color(255, 215, 0));
	zrake[2].setPosition(695, 90);
	if (timer % 2 == 0)zrake[2].setFillColor(Color(255, 140, 0));

	zrake[3].rotate(155);
	zrake[3].setSize(Vector2f(75, 5));
	zrake[3].setFillColor(Color(255, 215, 0));
	zrake[3].setPosition(675, 70);
	if (timer % 2 == 1)zrake[3].setFillColor(Color(255, 140, 0));

	zrake[4].rotate(175);
	zrake[4].setSize(Vector2f(75, 5));
	zrake[4].setFillColor(Color(255, 215, 0));
	zrake[4].setPosition(655, 40);
	if (timer % 2 == 0)zrake[4].setFillColor(Color(255, 140, 0));

	for (int i = 0; i < 5; i++)
	{
		window->draw(zrake[i]); 
	}
}

void cvijet::draw_background()
{
	RectangleShape tlo(Vector2f(3000, 200));
	tlo.setFillColor(Color(139,69,19));
	tlo.move(0, 400);
	
	RectangleShape nebo(Vector2f(3000, 2000));
	nebo.setFillColor(Color(135, 206, 255));

	window->draw(nebo);
	window->draw(tlo);
}

cvijet::cvijet(RenderWindow* window)
{
	this->window = window; 
}
