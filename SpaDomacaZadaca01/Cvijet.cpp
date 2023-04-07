#include "Cvijet.h"



Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}



void Cvijet::draw()
{
	// zarotiraj i pomakni malo
	rotacija += 3.0f;
	pocetni_x += 3.0f;
	if (pocetni_x > window->getSize().x) {
		pocetni_x = 0;
	}



	// stabljika
	sf::RectangleShape stabljika(sf::Vector2f(10.f, 100.f));
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setPosition(pocetni_x + 15.f, pocetni_y + 30.f);



	// tučak
	sf::CircleShape tucak(15.0f);
	tucak.setFillColor(sf::Color::Yellow);
	tucak.setOutlineThickness(2.0f);
	tucak.setOutlineColor(sf::Color::Black);
	tucak.setPosition(pocetni_x + 5.f, pocetni_y + 5.f);



	// lišće
	sf::ConvexShape list1(4);
	list1.setPoint(0, sf::Vector2f(pocetni_x - 30, pocetni_y + 60));
	list1.setPoint(1, sf::Vector2f(pocetni_x - 5, pocetni_y + 70));
	list1.setPoint(2, sf::Vector2f(pocetni_x + 20, pocetni_y + 100));
	list1.setPoint(3, sf::Vector2f(pocetni_x - 10, pocetni_y + 90));
	list1.setFillColor(sf::Color::Green);



	sf::ConvexShape list2(4);
	list2.setPoint(0, sf::Vector2f(pocetni_x + 70, pocetni_y + 70));
	list2.setPoint(1, sf::Vector2f(pocetni_x + 45, pocetni_y + 80));
	list2.setPoint(2, sf::Vector2f(pocetni_x + 20, pocetni_y + 110));
	list2.setPoint(3, sf::Vector2f(pocetni_x + 50, pocetni_y + 100));
	list2.setFillColor(sf::Color::Green);



	// latice
	sf::CircleShape latice[BR_LATICA];
	for (int i = 0; i < BR_LATICA; i++) {
		latice[i].setFillColor(sf::Color::Red);
		latice[i].setOutlineThickness(2.0f);
		latice[i].setOutlineColor(sf::Color::Black);
		latice[i].setPosition(pocetni_x + 20.0f, pocetni_y + 20.0f);
		latice[i].setRotation(rotacija + 360.0f / BR_LATICA * i);
		latice[i].setRadius(18.0f);
	}



	window->draw(stabljika);
	window->draw(list1);
	window->draw(list2);
	for (int i = 0; i < BR_LATICA; i++) {
		window->draw(latice[i]);
	}
	window->draw(tucak);



}