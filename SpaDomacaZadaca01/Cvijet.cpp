#include "Cvijet.h"

void Cvijet::pozicijaStabiljka(float x, float y)
{
	stabiljka.setPosition(cvijet.getPosition());
	stabiljka.move(cvijet.getRadius() - ((cvijet.getRadius() / 3) / 2), cvijet.getRadius() * 2 + cvijet.getRadius() / 2);
	dimenzijeListica(x, y);

}


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	window->draw(cvijet);
	window->draw(sunce);
	window->draw(stabiljka);
	window->draw(listic);

}

void Cvijet::RadiusSunca(float radius)
{
	sunce.setRadius(radius);
	sunce.setFillColor(sf::Color::Yellow);
}

void Cvijet::RadiusCvijeta(float radius)
{
	cvijet.setRadius(radius);
	cvijet.setFillColor(sf::Color::Green);
	dimenzijeStabiljka(radius / 3, radius * 4);
	cvijet.setOutlineColor(sf::Color::Red);
	cvijet.setOutlineThickness(radius / 2);
}

void Cvijet::pozicijaSunca(float x, float y)
{
	sunce.setPosition(x, y);
}

void Cvijet::pozicijaCvijeta(float x, float y)
{
	cvijet.setPosition(x, y);
	pozicijaStabiljka(x, y);

}

void Cvijet::dimenzijeStabiljka(float x, float y)
{
	stabiljka.setSize(sf::Vector2f(x, y));
	stabiljka.setFillColor(sf::Color::Green);

}

void Cvijet::dimenzijeListica(float x, float y)
{

	float sirina = stabiljka.getSize().x;
	float visina = stabiljka.getSize().y;
	float helperx = stabiljka.getPosition().x + sirina;
	float helpery = stabiljka.getPosition().y + visina / 2;
	listic.setFillColor(sf::Color::Green);
	listic.setPointCount(4);
	listic.setPoint(0, sf::Vector2f(helperx, helpery));
	listic.setPoint(1, sf::Vector2f(helperx + sirina * 4, helpery - visina / 5));
	listic.setPoint(2, sf::Vector2f(helperx + sirina * 9, helpery - visina / 7));
	listic.setPoint(3, sf::Vector2f(helperx + sirina * 8, helpery + visina / 15));


}
