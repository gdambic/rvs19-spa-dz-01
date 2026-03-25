#include "Cvijet.h"

// tulipetchebest

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	this->sunrised = false;
	sun1 = sf::CircleShape(50.f);
	sun1.setPosition(-100.f, 200.f);

	fond.setPointCount(4);
	fond.setPoint(0, sf::Vector2f(0.f, 0.f));
	fond.setPoint(1, sf::Vector2f(0.f, 600.f));
	fond.setPoint(2, sf::Vector2f(800.f, 600.f));
	fond.setPoint(3, sf::Vector2f(800.f, 0.f));

	middle.setPointCount(4);
	middle.setPoint(0, sf::Vector2f(349.f, 129.f));
	middle.setPoint(1, sf::Vector2f(419.f, 096.f));
	middle.setPoint(2, sf::Vector2f(492.f, 138.f));
	middle.setPoint(3, sf::Vector2f(419.f, 200.f));

	petal1.setPointCount(7);
	petal1.setPoint(0, sf::Vector2f(314.f, 308.f));
	petal1.setPoint(1, sf::Vector2f(292.f, 231.f));
	petal1.setPoint(2, sf::Vector2f(301.f, 148.f));
	petal1.setPoint(3, sf::Vector2f(315.f, 118.f));
	petal1.setPoint(4, sf::Vector2f(349.f, 129.f));
	petal1.setPoint(5, sf::Vector2f(420.f, 194.f));
	petal1.setPoint(6, sf::Vector2f(363.f, 240.f));

	petal2.setPointCount(9);
	petal2.setPoint(0, sf::Vector2f(314.f, 308.f));
	petal2.setPoint(1, sf::Vector2f(363.f, 240.f));
	petal2.setPoint(2, sf::Vector2f(420.f, 194.f));
	petal2.setPoint(3, sf::Vector2f(489.f, 138.f));
	petal2.setPoint(4, sf::Vector2f(521.f, 133.f));
	petal2.setPoint(5, sf::Vector2f(533.f, 167.f));
	petal2.setPoint(6, sf::Vector2f(500.f, 300.f));
	petal2.setPoint(7, sf::Vector2f(461.f, 334.f));
	petal2.setPoint(8, sf::Vector2f(404.f, 350.f));

	tige.setPointCount(4);
	tige.setPoint(0, sf::Vector2f(404.f, 350.f));
	tige.setPoint(1, sf::Vector2f(414.f, 347.f));
	tige.setPoint(2, sf::Vector2f(414.f, 601.f));
	tige.setPoint(3, sf::Vector2f(404.f, 601.f));

	feuille1.setPointCount(4);
	feuille1.setPoint(0, sf::Vector2f(412.f, 566.f));
	feuille1.setPoint(1, sf::Vector2f(503.f, 472.f));
	feuille1.setPoint(2, sf::Vector2f(573.f, 453.f));
	feuille1.setPoint(3, sf::Vector2f(532.f, 526.f));

	feuille2.setPointCount(4);
	feuille2.setPoint(0, sf::Vector2f(402.f, 566.f));
	feuille2.setPoint(1, sf::Vector2f(334.f, 477.f));
	feuille2.setPoint(2, sf::Vector2f(245.f, 451.f));
	feuille2.setPoint(3, sf::Vector2f(300.f, 515.f));

	middle.setFillColor(sf::Color(184, 20, 91));
	petal1.setFillColor(sf::Color(230, 33, 118));
	petal2.setFillColor(sf::Color(233, 53, 131));
	tige.setFillColor(sf::Color(128, 222, 125));
	feuille1.setFillColor(sf::Color(96, 214, 92));
	feuille2.setFillColor(sf::Color(49, 180, 45));
	fond.setFillColor(sf::Color(179, 235, 242));
	sun1.setFillColor(sf::Color(253, 253, 150));

}

void Cvijet::draw()
{
	sf::Color day = sf::Color(179, 235, 242);
	sf::Color night = sf::Color(3, 34, 76);

	float chrono = clock.getElapsedTime().asSeconds();
	if (chrono > 0.03) {
			clock.restart();
			float oldx = sun1.getPosition().x;
			float oldy = sun1.getPosition().y;
			if (oldx > 900)
			{
				sun1.setPosition(-100.f, 200.f);
				if (sun1.getFillColor() == sf::Color(253, 253, 150))
				{
					sun1.setFillColor(sf::Color(244, 254, 254));
					fond.setFillColor(night);
				}
				else
				{
					sun1.setFillColor(sf::Color(253, 253, 150));
					fond.setFillColor(day);
				}
				sunrised = false;
			}
			else
			{
				if (oldy < 50 and oldy > 40)
					sunrised = true;
				if(not sunrised)
					sun1.setPosition(oldx + 10.f, oldy - 4.f);
				else
					sun1.setPosition(oldx + 10.f, oldy + 4.f);
			}
	}

	(*window).draw(fond);
	(*window).draw(sun1);
	(*window).draw(middle);
	(*window).draw(petal1);
	(*window).draw(petal2);
	(*window).draw(tige);
	(*window).draw(feuille1);
	(*window).draw(feuille2);
}