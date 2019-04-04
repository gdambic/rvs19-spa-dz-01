#include "Cvijet.h"
#include <Windows.h>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window_class = window;
}

void Cvijet::draw()
{
	//nebo kao pozadina
	sf::RectangleShape sky(sf::Vector2f(800, 400));
	sky.setFillColor(sf::Color(80, 185, 255));

	//trava
	sf::RectangleShape grass(sf::Vector2f(800, 200));
	grass.setFillColor(sf::Color(155, 255, 80));
	grass.setPosition(0, 400);

	//stabljika
	sf::RectangleShape stem(sf::Vector2f(12.f, 200.f));
	stem.setFillColor(sf::Color::Green);
	stem.setPosition(285.f, 230.f);

	//tuèak cvijeta
	sf::CircleShape flower_pestle(40.f);
	sf::CircleShape small_pestle(30.f);
	flower_pestle.setFillColor(sf::Color(255, 170, 30));
	small_pestle.setFillColor(sf::Color(255, 255, 180));
	flower_pestle.setPosition(250.f, 150.f);
	small_pestle.setPosition(260.f, 160.f);

	//latice cvijeta
	sf::ConvexShape petals;
	petals.setPointCount(12);
	petals.setPoint(0, sf::Vector2f(0.f, 50.f));
	petals.setPoint(1, sf::Vector2f(50.f, 50.f));
	petals.setPoint(2, sf::Vector2f(75.f, 0.f));
	petals.setPoint(3, sf::Vector2f(100.f, 50.f));
	petals.setPoint(4, sf::Vector2f(150.f, 50.f));
	petals.setPoint(5, sf::Vector2f(125.f, 100.f));
	petals.setPoint(6, sf::Vector2f(150.f, 150.f));
	petals.setPoint(7, sf::Vector2f(100.f, 150.f));
	petals.setPoint(8, sf::Vector2f(75.f, 200.f));
	petals.setPoint(9, sf::Vector2f(50.f, 150.f));
	petals.setPoint(10, sf::Vector2f(0.f, 150.f));
	petals.setPoint(11, sf::Vector2f(25.f, 100.f));
	petals.setPosition(217.f, 90.f);
	petals.setFillColor(sf::Color::Magenta);

	//sunce
	sf::CircleShape sun(80.f);
	sun.setFillColor(sf::Color::Yellow);
	sun.setPosition(720, -80);
	sf::RectangleShape ray1(sf::Vector2f(5.f, 80.f));
	ray1.setFillColor(sf::Color::Yellow);
	ray1.rotate(65.f);
	ray1.setPosition(700.f, 20.f);
	sf::RectangleShape ray2(sf::Vector2f(5.f, 50.f));
	ray2.setFillColor(sf::Color::Yellow);
	ray2.rotate(55.f);
	ray2.setPosition(725.f, 60.f);
	sf::RectangleShape ray3(sf::Vector2f(5.f, 80.f));
	ray3.setFillColor(sf::Color::Yellow);
	ray3.rotate(50.f);
	ray3.setPosition(780.f, 85.f);

	//listovi
	sf::ConvexShape leaf;
	leaf.setPointCount(5);
	leaf.setPoint(0, sf::Vector2f(5.f, 5.f));
	leaf.setPoint(1, sf::Vector2f(15.f, 5.f));
	leaf.setPoint(2, sf::Vector2f(18.f, 0.f));
	leaf.setPoint(3, sf::Vector2f(15.f, 10.f));
	leaf.setPoint(4, sf::Vector2f(5.f, 10.f));
	leaf.scale(3.f, 2.f);
	leaf.setPosition(280.f, 320.f);
	leaf.setFillColor(sf::Color::Green);

	//grm
	sf::CircleShape bush(70.f);
	bush.setFillColor(sf::Color::Yellow);

	window_class->draw(sky);
	window_class->draw(grass);
	window_class->draw(stem);
	window_class->draw(petals);
	window_class->draw(flower_pestle);
	window_class->draw(small_pestle);
	window_class->draw(sun);
	window_class->draw(ray1);
	window_class->draw(ray2);
	window_class->draw(ray3);
	window_class->draw(leaf);

	window_class->display();
}
