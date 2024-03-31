#include "Cvijet.h"
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	elapsed = frameClock.restart();
}

void Cvijet::draw()
{
	crtajNebo();
	crtajList();
	crtajStabljiku();
	crtajLatice();
	crtajShape();
	crtajGround();
	crtajSunce();

	//time management
	elapsed = frameClock.restart();
	scale += scaleSpeed * elapsed.asSeconds();
	if (scale >= 2.0f || scale <= 1.0f)
		scaleSpeed = -scaleSpeed;
}

void Cvijet::crtajNebo()
{
	//blue sky background
	sky.setSize(sf::Vector2f(800, 600));
	sky.setFillColor(sf::Color(153, 228, 255));
	window->draw(sky);
}
void Cvijet::crtajList()
{
	//the leaf
	leaf.setPointCount(5);
	leaf.setPoint(0, sf::Vector2f(140, 340));
	leaf.setPoint(1, sf::Vector2f(200, 310));
	leaf.setPoint(2, sf::Vector2f(230, 320));
	leaf.setPoint(3, sf::Vector2f(250, 350));
	leaf.setPoint(4, sf::Vector2f(190, 360));
	leaf.setFillColor(sf::Color(45, 128, 13));
	window->draw(leaf);
}
void Cvijet::crtajStabljiku()
{
	//the upper green part of the cvijet
	upperLine.setSize(sf::Vector2f(10.f, 200.f));
	upperLine.setFillColor(sf::Color(44, 150, 59));
	upperLine.setPosition(100.f, 150.f);
	upperLine.setRotation(-10);
	window->draw(upperLine);

	//the lower green part of the cvijet
	lowerLine.setSize(sf::Vector2f(10.f, 150.f));
	lowerLine.setFillColor(sf::Color(44, 150, 59));
	lowerLine.setPosition(135.f, 343.f);
	lowerLine.setRotation(10);
	window->draw(lowerLine);
}
void Cvijet::crtajLatice()
{
	//red circles
	for (int i = 0; i < 5; i++)
	{
		sf::CircleShape latice;
		latice.setRadius(30.f);
		latice.setFillColor(sf::Color(255, 0, 0));
		latice.setPosition(100, 100);
		latice.setRotation((i + 1) * 72.f);
		window->draw(latice);
	}
}
void Cvijet::crtajShape()
{
	//yellow circle
	shape.setRadius(35.f);
	shape.setFillColor(sf::Color(255, 255, 0));
	shape.setPosition(65.f, 65.f);
	window->draw(shape);
}
void Cvijet::crtajGround()
{
	//ground
	ground.setPointCount(4);
	ground.setPoint(0, sf::Vector2f(0, 450));
	ground.setPoint(1, sf::Vector2f(0, 600));
	ground.setPoint(2, sf::Vector2f(800, 600));
	ground.setPoint(3, sf::Vector2f(800, 475));
	ground.setFillColor(sf::Color(45, 128, 13));
	window->draw(ground);
}
void Cvijet::crtajSunce()
{
	//sunce
	sunce.setRadius(100.f);
	sunce.setFillColor(sf::Color(255, 255, 0));
	sunce.setPosition(750, -50);
	window->draw(sunce);

	//kinda animated zrake sunca
	for (auto i = 0; i < 7; i++)
	{
		sf::Vector2f size(10.f, (i % 2 == 0) ? 10.f : 7.f);
		zraka.setSize(size);
		zraka.setScale(1.f, 30 * scale);
		zraka.setOrigin(zraka.getSize() / 2.0f);
		zraka.setFillColor(sf::Color(255, 255, 0));
		zraka.setPosition(850, 37.5f);
		zraka.setRotation((i + 1) * 15);
		window->draw(zraka);
	}
}