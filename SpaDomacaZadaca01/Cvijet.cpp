#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->xwindow = window;
}


void Cvijet::draw()
{

	sf::CircleShape Latice(50.f);
	Latice.setFillColor(sf::Color(80, 0, 160));
	Latice.setPosition(100.f, 100.f);


	sf::CircleShape UnutarnjiKrug(30.f);
	UnutarnjiKrug.setFillColor(sf::Color(255, 220, 0));
	UnutarnjiKrug.setPosition(120.f, 120.f);


	sf::RectangleShape Linija(sf::Vector2f(4.f, 150.f));
	//Zelena
	Linija.setFillColor(sf::Color(0, 210, 130));
	Linija.setPosition(148.f, 200.f);


	sf::ConvexShape List;
	List.setPointCount(4);
	List.setPoint(0, sf::Vector2f(148.f, 290.f));
	List.setPoint(1, sf::Vector2f(110.f, 275.f));
	List.setPoint(2, sf::Vector2f(135.f, 260.f));
	List.setPoint(3, sf::Vector2f(148.f, 290.f));
	List.setFillColor(sf::Color(0, 210, 130));


	sf::ConvexShape List2;
	List2.setPointCount(4);
	List2.setPoint(0, sf::Vector2f(152.f, 290.f));
	List2.setPoint(1, sf::Vector2f(190.f, 275.f));
	List2.setPoint(2, sf::Vector2f(165.f, 260.f));
	List2.setPoint(3, sf::Vector2f(152.f, 290.f));
	List2.setFillColor(sf::Color(0, 210, 130));


	sf::CircleShape Sunce(30.f);
	Sunce.setFillColor(sf::Color(255, 210, 0));
	Sunce.setPosition(400.f, 0.f);


	xwindow->draw(Latice);
	xwindow->draw(UnutarnjiKrug);
	xwindow->draw(Linija);
	xwindow->draw(List);
	xwindow->draw(List2);
	xwindow->draw(Sunce);

	drawZrake();
}



void Cvijet::drawZrake()
{
	if (i < 150) {
		sf::RectangleShape Zraka1(sf::Vector2f(2, i + 20));
		Zraka1.setFillColor(sf::Color(255, 255, 0));
		Zraka1.setPosition(395.f, 40.f);
		Zraka1.rotate(60.f);


		sf::RectangleShape Zraka2(sf::Vector2f(2, i + 5));
		Zraka2.setFillColor(sf::Color(255, 255, 0));
		Zraka2.setPosition(390.f, 20.f);
		Zraka2.rotate(60.f);

		sf::RectangleShape Zraka3(sf::Vector2f(2, i));
		Zraka3.setFillColor(sf::Color(255, 255, 0));
		Zraka3.setPosition(400.f, 60.f);
		Zraka3.rotate(60.f);

		xwindow->draw(Zraka1);
		xwindow->draw(Zraka2);
		xwindow->draw(Zraka3);
		i++;
	}
	else {
		i = 0;
	}

}
