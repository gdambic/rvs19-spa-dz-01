#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	set_pupoljak();
	set_sjemenka();
	set_list();
	set_stabiljka();
	set_livada();
	set_sunce();
	
}

void Cvijet::set_pupoljak()
{
	//Pupoljak
	sf::CircleShape krug(70.f, 12);
	krug.setFillColor(sf::Color(222, 138, 13));
	krug.setPosition(100.f, 80.f);
	krug.setOutlineColor(sf::Color(255, 255, 0));
	krug.setOutlineThickness(10.f);
	this->pupoljak = krug;
}

void Cvijet::set_sjemenka()
{
	//Sjemenka
	sf::CircleShape sjemenka(20.f, 8);
	sjemenka.setFillColor(sf::Color(46, 30, 15));
	sjemenka.setPosition(150.f, 130.f);
	this->sjemenka = sjemenka;
}

void Cvijet::set_list()
{
	//List
	sf::CircleShape triangle(40, 4);
	triangle.setFillColor(sf::Color(15, 245, 5));
	triangle.setPosition(165.f, 230.f);
	triangle.scale(sf::Vector2f(1.15, 0.5));
	triangle.rotate(48.f);
	this->list[0] = triangle;

	sf::CircleShape triangleP(40, 4);
	triangleP.setFillColor(sf::Color(15, 245, 5));
	triangleP.setPosition(190.f, 290.f);
	triangleP.scale(sf::Vector2f(1.25, 0.5));
	triangleP.rotate(-45.f);
	this->list[1] = triangleP;
}

void Cvijet::set_stabiljka()
{
	//Stabiljka
	sf::Vector2f v(14.f, 330.f);
	sf::RectangleShape stabiljka;
	stabijka.setFillColor(sf::Color(10, 255, 5));
	stabijka.setSize(v);
	stabijka.setRotation(-18.f);
	stabijka.setPosition(180.f, 228.f);
	this->stabijka = stabijka;
}

void Cvijet::set_livada()
{
	//Livada
	sf::Vector2f l(800.f, 200.f);
	sf::Texture liv;
	sf::RectangleShape livada;
	livada.setFillColor(sf::Color(25, 200, 30));
	livada.setSize(l);
	livada.setPosition(0.f, 500.f);
	this->livada = livada;

}

void Cvijet::set_sunce()
{
	//Sunce
	sf::Clock clock;
	sf::CircleShape sunce(60.f, 12);
	sunce.setFillColor(sf::Color(252, 212, 64));
	sunce.setPosition(600.f, 20.f);
	this->sunce = sunce;
}

void Cvijet::draw(sf::RenderWindow* window)
{
	window->draw(this->pupoljak);
	window->draw(this->stabijka);
	window->draw(this->sjemenka);
	window->draw(this->livada);
	window->draw(this->list[0]);
	window->draw(this->list[1]);
	window->draw(this->sunce);
	
}
