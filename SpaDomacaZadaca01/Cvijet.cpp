#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;

}

void Cvijet::draw()
{
	//main flower
	sf::CircleShape square(85.f, 4);
	square.setOrigin(square.getRadius(), square.getRadius());
	square.setFillColor(sf::Color(134, 14, 14));
	
	square.setOutlineThickness(75.f);
	square.setOutlineColor(sf::Color(51, 5, 5));
	
	square.setPosition((window->getSize().x / 2), (window->getSize().y / 2));

	//cover edges
	sf::RectangleShape cover1(sf::Vector2f(100.f, 50.f));
	cover1.setOrigin(50.f, 25.f);
	cover1.setFillColor(sf::Color(42, 78, 101));
	sf::RectangleShape cover2(sf::Vector2f(100.f, 50.f));
	cover2.setOrigin(50.f, 25.f);
	cover2.setFillColor(sf::Color(42, 78, 101));
	sf::RectangleShape cover3(sf::Vector2f(100.f, 50.f));
	cover3.setOrigin(50.f, 25.f);
	cover3.setFillColor(sf::Color(42, 78, 101));
	sf::RectangleShape cover4(sf::Vector2f(100.f, 50.f));
	cover4.setOrigin(50.f, 25.f);
	cover4.setFillColor(sf::Color(42, 78, 101));

	cover1.setPosition(400.f, 134.f);
	cover2.setPosition(400.f, 466.f);
	cover3.rotate(90.f);
	cover3.setPosition(234.f, (window->getSize().y / 2));
	cover4.rotate(90.f);
	cover4.setPosition(566.f, (window->getSize().y / 2));
	
	//stem
	sf::ConvexShape stem;
	stem.setPointCount(8);
	stem.setFillColor(sf::Color(12, 64, 13));

	stem.setPoint(0, sf::Vector2f(385.f, 441.f));
	stem.setPoint(1, sf::Vector2f(362.f, 478.f));
	stem.setPoint(2, sf::Vector2f(365.f, 526.f));
	stem.setPoint(3, sf::Vector2f(350.f, 576.f));
	stem.setPoint(4, sf::Vector2f(370.f, 576.f));
	stem.setPoint(5, sf::Vector2f(385.f, 531.f));
	stem.setPoint(6, sf::Vector2f(380.f, 496.f));
	stem.setPoint(7, sf::Vector2f(405.f, 441.f));

	//leaf1
	sf::ConvexShape leaf1;
	leaf1.setPointCount(5);
	leaf1.setFillColor(sf::Color(12, 64, 13));

	leaf1.setPoint(0, sf::Vector2f(380.f, 510.f));
	leaf1.setPoint(1, sf::Vector2f(410.f, 498.f));
	leaf1.setPoint(2, sf::Vector2f(420.f, 480.f));
	leaf1.setPoint(3, sf::Vector2f(390.f, 490.f));
	leaf1.setPoint(4, sf::Vector2f(380.f, 505.f));

	//sun
	sf::CircleShape sun(30.f);
	sun.setFillColor(sf::Color().Yellow);
	sun.setOrigin(sun.getRadius(), sun.getRadius());

	sun.move(50.f, 50.f);



	window->draw(square);
	window->draw(cover1);
	window->draw(cover2);
	window->draw(cover3);
	window->draw(cover4);
	window->draw(stem);
	window->draw(leaf1);
	window->draw(sun);


}
