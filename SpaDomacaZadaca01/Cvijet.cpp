#include "Cvijet.h"
#include<iostream>

Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->mainwindow = window;
}

void Cvijet::draw()
{
	sf::CircleShape flower(50.f);
	flower.setFillColor(sf::Color(255, 255, 0));
	flower.setPosition(200, 200);
	flower.setOutlineThickness(40.f);
	flower.setOutlineColor(sf::Color(255, 0, 0));

	sf::RectangleShape flowerStem(sf::Vector2f(8.f, 210.f));
	flowerStem.setFillColor(sf::Color(25, 230, 0));
	flowerStem.setPosition(245, 340);

	sf::RectangleShape grass(sf::Vector2f(800.f, 50.f));
	grass.setFillColor(sf::Color(0, 255, 0));
	grass.setPosition(0, 550);

	sf::ConvexShape leaf1;
	leaf1.setPointCount(6);
	leaf1.setFillColor(sf::Color(25, 230, 0));
	leaf1.setPoint(0, sf::Vector2f(250.f, 400.f));
	leaf1.setPoint(1, sf::Vector2f(280.f, 380.f));
	leaf1.setPoint(2, sf::Vector2f(310.f, 370.f));
	leaf1.setPoint(3, sf::Vector2f(340.f, 390.f));
	leaf1.setPoint(4, sf::Vector2f(310.f, 370.f));
	leaf1.setPoint(5, sf::Vector2f(280.f, 380.f));

	sf::ConvexShape leaf2;
	leaf2.setPointCount(6);
	leaf2.setFillColor(sf::Color(25, 230, 0));
	leaf2.setPoint(0, sf::Vector2f(250.f, 450.f));
	leaf2.setPoint(1, sf::Vector2f(280.f, 430.f));
	leaf2.setPoint(2, sf::Vector2f(310.f, 420.f));
	leaf2.setPoint(3, sf::Vector2f(340.f, 440.f));
	leaf2.setPoint(4, sf::Vector2f(310.f, 420.f));
	leaf2.setPoint(5, sf::Vector2f(280.f, 430.f));

	sf::CircleShape sun(120.f);
	sun.setFillColor(sf::Color(255, 255, 0));
	sun.setPosition(650, -100);

	sf::RectangleShape ray1(sf::Vector2f(30.f, 3.f));
	ray1.setPosition(660, 100);
	ray1.setFillColor(sf::Color(255, 255, 0));
	ray1.rotate(140.f);

	sf::RectangleShape ray2(sf::Vector2f(30.f, 3.f));
	ray2.setPosition(640, 65);
	ray2.setFillColor(sf::Color(255, 255, 0));
	ray2.rotate(155.f);

	sf::RectangleShape ray3(sf::Vector2f(30.f, 3.f));
	ray3.setPosition(630, 30);
	ray3.setFillColor(sf::Color(255, 255, 0));
	ray3.rotate(170.f);

	sf::RectangleShape ray4(sf::Vector2f(30.f, 3.f));
	ray4.setPosition(685, 130);
	ray4.setFillColor(sf::Color(255, 255, 0));
	ray4.rotate(127.f);

	sf::RectangleShape ray5(sf::Vector2f(30.f, 3.f));
	ray5.setPosition(720, 149);
	ray5.setFillColor(sf::Color(255, 255, 0));
	ray5.rotate(113.f);

	sf::RectangleShape ray6(sf::Vector2f(30.f, 3.f));
	ray6.setPosition(760, 158);
	ray6.setFillColor(sf::Color(255, 255, 0));
	ray6.rotate(103.f);


	//animacija

	animation = clock.getElapsedTime().asSeconds();
	animation /= 25;
	//std::cout << animation << std::endl;

	if (animation < 0.05)
	{
		sun.scale(1 + animation / 2, 1 + animation / 2);
		ray1.scale(1 + animation * 5, 1);
		ray2.scale(1 + animation * 2, 1);
		ray3.scale(1 + animation * 3, 1);
		ray4.scale(1 + animation * 4, 1);
		ray5.scale(1 + animation * 7, 1);
		ray6.scale(1 + animation * 2, 1);
	}
	else if (animation < 0.1)
	{
		animation2 = animation - 0.05;

		sun.scale(1.025 - animation2 / 2, 1.025 - animation2 / 2);
		ray1.scale(1.25 - animation2 * 5, 1);
		ray2.scale(1.1 - animation2 * 2, 1);
		ray3.scale(1.15 - animation2 * 3, 1);
		ray4.scale(1.2 - animation2 * 4, 1);
		ray5.scale(1.35 - animation2 * 7, 1);
		ray6.scale(1.1 - animation2 * 2, 1);
	}
	else
	{
		clock.restart();
	}


	mainwindow->draw(flower);
	mainwindow->draw(flowerStem);
	mainwindow->draw(grass);
	mainwindow->draw(leaf1);
	mainwindow->draw(leaf2);
	mainwindow->draw(sun);
	mainwindow->draw(ray1);
	mainwindow->draw(ray2);
	mainwindow->draw(ray3);
	mainwindow->draw(ray4);
	mainwindow->draw(ray5);
	mainwindow->draw(ray6);
}
