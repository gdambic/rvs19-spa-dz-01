#include "Cvijet.h"
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::PostaviPozicije()
{
	stabiljka.setPosition(sf::Vector2f(388.f, 265.f));
	glava.setPosition(window->getSize().x / 2.f, 180);
}

void Cvijet::draw()
{
	ProvjeriTeksture(poz, "Pozadina.jpg");
	pozadina.setTexture(poz);
	this->window->draw(pozadina);

	stabiljka.setSize(sf::Vector2f(25.f, 290.f));
	ProvjeriTeksture(st, "dytx.jpg");
	stabiljka.setTexture(&st);
	this->window->draw(stabiljka);

	ProvjeriTeksture(ls, "dytx.jpg");
	listD.setTexture(&ls);
	listL.setTexture(&ls);
	KreirajDesniList(listD, 413.f, 380.f);
	KreirajDesniList(listD, 413.f, 514.f);
	KreirajLijeviList(listL, 388.f, 320.f);
	KreirajLijeviList(listL, 388.f, 450.f);

	ProvjeriTeksture(gl, "Glava2.jpg");
	glava.setTexture(&gl);
	glava.setRadius(100.f);
	glava.setTextureRect(sf::IntRect(26, 26, 140, 140));
	glava.setOrigin(100, 100);
	this->window->draw(glava);
}

void Cvijet::ProvjeriTeksture(sf::Texture& tx, std::string naziv)
{
	if (!tx.loadFromFile(naziv))
	{
		system("pause");
	}
}

void Cvijet::KreirajDesniList(sf::ConvexShape& list, float pozicijaX, float pozicijaY)
{
	list.setPosition(sf::Vector2f(pozicijaX, pozicijaY));
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(40.f, -40.f));
	list.setPoint(2, sf::Vector2f(120.f, -40.f));
	list.setPoint(3, sf::Vector2f(40.f, 10.f));
	this->window->draw(list);
}

void Cvijet::KreirajLijeviList(sf::ConvexShape& list, float pozicijaX, float pozicijaY)
{
	list.setPosition(sf::Vector2f(pozicijaX, pozicijaY));
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(-40.f, -40.f));
	list.setPoint(2, sf::Vector2f(-120.f, -40.f));
	list.setPoint(3, sf::Vector2f(-40.f, 10.f));
	this->window->draw(list);
}

void Cvijet::AnimacijaOkretanja()
{
	if (frameClock.getElapsedTime().asMilliseconds() > 1.f)
	{
		if (glava.getRotation() == 360.f)
		{
			rot = 1;
		}
		else {
			glava.setRotation(rot++);
		}

		frameClock.restart();
	}
}

void Cvijet::AnimacijaPomicanja()
{
	if (frameClock2.getElapsedTime().asMilliseconds() > 1.f)
	{
		if (!nazad)
		{
			listD.setRotation(rotD++);
			listL.setRotation(rotL--);
			glava.setPosition(window->getSize().x / 2.f, gla--);
			stabiljka.setPosition(sf::Vector2f(388.f, sta--));
			nazad = (rotD == 30.f) ? true : false;
		}

		if (nazad)
		{
			listD.setRotation(rotD--);
			listL.setRotation(rotL++);
			glava.setPosition(window->getSize().x / 2.f, gla++);
			stabiljka.setPosition(sf::Vector2f(388.f, sta++));
			nazad = (rotD == 0.f) ? false : true;
		}
		
		frameClock2.restart();
	}
}
