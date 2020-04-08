#include "Cvijet.h"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window) { this->window = window; }

Cvijet::~Cvijet() {}

void Cvijet::draw() {
	s = EllipseShape(sf::Vector2f(7.f, 127.f));
	s.setRotation(15);
	s.setPosition(390, 420);
	s.setFillColor(sf::Color(40, 153, 40));
	s.setOutlineThickness(2.f);
	s.setOutlineColor(sf::Color(0, 0, 0));

	s2 = s1 = EllipseShape(sf::Vector2f(15.f, 48.f));
	s1.setRotation(-45);
	s1.setPosition(280, 520);
	s1.setFillColor(sf::Color(40, 153, 40));
	s1.setOutlineThickness(2.f);
	s1.setOutlineColor(sf::Color(0, 0, 0));
	s2.setRotation(70);
	s2.setPosition(440, 520);
	s2.setFillColor(sf::Color(40, 153, 40));
	s2.setOutlineThickness(2.f);
	s2.setOutlineColor(sf::Color(0, 0, 0));

	c = sf::CircleShape(20.f);
	c.setPosition(380.f, 380.f);
	c.setFillColor(sf::Color(224, 126, 15));
	c.setOutlineThickness(2.f);
	c.setOutlineColor(sf::Color(0, 0, 0));

	for (int i = 0; i < 9; ++i) {
		l[i] = EllipseShape(sf::Vector2f(40.f, 20.f));
		l[i].rotate((i + 1) * 40.f);
		l[i].setPosition(400.f, 400.f);
		l[i].setFillColor(sf::Color(100, 0, 0));
		l[i].setOutlineThickness(2.f);
		l[i].setOutlineColor(sf::Color(0, 0, 0));
	}

	time = clk.getElapsedTime();
	if (time.asSeconds() < 1) {
		rainposx = 700;
		rainposy = 100;
	} else {
		rainposx -= 10;
		rainposy += 10;
	}
	r = EllipseShape(sf::Vector2f(1.5f, 5.f));
	r.setRotation(45);
	r.setPosition(rainposx, rainposy);
	r.setFillColor(sf::Color(40, 96, 153));

	window->draw(s2);
	window->draw(s1);
	window->draw(s);
	for (int i = 0; i < 9; ++i)
		window->draw(l[i]);
	window->draw(c);
	window->draw(r);
}
