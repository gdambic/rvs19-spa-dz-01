#include "Cvijet.h"
#include "EllipseShape.cpp"
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape stabljika(sf::Vector2f(200.f, 10.f));
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setPosition(395.f, 225.f);
	stabljika.setRotation(90.f);
	window->draw(stabljika);

	EllipseShape list(sf::Vector2f(20.f, 40.f));
	list.setFillColor(sf::Color::Green);
	list.setPosition(425.f, 250.f);
	list.setRotation(35.f);
	window->draw(list);

	EllipseShape list2(sf::Vector2f(20.f, 40.f));
	list2.setFillColor(sf::Color::Green);
	list2.setPosition(320.f, 325.f);
	list2.setRotation(-40.f);
	window->draw(list2);

	EllipseShape latica(sf::Vector2f(20.f, 40.f));
	latica.setFillColor(sf::Color::Yellow);
	latica.setOutlineThickness(1.f);
	latica.setOutlineColor(sf::Color::Black);
	latica.setPosition(425.f, 125.f);
	latica.setRotation(35.f);
	window->draw(latica);
	
	EllipseShape latica2(sf::Vector2f(20.f, 40.f));
	latica2.setFillColor(sf::Color::Yellow);
	latica2.setOutlineThickness(1.f);
	latica2.setOutlineColor(sf::Color::Black);
	latica2.setPosition(455.f, 150.f);
	latica2.setRotation(75.f);
	window->draw(latica2);

	EllipseShape latica3(sf::Vector2f(20.f, 40.f));
	latica3.setFillColor(sf::Color::Yellow);
	latica3.setOutlineThickness(1.f);
	latica3.setOutlineColor(sf::Color::Black);
	latica3.setPosition(465.f, 200.f);
	latica3.setRotation(115.f);
	window->draw(latica3);

	EllipseShape latica4(sf::Vector2f(20.f, 40.f));
	latica4.setFillColor(sf::Color::Yellow);
	latica4.setOutlineThickness(1.f);
	latica4.setOutlineColor(sf::Color::Black);
	latica4.setPosition(445.f, 250.f);
	latica4.setRotation(145.f);
	window->draw(latica4);
	
	EllipseShape latica5(sf::Vector2f(20.f, 40.f));
	latica5.setFillColor(sf::Color::Yellow);
	latica5.setOutlineThickness(1.f);
	latica5.setOutlineColor(sf::Color::Black);
	latica5.setPosition(410.f, 275.f);
	latica5.setRotation(175.f);
	window->draw(latica5);
	
	EllipseShape latica6(sf::Vector2f(20.f, 40.f));
	latica6.setFillColor(sf::Color::Yellow);
	latica6.setOutlineThickness(1.f);
	latica6.setOutlineColor(sf::Color::Black);
	latica6.setPosition(350.f, 275.f);
	latica6.setRotation(215.f);
	window->draw(latica6);
	
	EllipseShape latica7(sf::Vector2f(20.f, 40.f));
	latica7.setFillColor(sf::Color::Yellow);
	latica7.setOutlineThickness(1.f);
	latica7.setOutlineColor(sf::Color::Black);
	latica7.setPosition(315.f, 235.f);
	latica7.setRotation(255.f);
	window->draw(latica7);
	
	EllipseShape latica8(sf::Vector2f(20.f, 40.f));
	latica8.setFillColor(sf::Color::Yellow);
	latica8.setOutlineThickness(1.f);
	latica8.setOutlineColor(sf::Color::Black);
	latica8.setPosition(315.f, 175.f);
	latica8.setRotation(295.f);
	window->draw(latica8);
	
	EllipseShape latica9(sf::Vector2f(20.f, 40.f));
	latica9.setFillColor(sf::Color::Yellow);
	latica9.setOutlineThickness(1.f);
	latica9.setOutlineColor(sf::Color::Black);
	latica9.setPosition(335.f, 135.f);
	latica9.setRotation(335.f);
	window->draw(latica9);
	
	EllipseShape latica10(sf::Vector2f(20.f, 40.f));
	latica10.setFillColor(sf::Color::Yellow);
	latica10.setOutlineThickness(1.f);
	latica10.setOutlineColor(sf::Color::Black);
	latica10.setPosition(385.f, 115.f);
	latica10.setRotation(375.f);
	window->draw(latica10);

	sf::CircleShape sredina(40.f);
	sredina.setFillColor(sf::Color(160, 82, 45));
	sredina.setPosition(350.f, 150.f);
	window->draw(sredina);
}
