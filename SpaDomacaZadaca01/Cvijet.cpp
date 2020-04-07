#include "Cvijet.h"
#include <SFML/Graphics.hpp>
using namespace std;

void Cvijet::set_trokut(sf::ConvexShape& trokut, sf::Vector2f point0, sf::Vector2f point1, sf::Vector2f point2, float rotation, sf::Vector2f origin, sf::Vector2f position, sf::Color boja)
{
	trokut.setPointCount(3);
	trokut.setPoint(0, point0);
	trokut.setPoint(1, point1);
	trokut.setPoint(2, point2);
	trokut.setFillColor(boja);
	trokut.setRotation(rotation);
	trokut.setOrigin(origin);
	trokut.setPosition(position);
}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{

	//STABLJIKA
	stabljika.setSize(sf::Vector2f(7.f, 335.f));
	stabljika.setFillColor(sf::Color(100, 250, 50, 255));
	sf::Rect <float> sizestabljika = stabljika.getGlobalBounds();
	stabljika.setOrigin(sf::Vector2f(sizestabljika.width / 2, sizestabljika.height / 2));
	stabljika.setPosition(sf::Vector2f(400, 430));

	window->draw(stabljika);

	//LIST

	set_trokut(list,
		sf::Vector2f(0.f, 350.f),
		sf::Vector2f(100.f, 50.f),
		sf::Vector2f(100.f, 200.f),
		180,
		sf::Vector2f(100.f, 200.f),
		sf::Vector2f(400, 450),
		sf::Color(100, 250, 50, 255));

	window->draw(list);


	//LATICE LIJEVE I DESNE

	set_trokut(laticad,
		sf::Vector2f(0.f, 0.f),      // point0
		sf::Vector2f(25.f, 3.f),     // point1
		sf::Vector2f(60.f, 35.f),    // point2
		0,                           // rotation
		sf::Vector2f(85.f, 60.f),    // origin
		sf::Vector2f(400, 170),      // position
		sf::Color(0, 50, 255, 150)); // color


	set_trokut(latical, 
		sf::Vector2f(0.f, 0.f), 
		sf::Vector2f(3.f, 25.f), 
		sf::Vector2f(35.f, 60.f),
		0, 
		sf::Vector2f(60.f, 85.f), 
		sf::Vector2f(400, 170), 
		sf::Color(0, 50, 255, 150));

	for (int i = 0; i < 96; i++)
	{

		if (i < 24) {

			laticad.setOrigin(sf::Vector2f(65.f, 40.f));
			latical.setOrigin(sf::Vector2f(40.f, 65.f));

			if (i % 2) {
				laticad.setFillColor(sf::Color(255, 255, 255, 150));
				latical.setFillColor(sf::Color(255, 255, 255, 150));
			}
			else {
				laticad.setFillColor(sf::Color(255, 255, 255, 225));
				latical.setFillColor(sf::Color(255, 255, 255, 225));
			}
		}


		else if (i<48) {

			laticad.setOrigin(sf::Vector2f(85.f, 60.f));
			latical.setOrigin(sf::Vector2f(60.f, 85.f));


			if (i % 2) {
				laticad.setFillColor(sf::Color(0, 75, 255, 150));
				latical.setFillColor(sf::Color(0, 75, 255, 150));
			}
			else {
				laticad.setFillColor(sf::Color(0, 75, 255, 255));
				latical.setFillColor(sf::Color(0, 75, 255, 255));
			}
		}

		else if (i < 72) {

			laticad.setOrigin(sf::Vector2f(95.f, 70.f));
			latical.setOrigin(sf::Vector2f(70.f, 95.f));

			if (i % 2) {
				laticad.setFillColor(sf::Color(0, 200, 255, 150));
				latical.setFillColor(sf::Color(0, 200, 255, 150));
			}
			else {
				laticad.setFillColor(sf::Color(0, 255, 255, 225));
				latical.setFillColor(sf::Color(0, 255, 255, 225));
			}
		}

		else if (i < 96) {

			laticad.setOrigin(sf::Vector2f(115.f, 90.f));
			latical.setOrigin(sf::Vector2f(90.f, 115.f));

			if (i % 2) {
				laticad.setFillColor(sf::Color(0, 225, 255, 50));
				latical.setFillColor(sf::Color(0, 225, 255, 50));
			}
			else {
				laticad.setFillColor(sf::Color(0, 225, 255, 100));
				latical.setFillColor(sf::Color(0, 225, 255, 100));
			}

		}

		laticad.rotate(15);
		window->draw(laticad);
		latical.rotate(-15);
		window->draw(latical);
	}

	//TUCAK

	float r = 10;
	tucak.setRadius(r);
	tucak.setFillColor(sf::Color(255, 255, 0, 200));
	tucak.setOrigin(tucak.getRadius(), tucak.getRadius());
	tucak.setPosition(sf::Vector2f(400, 170));

	window->draw(tucak);

	// ANIMACIJA
	
		sf::Time elapsed1 = frameClock.getElapsedTime();

		if (elapsed1.asMilliseconds() >= 1000) {

			r += 3;
			tucak.setRadius(r);
			tucak.setOrigin(tucak.getRadius(), tucak.getRadius());
			tucak.setPosition(sf::Vector2f(400, 170));
			window->draw(tucak);

			if(elapsed1.asMilliseconds() >= 2000) frameClock.restart();
		}
	
}