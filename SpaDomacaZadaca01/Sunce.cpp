#include "Sunce.h"
#include <iostream>

Sunce::Sunce(sf::RenderWindow* window) {
	this->window = window;
}

sf::CircleShape sunce(75.f, 100.f);

void first_position(sf::CircleShape& sunce) {
	sunce.setPosition(550.f, 150.f);
}


void Sunce::draw() {
	first_position(sunce);

	sunce.setFillColor(sf::Color::Yellow);
	sunce.setOutlineColor(sf::Color(255, 162, 68, 255));
	sunce.setOutlineThickness(18.f);
	sunce.setPosition(x, y);
	x--;
	y++;
	window->draw(sunce);
}