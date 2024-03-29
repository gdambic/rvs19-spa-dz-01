#include "Cvijet.h"
#include <iostream>
Cvijet::Cvijet(sf::RenderWindow* window) : window(window)
{
	sunce = sf::CircleShape(25.f);
	sunce.setFillColor(sf::Color(255, 255, 0));

	shape0 = sf::CircleShape(150.f);
	shape0.setFillColor(sf::Color(255, 140, 0));
	shape0.setOrigin(150, 150);
	shape0.setPosition(sf::Vector2f(200, 200));

	shape1 = sf::CircleShape(100.f);
	shape1.setOrigin(100, 100);
	shape1.setFillColor(sf::Color(255, 255, 0));
	shape1.setPosition(200, 200);

	stabljika = sf::RectangleShape(sf::Vector2f(20, 200));
	stabljika.setPosition(200, 200 + 145);
	stabljika.setFillColor(sf::Color(0, 255, 0));

	list = sf::ConvexShape();
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(200.0f-200.0f, 400.0f-400.0f));
	list.setPoint(1, sf::Vector2f(350.f - 200.0f, 350.f - 400.0f));
	list.setPoint(2, sf::Vector2f(400.f - 200.0f, 400.f - 400.0f));
	list.setPoint(3, sf::Vector2f(350.f - 200.0f, 450.f - 400.0f));
	list.setPosition(205, 400);
	list.setFillColor(sf::Color::Green);
}

void Cvijet::Draw()
{
	window->draw(sunce);
	window->draw(stabljika);
	window->draw(shape0);
	window->draw(shape1);
	window->draw(list);
	RotirajList(0.5f);
	GoreDolje();
}

void Cvijet::RotirajList(float deg)
{
	list.setRotation(list.getRotation() + deg*list_dir);
	if (list_dir == -1 && list.getRotation() < 330) list_dir = 1;
	else if (list_dir == 1 && list.getRotation() < 330) list_dir = -1;
}

void Cvijet::GoreDolje()
{ 
	counter++;
	shape0.setPosition(shape0.getPosition().x, shape0.getPosition().y + sin(counter*0.025f)*0.15f);
	shape1.setPosition(shape0.getPosition().x, shape0.getPosition().y + sin(counter * 0.025f) * 0.15f);
}
