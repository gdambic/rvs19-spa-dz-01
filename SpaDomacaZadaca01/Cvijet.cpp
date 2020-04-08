#include<iostream>
#include <SFML/Graphics.hpp>
#include "Cvijet.h"
using namespace sf;
using namespace std;

Cvijet::Cvijet(RenderWindow *window)
{
	this->renwin = window;
}

void Cvijet::setCvijet()
{
	setOctagon();
	setCircle();
	setBranch();
	setLeaf();
	setSun();
}

void Cvijet::setOctagon()
{
	octagon.setRadius(100.f);
	octagon.setPointCount(frameClock);
	octagon.setPosition(50, 50);
	octagon.setFillColor(Color::Cyan);
}

void Cvijet::setCircle()
{
	shape.setRadius(50.f);
	shape.setPosition(100, 100);
	shape.setFillColor(Color::Yellow);
}

void Cvijet::setBranch()
{
	branch.setSize(Vector2f(250.f, 10.f));
	branch.setRotation(90.f);
	branch.setPosition(155, 155);
	branch.setFillColor(Color::Green);
}

void Cvijet::setLeaf()
{
	leaf.setPointCount(3);
	leaf.setPoint(0, Vector2f(0.f, 0.f));
	leaf.setPoint(1, Vector2f(150.f, 10.f));
	leaf.setPoint(2, Vector2f(0.f, 50.f));
	leaf.setPosition(155, 300);
	leaf.setFillColor(Color::Green);
}

void Cvijet::setSun()
{
	sun.setRadius(frameClock);
	sun.setFillColor(Color::Yellow);
}

void Cvijet::draw()
{
	setCvijet();
	frameClock = clock.getElapsedTime().asSeconds() * 10;

	renwin->draw(branch);
	renwin->draw(octagon);
	renwin->draw(shape);
	renwin->draw(leaf);
	renwin->draw(sun);

	if (clock.getElapsedTime().asSeconds() > 3) clock.restart();
}
