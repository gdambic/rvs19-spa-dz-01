#include "Cvijet.h"





Cvijet::Cvijet(sf::RenderWindow* windowAdress)
{
	this->windowAdress = windowAdress;
	skalar = 1;
	
}

void Cvijet::designGlava()
{
	glava.setRadius(50.f);
	glava.setFillColor(sf::Color(150, 50, 250));
	glava.setOutlineThickness(40.f);
	glava.setOutlineColor(sf::Color(250, 150, 100));
	glava.setPosition(350.f, 200.f);

}

void Cvijet::designStabljika()
{
	stabljika.setSize(sf::Vector2f(10.f, 220.f));
	stabljika.setPosition(395, 340);
	stabljika.setFillColor(sf::Color(101, 67, 33));
}

void Cvijet::designList()
{
	list.setPointCount(3);

	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(80.f, -10.f));
	list.setPoint(2, sf::Vector2f(-60.f, 50.f));

	list.setPosition(460.f, 400.f);

	list.setFillColor(sf::Color(0, 168, 107));
}

void Cvijet::designSunce()
{
	sunce.setRadius(15.f);
	sunce.setFillColor(sf::Color::Yellow);
	
}

void Cvijet::sunceAnimacija()
{
	
	if (clock.getElapsedTime().asSeconds() > 0.05f) {
		if(sunce.getGlobalBounds().width < 100.0f && skalar == 1){ 
			sunce.scale(1.05f, 1.05f); 
			
		}
		else if (sunce.getGlobalBounds().width >= 100.0f || skalar == 0) {
			sunce.scale(0.95f, 0.95f);
			skalar = 0;
			if (sunce.getGlobalBounds().width < 20.0f) {
				skalar = 1;
			}
			
		}
		

		clock.restart();
	}
	

	
}


void Cvijet::draw()
{
	

	Cvijet::designGlava();
	windowAdress->draw(glava);

	Cvijet::designStabljika();
	windowAdress->draw(stabljika);

	Cvijet::designList();
	windowAdress->draw(list);

	Cvijet::designSunce();
	windowAdress->draw(sunce);

	Cvijet::sunceAnimacija();

}
