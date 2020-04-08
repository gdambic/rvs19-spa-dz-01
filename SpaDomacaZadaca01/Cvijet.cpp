#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->Window = window;
}

void Cvijet::drawSmallFlower()
{
	RectangleShape pozadina(Vector2f(800, 600));
	pozadina.setPosition(0, 0);
	sf::Texture texture;
	texture.loadFromFile("summer.jpg");
	pozadina.setTexture(&texture);
	Window->draw(pozadina);

	RectangleShape malaStabiljka(Vector2f(50, 6));
	malaStabiljka.setFillColor(sf::Color::Green);
	malaStabiljka.rotate(90);
	malaStabiljka.setPosition(300, 550);
	Window->draw(malaStabiljka);

	CircleShape maliTucak(10);
	maliTucak.setFillColor(sf::Color::Red);
	maliTucak.setOutlineColor(sf::Color::Yellow);
	maliTucak.setOutlineThickness(15);
	maliTucak.setPosition(287, 515);
	Window->draw(maliTucak);

	float udaljenost = 2 * 3.1415 / 28;//kut(udaljenost) izmedu svake latice

	for (int i = 1; i <= 28; i++)
	{
		CircleShape malaLatica(10);
		malaLatica.setRadius(5);
		malaLatica.setFillColor(sf::Color::Red);
		malaLatica.setOrigin(5 + (5 + 25) * sin(i * udaljenost), 5 + (5 + 25) * cos(i * udaljenost));
		malaLatica.setOutlineColor(sf::Color::Yellow);
		malaLatica.setOutlineThickness(1);
		malaLatica.setPosition(297, 525);

		Window->draw(malaLatica);
	}

	ConvexShape maliList1;
	maliList1.setPointCount(5);
	maliList1.setFillColor(sf::Color::Green);
	maliList1.setPosition(265, 580);
	maliList1.setPoint(0, Vector2f(0, 0));
	maliList1.setPoint(1, Vector2f(30, 18));
	maliList1.setPoint(2, Vector2f(30, 20));
	maliList1.setPoint(3, Vector2f(30, 30));
	maliList1.setPoint(4, Vector2f(0, 0));
	Window->draw(maliList1);

	ConvexShape maliList2;
	maliList2.setPointCount(5);
	maliList2.setFillColor(sf::Color::Green);
	maliList2.setPosition(330, 580);
	maliList2.setPoint(0, Vector2f(0, 0));
	maliList2.setPoint(1, Vector2f(-30, 18));
	maliList2.setPoint(2, Vector2f(-30, 20));
	maliList2.setPoint(3, Vector2f(-30, 30));
	maliList2.setPoint(4, Vector2f(0, 0));
	Window->draw(maliList2);

}

