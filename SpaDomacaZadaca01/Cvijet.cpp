#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window) : prozor(window)
{
	stoperica.restart();
	genStabljika();
	genList();
	genTucak();
	genLatice();
	genSunce();
}




void Cvijet::draw()
{
	
	prozor.draw(stabljika);
	prozor.draw(latice);
	prozor.draw(tucak);
	prozor.draw(list);

	vrijeme = stoperica.getElapsedTime();

	
	if (vrijeme.asSeconds()>=2)
	{
		sunce.setRadius(80);
		stoperica.restart();
	}

	else if (vrijeme.asSeconds()>=1)
	{
		sunce.setRadius(60);
	}

	prozor.draw(sunce);
}

void Cvijet::genSunce()
{
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(600, 60);
	sunce.setRadius(80);


}

void Cvijet::genStabljika()
{
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setSize(sf::Vector2f(15, 150));
	stabljika.setPosition(400, 350);
}

void Cvijet::genList()
{
	list.setFillColor(sf::Color::Green);
	list.setPointCount(8);
	list.setPoint(0, sf::Vector2f(1,1));
	list.setPoint(1, sf::Vector2f(1.5f, 0.5f));
	list.setPoint(2, sf::Vector2f(2, 0));
	list.setPoint(3, sf::Vector2f(2.5f, 0.5f));
	list.setPoint(4, sf::Vector2f(3, 1));
	list.setPoint(5, sf::Vector2f(2.5f, 1.5f));
	list.setPoint(6, sf::Vector2f(2, 2));
	list.setPoint(7, sf::Vector2f(1.5f, 1.5f));
	list.setScale(sf::Vector2f(85, 20));
	list.setPosition(240, 390);
}

void Cvijet::genTucak()
{
	tucak.setFillColor(sf::Color::Yellow);
	tucak.setRadius(20);
	tucak.setPosition(390, 280);
}

void Cvijet::genLatice()
{
	latice.setFillColor(sf::Color::Magenta);
	latice.setRadius(50);
	latice.setPosition(360, 250);
}



