#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window) {
		this->window = window;
}

void Cvijet::draw() {
	// Postavi dijelove cvijeta
	stabljika_setup();
	vanjski_setup();
	unutarnji_setup();
	list_setup();

	//Nacrta dijelove cvijeta
	window->draw(stabljika);
	window->draw(vanjski);
	window->draw(unutarnji);
	window->draw(list);	

	//Postavi sunce
	sunce.setPosition(sf::Vector2f(sunceX, 10.f));
	sunce.setRadius(sunceRadius);
	sunce.setFillColor(sf::Color::Yellow);

	// 16.66 ms je 60fps
	//Povecavanje pa smanjivanje sunca
	if (clock.getElapsedTime() >= sf::milliseconds(16.66f) && !radiusCheck) {
		sunceRadius += 0.10f;
		if (sunceRadius > 15) {
			radiusCheck = 1;
		}
	}
	else {
		sunceRadius -= 0.10f;
		if (sunceRadius < 10) {
			radiusCheck = 0;
		}
	}

	//Micanje sunca desno pa lijevo
	if (clock.getElapsedTime() >= sf::milliseconds(16.66f) && !animacijaCheck) {
		window->draw(sunce);
		++++sunceX; //zasto ovo radi
		sunce.move(sunceX, 10.f);
		if (sunceX > 260.f) {
			animacijaCheck = 1;
		}
		clock.restart();
	}
	else {
		window->draw(sunce);
		----sunceX;
		sunce.move(sunceX, 10.f);
		if (sunceX < 10.f) {
			animacijaCheck = 0;
		}
		clock.restart();
	}
}

void Cvijet::unutarnji_setup() {
	unutarnji.setFillColor(sf::Color::Yellow);
	unutarnji.setRadius(40.f);
	unutarnji.setPosition(120.f, 120.f);
}
void Cvijet::vanjski_setup() {
	vanjski.setFillColor(sf::Color::Red);
	vanjski.setRadius(60.f);
	vanjski.setPosition(100.f, 100.f);
}

void Cvijet::stabljika_setup() {
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setSize(sf::Vector2f(10.f, 150.f));
	stabljika.setPosition(sf::Vector2f(155.f, 200.f));
}

void Cvijet::list_setup() {
	list.setFillColor(sf::Color::Green);
	list.setPosition(sf::Vector2f(160.f, 250.f));
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(50.f, 20.f));
	list.setPoint(2, sf::Vector2f(90.f, 0.f));
	list.setPoint(3, sf::Vector2f(30.f, -5.f));
}