void Cvijet::drawMiddleFlower()
{
	RectangleShape pozadina(Vector2f(800, 600));
	pozadina.setPosition(0, 0);
	sf::Texture texture;
	texture.loadFromFile("summer.jpg");
	pozadina.setTexture(&texture);
	Window->draw(pozadina);

	RectangleShape srednjaStabiljka(Vector2f(75, 8));
	srednjaStabiljka.setFillColor(sf::Color::Green);
	srednjaStabiljka.rotate(90);
	srednjaStabiljka.setPosition(300, 525);
	Window->draw(srednjaStabiljka);

	CircleShape srednjiTucak(15);
	srednjiTucak.setFillColor(sf::Color::Red);
	srednjiTucak.setOutlineColor(sf::Color::Yellow);
	srednjiTucak.setOutlineThickness(28);
	srednjiTucak.setPosition(280, 470);
	Window->draw(srednjiTucak);

	float udaljenost = 2 * 3.1415 / 28;//kut(udaljenost) izmedu svake latice

	for (int i = 1; i <= 28; i++)
	{
		CircleShape srednjaLatica(12);
		srednjaLatica.setRadius(7);
		srednjaLatica.setFillColor(sf::Color::Red);
		srednjaLatica.setOrigin(10 + (10 + 40) * sin(i * udaljenost), 10 + (10 + 40) * cos(i * udaljenost));
		srednjaLatica.setOutlineColor(sf::Color::Yellow);
		srednjaLatica.setOutlineThickness(1);
		srednjaLatica.setPosition(298, 488);

		Window->draw(srednjaLatica);
	}

	ConvexShape srednjiList1;
	srednjiList1.setPointCount(5);
	srednjiList1.setFillColor(sf::Color::Green);
	srednjiList1.setPosition(250, 560);
	srednjiList1.setPoint(0, Vector2f(0, 0));
	srednjiList1.setPoint(1, Vector2f(48, 18));
	srednjiList1.setPoint(2, Vector2f(48, 20));
	srednjiList1.setPoint(3, Vector2f(48, 30));
	srednjiList1.setPoint(4, Vector2f(0, 0));
	Window->draw(srednjiList1);

	ConvexShape srednjiList2;
	srednjiList2.setPointCount(5);
	srednjiList2.setFillColor(sf::Color::Green);
	srednjiList2.setPosition(340, 560);
	srednjiList2.setPoint(0, Vector2f(0, 0));
	srednjiList2.setPoint(1, Vector2f(-48, 18));
	srednjiList2.setPoint(2, Vector2f(-48, 20));
	srednjiList2.setPoint(3, Vector2f(-48, 30));
	srednjiList2.setPoint(4, Vector2f(0, 0));
	Window->draw(srednjiList2);

}

void Cvijet::drawBigFlower()
{
	RectangleShape pozadina(Vector2f(800, 600 ));
	pozadina.setPosition(0, 0);
	sf::Texture texture;
	texture.loadFromFile("summer.jpg");
	pozadina.setTexture(&texture);
	Window->draw(pozadina);
	
	RectangleShape velikaStabiljka(Vector2f(100, 10));
	velikaStabiljka.setFillColor(sf::Color::Green);
	velikaStabiljka.rotate(90);
	velikaStabiljka.setPosition(300, 500);
	Window->draw(velikaStabiljka);

	CircleShape velikiTucak(20);
	velikiTucak.setFillColor(sf::Color::Red);
	velikiTucak.setOutlineColor(sf::Color::Yellow);
	velikiTucak.setOutlineThickness(40);
	velikiTucak.setPosition(275, 450);
	Window->draw(velikiTucak);

	float udaljenost = 2 * 3.1415 / 28;//kut(udaljenost) izmedu svake latice

	for (int i = 1; i <= 28; i++)
	{
		CircleShape velikaLatica(20);
		velikaLatica.setRadius(10);
		velikaLatica.setFillColor(sf::Color::Red);
		velikaLatica.setOrigin(10 + (10 + 55) * sin(i * udaljenost), 10 + (10 + 55) * cos(i * udaljenost));
		velikaLatica.setOutlineColor(sf::Color::Yellow);
		velikaLatica.setOutlineThickness(1);
		velikaLatica.setPosition(295, 470);

		Window->draw(velikaLatica);
	}

	ConvexShape velikiList1;
	velikiList1.setPointCount(5);
	velikiList1.setFillColor(sf::Color::Green);
	velikiList1.setPosition(225, 560);
	velikiList1.setPoint(0, Vector2f(0, 0));
	velikiList1.setPoint(1, Vector2f(65, 18));
	velikiList1.setPoint(2, Vector2f(65, 20));
	velikiList1.setPoint(3, Vector2f(65, 30));
	velikiList1.setPoint(4, Vector2f(0, 0));
	Window->draw(velikiList1);

	ConvexShape velikiList2;
	velikiList2.setPointCount(5);
	velikiList2.setFillColor(sf::Color::Green);
	velikiList2.setPosition(365, 560);
	velikiList2.setPoint(0, Vector2f(0, 0));
	velikiList2.setPoint(1, Vector2f(-65, 18));
	velikiList2.setPoint(2, Vector2f(-65, 20));
	velikiList2.setPoint(3, Vector2f(-65, 30));
	velikiList2.setPoint(4, Vector2f(0, 0));
	Window->draw(velikiList2);

}

