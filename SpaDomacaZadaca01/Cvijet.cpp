#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"

using namespace std;


Cvijet::Cvijet(sf::RenderWindow* adresa)
{
	this->adresa = adresa;
}

void Cvijet::drawNebo()
{
	sf::RectangleShape nebo(sf::Vector2f(1200.f, 720.f));
	nebo.setFillColor(sf::Color(10, 143, 245));
	adresa->draw(nebo);
}

void Cvijet::drawSunce(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB)
{
	sf::CircleShape sunce(radius);
	sunce.setPosition(position1, position2);
	sunce.setFillColor(sf::Color(fillR, fillG, fillB));
	sunce.setOutlineThickness(outline);
	sunce.setOutlineColor(sf::Color(outR, outG, outB));
	adresa->draw(sunce);
}

void Cvijet::drawCvijet(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB)
{
	sf::CircleShape mainFlower (radius);
	mainFlower.setPosition(position1, position2);
	mainFlower.setFillColor(sf::Color(fillR, fillG, fillB));
	mainFlower.setOutlineThickness(outline);
	mainFlower.setOutlineColor(sf::Color(outR, outG, outB));
	adresa->draw(mainFlower);

}

void Cvijet::drawOblak()
{
}



void Cvijet::drawLivada()
{
	sf::ConvexShape livada(4);
	livada.setPoint(0, sf::Vector2f(0.f, 400.f));
	livada.setPoint(1, sf::Vector2f(1200.f, 400.f));
	livada.setPoint(2, sf::Vector2f(1200.f, 720.f));
	livada.setPoint(3, sf::Vector2f(0.f, 720.f));
	livada.setFillColor(sf::Color(0, 153, 2));
	adresa->draw(livada);

}

void Cvijet::draw()
{
	//Nebo
	drawNebo();

	//SUNCE

	drawSunce(80.f, 1050.f, -20.f, 255, 255, 0,  10.f, 255, 255, 153);


	//LIVADA
	drawLivada();


	sf::ConvexShape stabljika(8);
	stabljika.setPoint(0, sf::Vector2f(420.f, 360.f));
	stabljika.setPoint(1, sf::Vector2f(440.f, 360.f));
	stabljika.setPoint(2, sf::Vector2f(440.f, 370.f));
	stabljika.setPoint(3, sf::Vector2f(435.f, 420.f));
	stabljika.setPoint(4, sf::Vector2f(440.f, 470.f));
	stabljika.setPoint(5, sf::Vector2f(420.f, 470.f));
	stabljika.setPoint(6, sf::Vector2f(415.f, 420.f));
	stabljika.setPoint(7, sf::Vector2f(420.f, 370.f));
	stabljika.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(stabljika);

	//LISTOVI
	sf::ConvexShape d_list(4);
	d_list.setPoint(0, sf::Vector2f(430.f, 390.f));
	d_list.setPoint(1, sf::Vector2f(455.f, 410.f));
	d_list.setPoint(2, sf::Vector2f(495.f, 360.f));
	d_list.setPoint(3, sf::Vector2f(465.f, 425.f));
	d_list.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(d_list);

	sf::ConvexShape l_list(4);
	l_list.setPoint(0, sf::Vector2f(360.f, 360.f));
	l_list.setPoint(1, sf::Vector2f(400.f, 410.f));
	l_list.setPoint(2, sf::Vector2f(425.f, 390.f));
	l_list.setPoint(3, sf::Vector2f(390.f, 425.f));
	l_list.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(l_list);


	//Cvijet1
	drawCvijet(20.f, 85.f, 358.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 127.f, 362.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 165.f, 340.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 170.f, 295.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 145.f, 260.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 100.f, 255.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 65.f, 280.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 60.f, 325.f, 255, 0, 127, 5.f, 204, 0, 204);

	drawCvijet(45.f, 90.f, 285.f, 51, 0, 102, 5.f, 153, 153, 255);

	//Cvijet2
	drawCvijet(20.f, 385.f, 358.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 427.f, 362.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 465.f, 340.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 470.f, 295.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 445.f, 260.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 400.f, 255.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 365.f, 280.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 360.f, 325.f, 51,0,102, 5.f, 153, 153, 255);

	drawCvijet(35.f, 400.f, 295.f, 255, 0, 127, 20.f, 204, 0, 204);





	//Cvijet3
	drawCvijet(20.f, 685.f, 358.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 727.f, 362.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 765.f, 340.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 770.f, 295.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 745.f, 260.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 700.f, 255.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 665.f, 280.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 660.f, 325.f, 255, 0, 127, 5.f, 204, 0, 204);

	drawCvijet(45.f, 690.f, 285.f, 51, 0, 102, 5.f, 153, 153, 255);


	//Oblak
	sf::CircleShape oblak(35.f);
	sf::Vector2f oblakPozicija(140.f, 30.f);
	oblak.setRadius(30.f);
	oblak.setPosition(oblakPozicija);
	oblak.setFillColor(sf::Color(255, 255, 255));
	adresa->draw(oblak);
	//sf::CircleShape oblak2(35.f);
	//oblak2.setPosition(100.f, 30.f);
	//oblak2.setFillColor(sf::Color(255, 255, 255));
	//adresa->draw(oblak2);

	

	float xOs = 3;
	float yOs = 3;

	sf::Clock clock; // starts the clock
	
	
	sf::Time elapsed= clock.getElapsedTime();
	double t1 = elapsed.asSeconds();
	while (t1) {
		oblakPozicija.x += xOs;
		oblakPozicija.y += yOs;
		oblak.setPosition(oblakPozicija);
	}

	clock.restart();

	







}


