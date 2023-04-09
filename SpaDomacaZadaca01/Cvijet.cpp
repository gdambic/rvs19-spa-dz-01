#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& w)
{
	p = &w;
}

void Cvijet::crtaj()
{
	sf::Vector2f PozicijaKorijen;
	sf::Vector2f PozicijaSunce;
	PozicijaSunce.x = 20;
	PozicijaSunce.y = 10;

	PozicijaKorijen.x = 383;
	PozicijaKorijen.y = 318;

	//VEKTOR
	Krug.setRadius(100);
	Krug.setPosition(300, 120);
	Krug.setFillColor(sf::Color(100, 50, 30));
	//KRUG
	KrugDva.setRadius(85);
	KrugDva.setPosition(316, 135);
	KrugDva.setFillColor(sf::Color(255, 255, 224));
	//KRUG DVA

	Korijen.setSize(sf::Vector2f(30, 250));
	Korijen.setPosition(PozicijaKorijen);
	Korijen.setFillColor(sf::Color(128, 128, 0));
	//Korijen

	sunce.setPosition(PozicijaSunce);
	sunce.setFillColor(sf::Color(255, 255, 51));
	sunce.setRadius(20);

	//sunce

	list.setPointCount(3);
	list.setPoint(0, sf::Vector2f(410, 400));
	list.setPoint(1, sf::Vector2f(410, 500));
	list.setPoint(2, sf::Vector2f(650, 300));
	list.setFillColor(sf::Color(0, 100, 0));
	//list

	p->draw(Krug);
	p->draw(KrugDva);
	p->draw(Korijen);
	p->draw(list);
	p->draw(sunce);
}
