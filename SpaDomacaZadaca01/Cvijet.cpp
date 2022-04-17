#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
	this->window = window;
}
void Cvijet::flower() {
	sf::CircleShape shape(80.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setOutlineColor(sf::Color(255, 255, 0));
	shape.setPosition(100, 100);
	shape.setOutlineThickness(40);
	shape.setOutlineColor(sf::Color(255, 0, 0));
	window->draw(shape);
}

void Cvijet::stem() {
	sf::RectangleShape rect(sf::Vector2f(8.f, 200.f));
	rect.setFillColor(sf::Color(0, 255, 0));
	rect.setPosition(180, 300);
	window->draw(rect);
}

void Cvijet::leaf() {
	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(177,390));
	convex.setPoint(1, sf::Vector2f(240,340));
	convex.setPoint(2, sf::Vector2f(490,240));
	convex.setPoint(3, sf::Vector2f(240,440));
	convex.setFillColor(sf::Color(0, 255, 0));
	window->draw(convex);
}

void Cvijet::draw() {
	time = frameClock.getElapsedTime();
	float sec = time.asSeconds();
	flower();
	stem();
	leaf();
	sf::CircleShape sun(30.f);
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
		// drawing the Sun
		window->draw(sun);
	}
}