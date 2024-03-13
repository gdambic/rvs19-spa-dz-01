#include "Flower.h"
#include "EllipseShape.h";
#include <cmath>

Flower::Flower(sf::RenderWindow* window) {
	this->m_window = window;
	this->m_circle_radius = 50.f;
	this->m_clock = sf::Clock();
	this->m_isExpanding = true;
}

void Flower::draw() {
	
	//Circle
	sf::CircleShape shape(m_circle_radius);
	shape.setFillColor(sf::Color(46, 17, 24));
	shape.setOutlineThickness(10.f);
	shape.setOutlineColor(sf::Color(242, 147, 13));
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setPosition(400.f, 200.f);
	
	//Grass
	sf::RectangleShape rectangle(sf::Vector2f(800.f, 100.f));
	rectangle.setFillColor(sf::Color(100, 200, 0));
	rectangle.setPosition(0, 500);

	//Stem
	sf::RectangleShape rectangle2(sf::Vector2f(20.f, 400.f));
	rectangle2.setFillColor(sf::Color(100, 200, 100));
	rectangle2.setPosition(390, 200);
	
	Flower::m_window->draw(rectangle2);
	Flower::m_window->draw(rectangle);

	//Petals
	int petals = 12;

	int angle = 45;
	for (int i = 0; i < petals; i++)
	{
		EllipseShape ellipse(sf::Vector2f(100.f, 20.f));
		ellipse.setOrigin(0, 20);

		ellipse.setRotation(angle);
		ellipse.setPosition(400, 200);

		ellipse.setFillColor(sf::Color(255, 255, 100));

		Flower::m_window->draw(ellipse);

		angle += (360 / petals);

	}

	//Leaves
	EllipseShape ellipse(sf::Vector2f(50.f, 15.f));
	ellipse.setOrigin(0, 7);
	ellipse.setRotation(-30);
	ellipse.setPosition(400, 450);
	ellipse.setFillColor(sf::Color(100, 200, 100));
	Flower::m_window->draw(ellipse);

	EllipseShape ellipse2(sf::Vector2f(50.f, 15.f));
	ellipse2.setOrigin(0, 7);
	ellipse2.setRotation(190);
	ellipse2.setPosition(400, 450);
	ellipse2.setFillColor(sf::Color(100, 200, 100));
	Flower::m_window->draw(ellipse2);

	Flower::m_window->draw(shape);

	//Pulse Animation

	sf::Time time = m_clock.getElapsedTime();

	if (time.asMilliseconds() > 100) {
		m_clock.restart();

		if (m_isExpanding)
		{
			m_circle_radius += 1;
		}
		else {
			m_circle_radius -= 1;
		}
	}

	if (m_circle_radius >= 60 && m_isExpanding) {
		m_isExpanding = false;
	}
	else if (m_circle_radius <= 50 && !m_isExpanding) {
		m_isExpanding = true;
	}
}