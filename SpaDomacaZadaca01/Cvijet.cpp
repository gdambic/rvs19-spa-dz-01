#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include <math.h>


Cvijet::Cvijet(sf::RenderWindow *window) {
	this->window = window;
}

void Cvijet::draw() {
	const sf::Color &zeleno = sf::Color(0, 153, 0, 179);
	const sf::Color &bojatucka = sf::Color(255, 255, 77, 255);
	const sf::Color &zrak = sf::Color(218 ,250, 235, 255);
	const sf::Color &zrak2 = sf::Color(167, 200, 160, 255);

	


	sf::RectangleShape stablo(sf::Vector2f(8, 300));
	stablo.setPosition(280, 300);
	stablo.setFillColor(zeleno);
	stablo.setOutlineColor(zeleno);
	stablo.setOutlineThickness(3);
	stablo.rotate(3);
	window->draw(stablo);

	sf::CircleShape tucak(50.f);
	tucak.setPosition(240, 150);
	tucak.setFillColor(bojatucka);
	tucak.setOutlineColor(sf::Color::Magenta);
	tucak.setOutlineThickness(60);
	window->draw(tucak);

	sf::ConvexShape list;
	list.setPointCount(4);
	list.setFillColor(sf::Color::Green);
	list.setPoint(0, sf::Vector2f(230, 300));
	list.setPoint(1, sf::Vector2f(350, 360));
	list.setPoint(2, sf::Vector2f(450, 300));
	list.setPoint(3, sf::Vector2f(230, 320));
	window->draw(list);

	sf::ConvexShape list2;
	list2.setPointCount(4);
	list2.setFillColor(zeleno);
	list2.setPoint(3, sf::Vector2f(280, 440));
	list2.setPoint(2, sf::Vector2f(420, 500));
	list2.setPoint(1, sf::Vector2f(530, 460));
	list2.setPoint(0, sf::Vector2f(350, 440));
	window->draw(list2);

	sf::CircleShape triangle(80, 3);
	triangle.setPosition(300, 500);
	triangle.rotate(60);
	triangle.setFillColor(sf::Color::Green);
	window->draw(triangle);

	sf::CircleShape okod(7);
	okod.setPosition(300, 180);
	okod.setFillColor(sf::Color::Black);
	window->draw(okod);

	sf::CircleShape okol(7);
	okol.setPosition(275, 180);
	okol.setFillColor(sf::Color::Black);
	window->draw(okol);

	sf::ConvexShape usta;
	usta.setPointCount(4);
	usta.setFillColor(zeleno);
	usta.setPoint(2, sf::Vector2f(270, 255));
	usta.setPoint(1, sf::Vector2f(285, 200));
	usta.setPoint(0, sf::Vector2f(290, 200));
	usta.setPoint(3, sf::Vector2f(300, 255));
	window->draw(usta);

	sf::CircleShape sunce(50.f);
	sunce.setFillColor(sf::Color::Yellow);

	if (sin(clock.getElapsedTime().asSeconds()) > 0){
		sunce.setPosition(4.2*clock.getElapsedTime().asSeconds(), 4.2*clock.getElapsedTime().asSeconds());
		sunce.scale(sin(clock.getElapsedTime().asSeconds()), sin(clock.getElapsedTime().asSeconds()));}

	 else if(sin(clock.getElapsedTime().asSeconds()) < 0){
		sunce.setFillColor(zrak2);
		sunce.setPosition(420-0.8*clock.getElapsedTime().asSeconds(), 420-0.8*clock.getElapsedTime().asSeconds());
		sunce.setOutlineColor(zrak);
		sunce.setOutlineThickness(42);
		sunce.scale(tan(clock.getElapsedTime().asSeconds()), sin(clock.getElapsedTime().asSeconds()));
	}
		 
	if(clock.getElapsedTime().asSeconds()>6)clock.restart();
	window->draw(sunce);
}