void Cvijet::draw() 
{
	drawSmallFlower();

	CircleShape sunce(100);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(100, -100);
	Window->draw(sunce);

	ConvexShape zraka1; 
	zraka1.setPointCount(3);
	zraka1.setPoint(0, Vector2f( 0, 0));
	zraka1.setPoint(1, Vector2f( 100, -10));
	zraka1.setPoint(2, Vector2f( 100, 10));
	
	ConvexShape zraka2;
	zraka2.setPointCount(3);
	zraka2.setPoint(0, Vector2f(0, 0));
	zraka2.setPoint(1, Vector2f(-100, 10));
	zraka2.setPoint(2, Vector2f(-100, -10));

	ConvexShape zraka3;
	zraka3.setPointCount(3);
	zraka3.setPoint(0, Vector2f(0, 0));
	zraka3.setPoint(1, Vector2f(-100, 10));
	zraka3.setPoint(2, Vector2f(-100, -10));

	ConvexShape zraka4;
	zraka4.setPointCount(3);
	zraka4.setPoint(0, Vector2f(0, 0));
	zraka4.setPoint(1, Vector2f(-100, 10));
	zraka4.setPoint(2, Vector2f(-100, -10));

	ConvexShape zraka5;
	zraka5.setPointCount(3);
	zraka5.setPoint(0, Vector2f(0, 0));
	zraka5.setPoint(1, Vector2f(-100, 10));
	zraka5.setPoint(2, Vector2f(-100, -10));

	

	zraka1.setFillColor(sf::Color::Yellow);
	zraka2.setFillColor(sf::Color::Yellow);
	zraka3.setFillColor(sf::Color::Yellow);
	zraka4.setFillColor(sf::Color::Yellow);
	zraka5.setFillColor(sf::Color::Yellow);

	zraka1.rotate(-30);
	zraka2.rotate(30);
	zraka3.rotate(90);
	zraka4.rotate(0);
	zraka5.rotate(180);
	
	zraka1.setPosition(45, 100);
	zraka2.setPosition(355, 100);
	zraka3.setPosition(200, 180);
	zraka4.setPosition(390, 0);
	zraka5.setPosition(20, 0);

	Time counter = frameClock.getElapsedTime();
	Time stop = seconds(5.00f);
	Time stop1 = seconds(10.00f);
	Time stop2 = seconds(15.00f);
	Time stop3 = seconds(20.00f);
	Time stop4 = seconds(25.00f);
	cout << counter.asSeconds() << endl;
	if (counter >= stop)
	{
		Window->clear();
		drawMiddleFlower();
		sunce.setRadius(100);
		Window->draw(zraka1);
		Window->draw(zraka2);
		Window->draw(zraka3);
		Window->draw(zraka4);
		Window->draw(zraka5);
		Window->draw(sunce);
	}
	if (counter >= stop1)
	{
		Window->clear();
		drawBigFlower();
		sunce.setRadius(100);
		Window->draw(zraka1);
		Window->draw(zraka2);
		Window->draw(zraka3);
		Window->draw(zraka4);
		Window->draw(zraka5);
		Window->draw(sunce);
	}
	if (counter >= stop2)
	{
		Window->clear();
		drawMiddleFlower();
		sunce.setRadius(100);
		Window->draw(zraka1);
		Window->draw(zraka2);
		Window->draw(zraka3);
		Window->draw(zraka4);
		Window->draw(zraka5);
		Window->draw(sunce);
	}
	if (counter >= stop3)
	{
		Window->clear();
		drawSmallFlower();
		sunce.setRadius(100);
		Window->draw(sunce);
	}
	if (counter >= stop4)
	{
		Window->clear();
		sunce.setRadius(50);
		Window->draw(sunce);
		frameClock.restart();
	}

}
