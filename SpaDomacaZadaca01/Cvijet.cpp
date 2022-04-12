#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
	this->window = window;
}
void Cvijet::draw_flower() {
	sf::CircleShape shape(80.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setOutlineColor(sf::Color(255, 255, 0));
	shape.setPosition(100, 100);
	shape.setOutlineThickness(40);
	shape.setOutlineColor(sf::Color(255, 0, 0));
	window->draw(shape);
}

void Cvijet::draw_stem() {
	sf::RectangleShape rect(sf::Vector2f(8.f, 200.f));
	rect.setFillColor(sf::Color(0, 255, 0));
	rect.setPosition(180, 300);
	window->draw(rect);
}

void Cvijet::draw_leaf() {
	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(187,400));
	convex.setPoint(1, sf::Vector2f(250,350));
	convex.setPoint(2, sf::Vector2f(500,250));
	convex.setPoint(3, sf::Vector2f(250,450));
	convex.setFillColor(sf::Color(0, 255, 0));
	window->draw(convex);
}

void Cvijet::draw() {
	time = frameClock.getElapsedTime();
	float sec = time.asSeconds();
	draw_flower();
	draw_stem();
	draw_leaf();
	sf::CircleShape sun(30.f); //sun animation
	sun.setFillColor(sf::Color(255, 255, 0));
	if (sec >= 34.f)
	{
		frameClock.restart();
	}
	else
	{
		int speed = 25;
		float move_x = -55.f + (sec * speed);
		sun.setPosition(move_x,10);
		window->draw(sun);
	}
}