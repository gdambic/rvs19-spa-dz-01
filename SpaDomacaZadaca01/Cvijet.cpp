#include "Cvijet.h"
#include <vector>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	this->sun = sf::CircleShape();
	this->dolly = sf::CircleShape(50.f);
	this->stem = sf::ConvexShape();
	this->frameClock = sf::Clock();
	this->constant = 1.f;
}

void Cvijet::draw()
{
	sun.setRadius(sun.getRadius() + this->get_const());

	if (sun.getRadius() > 50 || sun.getRadius() < 0) { this->set_const(-get_const()); }

	sun.setPosition(600, 45);

	sun.setFillColor(sf::Color(255, 165, 0));

	sun.setOutlineThickness(5.f);

	sun.setOutlineColor(sf::Color(255, 255, 0));

	window->draw(sun);




	stem.setPointCount(4);

	stem.setPoint(0, sf::Vector2f(250.f, 500.f));

	stem.setPoint(1, sf::Vector2f(250.f, 200.f));

	stem.setPoint(2, sf::Vector2f(300.f, 200.f));

	stem.setPoint(3, sf::Vector2f(300.f, 500.f));

	stem.setFillColor(sf::Color(0, 255, 0));

	window->draw(stem);




	dolly.setPosition(225.f, 90.f);

	dolly.setFillColor(sf::Color(230, 230, 250));

	dolly.setOutlineThickness(80.f);

	dolly.setOutlineColor(sf::Color(139, 0, 139));

	window->draw(dolly);







}

sf::ConvexShape Cvijet::get_stem() const {
	return stem;
}

void Cvijet::set_stem(const sf::ConvexShape stem) {
	this->stem = stem;
}


sf::CircleShape Cvijet::get_cvijet() const {
	return dolly;
}

void Cvijet::set_cvijet(const sf::CircleShape dolly) {
	this->dolly = dolly;
}


float Cvijet::get_const() const {
	return constant;
}

void Cvijet::set_const(const float constant) {
	this->constant = constant;
}

sf::CircleShape Cvijet::get_sun() const {
	return sun;
}

void Cvijet::set_sun(const sf::CircleShape sunce) {
	this->sun = sun;
}
