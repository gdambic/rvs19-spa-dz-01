#include <SFML/Graphics.hpp>
#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
	this->init();
}

void Cvijet::draw()
{
	octagon.setPointCount((int)frameClock.getElapsedTime().asMilliseconds() / 100 % 10 * 10);

	window->draw(octagon);
	window->draw(line);
	window->draw(triangle1);
	window->draw(triangle2);
}


sf::CircleShape Cvijet::draw_triangle(float x, float y, float rot)
{
	sf::CircleShape triangle(40.f, 3);
	triangle.setFillColor(sf::Color::Green);
	triangle.setPosition(x, y);
	triangle.rotate(rot);
	return triangle;
}

sf::CircleShape Cvijet::draw_octagon()
{
	sf::CircleShape octagon(20.f, 8);
	octagon.setPosition(100.f, 100.f);
	octagon.setFillColor(sf::Color::Yellow);
	octagon.setOutlineThickness(60.f);
	octagon.setOutlineColor(sf::Color::White);
	return octagon;
}

sf::RectangleShape Cvijet::draw_line()
{
	sf::RectangleShape line(sf::Vector2f(300.f, 5.f));
	line.setFillColor(sf::Color::Green);
	line.setPosition(120.f, 200.f);
	line.rotate(90.f);
	return line;
}

void Cvijet::init()
{
	this->triangle1 = draw_triangle(60.f, 250.f, 30.f);
	this->triangle2 = draw_triangle(200.f, 210.f, 90.f);
	this->octagon = draw_octagon();
	this->line = draw_line();
}




