#include "Cvijet.h"

//KONSTRUKTOR
Cvijet::Cvijet(sf::RenderWindow *prozor)
{
	this->prozor = prozor;
}

//DEKONSTRUKTOR
Cvijet::~Cvijet() { }

//NACRTAJ CVIJET
void Cvijet::draw()
{
	prozor->draw(oblikReceptaculum());
	prozor->draw(oblikStabiljka());
	prozor->draw(oblikSepala());
}

//GLAVNI KRUG
sf::CircleShape Cvijet::oblikReceptaculum()
{
	sf::CircleShape receptaculum(40.f);
	receptaculum.setFillColor(sf::Color::Yellow);
	receptaculum.setOutlineThickness(25.f);
	receptaculum.setOutlineColor(sf::Color::Red);
	receptaculum.setPosition(70.f, 50.f);

	return receptaculum;
}

//STABILJKA
sf::RectangleShape Cvijet::oblikStabiljka()
{
	sf::RectangleShape ravnaLinija(sf::Vector2f(150.f, 5.f));
	ravnaLinija.rotate(90.f);
	ravnaLinija.setFillColor(sf::Color::Green);
	ravnaLinija.setPosition(110.f, 155.f);

	return ravnaLinija;
}

//LIST CVIJETA
sf::ConvexShape Cvijet::oblikSepala()
{
	sf::ConvexShape poligon;
	poligon.setPointCount(5);
	poligon.setPoint(0, sf::Vector2f(0.f, 0.f));
	poligon.setPoint(1, sf::Vector2f(30.f, 10.f));
	poligon.setPoint(2, sf::Vector2f(60.f, 20.f));
	poligon.setPoint(3, sf::Vector2f(30.f, 60.f));
	poligon.setPoint(4, sf::Vector2f(0.f, 30.f));
	poligon.setFillColor(sf::Color::Green);
	poligon.setPosition(110.f, 182.f);


	return poligon;
}
