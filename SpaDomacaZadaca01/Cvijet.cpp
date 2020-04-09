#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Cvijet::Cvijet(sf::RenderWindow* adresa)
{
	this->adresa = adresa;
}

void Cvijet::draw()
{
	//BG_NEBESA
	sf::RectangleShape nebo(sf::Vector2f(800.f, 600.f));
	nebo.setFillColor(sf::Color(0, 191, 185));
	adresa->draw(nebo);

	//SUNCE
	sf::CircleShape sunce(40.f);
	sunce.setPosition(34.f, 34.f);
	sunce.setFillColor(sf::Color(255, 231, 15));
	sunce.setOutlineThickness(15.f);
	sunce.setOutlineColor(sf::Color(255, 200, 33));
	adresa->draw(sunce);

	//BG_LIVADA
	sf::ConvexShape livada(803);
	bool top = false;
	float j = 0.0f;
	for (float i = 0.0f; i < 802; i++)
	{
		if (top)
		{
			livada.setPoint(i, sf::Vector2f(j, 420.f));
			top = false;
		}
		else
		{
			livada.setPoint(i, sf::Vector2f(j, 380.f));
			top = true;
		}
		j += 3;
	}

	livada.setPoint(801, sf::Vector2f(801, 600.f));
	livada.setPoint(802, sf::Vector2f(0, 600.f));
	livada.setFillColor(sf::Color(0, 153, 2));
	adresa->draw(livada);

	sf::ConvexShape stabljika(8);
	stabljika.setPoint(0, sf::Vector2f(420.f, 360.f));
	stabljika.setPoint(1, sf::Vector2f(440.f, 360.f));
	stabljika.setPoint(2, sf::Vector2f(440.f, 370.f));
	stabljika.setPoint(3, sf::Vector2f(435.f, 420.f));
	stabljika.setPoint(4, sf::Vector2f(440.f, 470.f));
	stabljika.setPoint(5, sf::Vector2f(420.f, 470.f));
	stabljika.setPoint(6, sf::Vector2f(415.f, 420.f));
	stabljika.setPoint(7, sf::Vector2f(420.f, 370.f));
	stabljika.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(stabljika);

	//LISTOVI
	sf::ConvexShape d_list(4);
	d_list.setPoint(0, sf::Vector2f(430.f, 390.f));
	d_list.setPoint(1, sf::Vector2f(455.f, 410.f));
	d_list.setPoint(2, sf::Vector2f(495.f, 360.f));
	d_list.setPoint(3, sf::Vector2f(465.f, 425.f));
	d_list.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(d_list);

	sf::ConvexShape l_list(4);
	l_list.setPoint(0, sf::Vector2f(360.f, 360.f));
	l_list.setPoint(1, sf::Vector2f(400.f, 410.f));
	l_list.setPoint(2, sf::Vector2f(425.f, 390.f));
	l_list.setPoint(3, sf::Vector2f(390.f, 425.f));
	l_list.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(l_list);


	//GLAVICA
	sf::CircleShape glava(35.f);
	glava.setPosition(400.f, 295.f);
	glava.setFillColor(sf::Color(122, 118, 1));
	glava.setOutlineThickness(25.f);
	glava.setOutlineColor(sf::Color(255, 248, 43));
	adresa->draw(glava);

	//LICE
	sf::CircleShape usta(15.f);
	usta.setPosition(412.f, 332.f);
	usta.setFillColor(sf::Color(0, 0, 0));
	adresa->draw(usta);

	sf::RectangleShape d_oko1(sf::Vector2f(16.f, 4.f));
	d_oko1.setPosition(445.f, 310.f);
	d_oko1.rotate(45.f);
	d_oko1.setFillColor(sf::Color(0, 0, 0));
	adresa->draw(d_oko1);

	sf::RectangleShape d_oko2(sf::Vector2f(16.f, 4.f));
	d_oko2.setPosition(445.f, 310.f);
	d_oko2.rotate(-45.f);
	d_oko2.setFillColor(sf::Color(0, 0, 0));
	adresa->draw(d_oko2);

	sf::RectangleShape l_oko1(sf::Vector2f(16.f, 4.f));
	l_oko1.setPosition(415.f, 313.f);
	l_oko1.rotate(135.f);
	l_oko1.setFillColor(sf::Color(0, 0, 0));
	adresa->draw(l_oko1);

	sf::RectangleShape l_oko2(sf::Vector2f(16.f, 4.f));
	l_oko2.setPosition(415.f, 313.f);
	l_oko2.rotate(-135.f);
	l_oko2.setFillColor(sf::Color(0, 0, 0));
	adresa->draw(l_oko2);

	//	sf::Clock clock;
	//	bool flip = false;
	//	while (adresa->isOpen())
	//	{
	//		if ((clock.getElapsedTime().asSeconds() > 1.0f) && flip)
	//		{
	//			stabljika.setPoint(3, sf::Vector2f(435.f, 420.f));
	//			stabljika.setPoint(6, sf::Vector2f(415.f, 420.f));
	//			adresa->draw(stabljika);
	//			flip = false;
	//		}
	//		else if ((clock.getElapsedTime().asSeconds() > 1.0f) && !flip)
	//		{
	//			stabljika.setPoint(3, sf::Vector2f(445.f, 420.f));
	//			stabljika.setPoint(6, sf::Vector2f(425.f, 420.f));
	//			adresa->draw(stabljika);
	//			flip = true;
	//		}
	//		clock.restart();
	//	}

}
