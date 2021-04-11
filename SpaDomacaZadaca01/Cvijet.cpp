#include "Cvijet.h"
#include <vector>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	this->sunce = sf::CircleShape();
	this->cvijet = sf::CircleShape(50.f);
	this->peteljka = sf::ConvexShape();
	this->frameClock = sf::Clock();
	this->konstanta = 1.f;
}

void Cvijet::draw()
{
	sunce.setRadius(sunce.getRadius() + this->get_konstanta());
	if (sunce.getRadius() > 50 || sunce.getRadius() < 0) { this->set_konstanta(-get_konstanta()); }
	sunce.setPosition(600, 25);
	sunce.setFillColor(sf::Color(255, 255, 0255));
	sunce.setOutlineThickness(5.f);
	sunce.setOutlineColor(sf::Color(255, 255, 0));
	window->draw(sunce);
	
	
	peteljka.setPointCount(4);
	peteljka.setPoint(0, sf::Vector2f(350.f, 600.f));
	peteljka.setPoint(1, sf::Vector2f(350.f, 300.f));
	peteljka.setPoint(2, sf::Vector2f(400.f, 300.f));
	peteljka.setPoint(3, sf::Vector2f(400.f, 600.f));
	
	peteljka.setFillColor(sf::Color(0, 255, 0));
	window->draw(peteljka);


	
	cvijet.setPosition(325.f, 190.f);
	cvijet.setFillColor(sf::Color(200, 255, 55));
	cvijet.setOutlineThickness(80.f);
	cvijet.setOutlineColor(sf::Color(255, 100, 150));
	window->draw(cvijet);
}

sf::CircleShape Cvijet::get_sunce() const {
	return sunce;
}

void Cvijet::set_sunce(const sf::CircleShape sunce) { 
	this->sunce = sunce;
}


sf::CircleShape Cvijet::get_cvijet() const {
	return cvijet;
}

void Cvijet::set_cvijet(const sf::CircleShape tucak) { 
	this->cvijet = tucak;
}

sf::ConvexShape Cvijet::get_peteljka() const {
	return peteljka;
}

void Cvijet::set_peteljka(const sf::ConvexShape peteljka){
	this->peteljka = peteljka;
}

float Cvijet::get_konstanta() const {
	return konstanta;
}

void Cvijet::set_konstanta(const float konstanta) { 
	this->konstanta = konstanta;
}