#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow* m_window)
{
	this->window = m_window;
}

void Cvijet::draw()

{
	dt = clock.restart();
	
	sf::RectangleShape line,linef;
	line.setSize(Vector2f(800, 150));
	line.setPosition(0,450);
	line.setFillColor(sf::Color::Green);

	linef.setSize(Vector2f(5, 100));
	linef.setPosition(297, 350);
	linef.setFillColor(sf::Color::Green);

	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Yellow);
	shape.setRadius(50.f);
	shape.setPosition(Vector2f(250, 230));
	shape.setOutlineThickness(20.0f);
	shape.setOutlineColor(sf::Color::Red);


	sf::CircleShape circle(200.f);
	circle.setRadius(40.f);
	circle.setPosition(x, y);
	circle.setFillColor(sf::Color(sf::Color::Yellow));
	x += brzina;
	if (x>=gornja_granica || x<=doljna_granica)
	{
		brzina *= -1;
	}
	

	sf::ConvexShape convex;
	convex.setPointCount(5);
	convex.setPoint(0, sf::Vector2f(100.f, 40.f));
	convex.setPoint(1, sf::Vector2f(50.f, 10.f));
	convex.setPoint(2, sf::Vector2f(60.f, 30.f));
	convex.setPoint(3, sf::Vector2f(0.f, 50.f));
	convex.setPoint(4, sf::Vector2f(0.f, 50.f));
	convex.setFillColor(sf::Color::Green);
	convex.setPosition(300.f, 360.f);


	
	
	window->draw(circle);
	window->draw(shape);
	window->draw(line);
	window->draw(linef);
	window->draw(convex);
	
	
	

}
