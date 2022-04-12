#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;


Cvijet::Cvijet(sf::RenderWindow* window) {
	
	this->window = window;
}

void Cvijet::draw() {

	mjesec();
	travnjak();
	cvijet();
	
}


void Cvijet::mjesec() {

	CircleShape shape(50.f);
	shape.setPosition(35.f, 35.f);
	shape.setFillColor(Color(160, 160, 160));
	shape.setOutlineThickness(15);
	shape.setOutlineColor(Color(200, 200, 200));
	window->draw(shape);
}

void Cvijet::travnjak() {
	RectangleShape travnjak(Vector2f(120.f, 80.f));
	travnjak.setSize(Vector2f(800.f, 600.f));
	travnjak.setRotation(0.f);
	travnjak.setPosition(0.f, 330.f);
	travnjak.setFillColor(Color(0, 100, 0));
	window->draw(travnjak);

}

void Cvijet::cvijet() {

	RectangleShape korijen(Vector2f(15.f, 100.f));
	korijen.setRotation(0.f);
	korijen.setPosition(432.f, 240.f);
	korijen.setFillColor(Color(50, 250, 50));
	window->draw(korijen);

	CircleShape latice(40.f, 6);
	latice.setFillColor(Color(250, 250, 100));
	latice.setPosition(400.f, 170.f);
	window->draw(latice);

	CircleShape centar(20.f);
	centar.setFillColor(Color(100, 50, 0));
	centar.setPosition(420.f, 190.f);
	window->draw(centar);
	
	
	

}



