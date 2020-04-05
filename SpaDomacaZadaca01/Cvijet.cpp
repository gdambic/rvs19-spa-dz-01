#include "Cvijet.h"
#include <vector>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	this->sunce = sf::CircleShape();
	this->latice = std::vector<sf::CircleShape>(6, sf::CircleShape(50.f));
	this->tucak = sf::CircleShape(50.f);
	this->peteljka = sf::ConvexShape();
	this->frameClock = sf::Clock();
	this->konstanta = 1.f;
}

void Cvijet::draw()
{
	//sunce:
	sunce.setRadius(sunce.getRadius() + this->get_konstanta());
	if (sunce.getRadius() > 50 || sunce.getRadius() < 0) { this->set_konstanta(- get_konstanta()); }
	sunce.setPosition(25, 25);
	sunce.setFillColor(sf::Color(255, 255, 255));
	sunce.setOutlineThickness(5.f);
	sunce.setOutlineColor(sf::Color(255, 255, 0));
	window->draw(sunce);
	
	//peteljka:
	peteljka.setPointCount(8);
	peteljka.setPoint(0, sf::Vector2f(300.f, 600.f));
	peteljka.setPoint(1, sf::Vector2f(400.f, 300.f));
	peteljka.setPoint(2, sf::Vector2f(425.f, 300.f));
	peteljka.setPoint(3, sf::Vector2f(325.f, 300.f));
	peteljka.setPoint(4, sf::Vector2f(325.f, 450.f));
	peteljka.setPoint(5, sf::Vector2f(225.f, 450.f));
	peteljka.setPoint(6, sf::Vector2f(325.f, 550.f));
	peteljka.setPoint(7, sf::Vector2f(325.f, 600.f));
	peteljka.setFillColor(sf::Color(0, 255, 0));
	window->draw(peteljka);

	//latice:
	float laticeKoordinate[6][2]
	{
		{250.f, 150.f},
		{325.f, 100.f},
		{400.f, 150.f},
		{400.f, 225.f},
		{325.f, 275.f},
		{250.f, 225.f},
	};
	for (int i = 0; i < 6; i++) {
		latice[i].setPosition(laticeKoordinate[i][0], laticeKoordinate[i][1]);
		latice[i].setFillColor(sf::Color(255, 0, 0));
		latice[i].setOutlineThickness(5.f);
		latice[i].setOutlineColor(sf::Color(255, 100, 100));
		window->draw(latice[i]);
	}

	//tucak:
	tucak.setPosition(325.f, 190.f);
	tucak.setFillColor(sf::Color(255, 255, 0));
	tucak.setOutlineThickness(10.f);
	tucak.setOutlineColor(sf::Color(0, 0, 0));
	window->draw(tucak);
}

sf::CircleShape Cvijet::get_sunce() const { return sunce;}

void Cvijet::set_sunce(const sf::CircleShape sunce) { this->sunce = sunce;}

std::vector<sf::CircleShape> Cvijet::get_latice() const { return latice;}

void Cvijet::set_latice(const std::vector<sf::CircleShape> latice) { this->latice = latice;}

sf::CircleShape Cvijet::get_tucak() const { return tucak;}

void Cvijet::set_tucak(const sf::CircleShape tucak) { this->tucak = tucak;}

sf::ConvexShape Cvijet::get_peteljka() const { return peteljka;}

void Cvijet::set_peteljka(const sf::ConvexShape peteljka){ this->peteljka = peteljka;}

float Cvijet::get_konstanta() const { return konstanta;}

void Cvijet::set_konstanta(const float konstanta) { this->konstanta = konstanta;}
