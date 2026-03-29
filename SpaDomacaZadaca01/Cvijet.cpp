#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::set_radius(float radius)
{
	this->radius = radius;
}

void Cvijet::draw()
{
	float cvijetX = 200.f;
	float cvijetY = 200.f;

	sf::Color bojaLatica = sf::Color(215, 140, 215);
	sf::Color outlineLatica = sf::Color(185, 110, 185);
	sf::Color bojaL = sf::Color(225, 180, 235);
	sf::Color outlineL = sf::Color(215, 165, 225);
	sf::Color bojaStabiljke = sf::Color(5, 135, 25);

	// ------------------------------------------ stabljika ------------------------------------------
	sf::ConvexShape stabljika;

	stabljika.setPointCount(6);
	stabljika.setFillColor(sf::Color(bojaStabiljke));

	stabljika.setPoint(0, sf::Vector2f(cvijetX + 50, cvijetY + 70));	// 1. tocka
	stabljika.setPoint(5, sf::Vector2f(cvijetX + 55, cvijetY + 70));	// 6. tocka
	stabljika.setPoint(1, sf::Vector2f(cvijetX + 80, cvijetY + 260));	// 2. tocka
	stabljika.setPoint(4, sf::Vector2f(cvijetX + 85, cvijetY + 260));	// 5. tocka
	stabljika.setPoint(2, sf::Vector2f(cvijetX + 60, cvijetY + 375));	// 3. tocka
	stabljika.setPoint(3, sf::Vector2f(cvijetX + 65, cvijetY + 375));	// 4. tocka

	window->draw(stabljika);

	// ------------------------------------------ list ------------------------------------------
	sf::ConvexShape list;

	list.setPointCount(8);
	list.setFillColor(sf::Color(bojaStabiljke));

	list.setPoint(0, sf::Vector2f(cvijetX + 75, cvijetY + 290));	// 1. tocka
	list.setPoint(1, sf::Vector2f(cvijetX + 175, cvijetY + 230));	// 2. tocka
	list.setPoint(2, sf::Vector2f(cvijetX + 140, cvijetY + 250));	// 3. tocka
	list.setPoint(3, sf::Vector2f(cvijetX + 275, cvijetY + 200));	// 4. tocka
	list.setPoint(4, sf::Vector2f(cvijetX + 240, cvijetY + 220));	// 5. tocka
	list.setPoint(5, sf::Vector2f(cvijetX + 400, cvijetY + 190));	// 6. tocka
	list.setPoint(6, sf::Vector2f(cvijetX + 230, cvijetY + 235));	// 7. tocka
	list.setPoint(7, sf::Vector2f(cvijetX + 275, cvijetY + 245));	// 8. tocka

	window->draw(list);

	// ------------------------------------------ latice ------------------------------------------
	sf::CircleShape latica1(70.f, 10);
	latica1.setPosition(cvijetX + 40, cvijetY + 50);
	latica1.setFillColor(sf::Color(bojaLatica));
	latica1.setOutlineThickness(5.f);
	latica1.setOutlineColor(sf::Color(outlineLatica));

	window->draw(latica1);

	sf::CircleShape l1(40.f, 10);
	l1.setPosition(cvijetX + 70, cvijetY + 80);
	l1.setFillColor(sf::Color(bojaL));
	l1.setOutlineThickness(10.f);
	l1.setOutlineColor(sf::Color(outlineL));

	window->draw(l1);

	sf::CircleShape latica2(70.f, 10);
	latica2.setPosition(cvijetX + 70, cvijetY - 50);
	latica2.setFillColor(sf::Color(bojaLatica));
	latica2.setOutlineThickness(5.f);
	latica2.setOutlineColor(sf::Color(outlineLatica));

	window->draw(latica2);

	sf::CircleShape l2(40.f, 10);
	l2.setPosition(cvijetX + 100, cvijetY - 20);
	l2.setFillColor(sf::Color(bojaL));
	l2.setOutlineThickness(10.f);
	l2.setOutlineColor(sf::Color(outlineL));

	window->draw(l2);

	sf::CircleShape latica3(70.f, 10);
	latica3.setPosition(cvijetX - 20, cvijetY - 120);
	latica3.setFillColor(sf::Color(bojaLatica));
	latica3.setOutlineThickness(5.f);
	latica3.setOutlineColor(sf::Color(outlineLatica));

	window->draw(latica3);

	sf::CircleShape l3(40.f, 10);
	l3.setPosition(cvijetX + 10, cvijetY - 90);
	l3.setFillColor(sf::Color(bojaL));
	l3.setOutlineThickness(10.f);
	l3.setOutlineColor(sf::Color(outlineL));

	window->draw(l3);

	sf::CircleShape latica4(70.f, 10);
	latica4.setPosition(cvijetX - 100, cvijetY - 45);
	latica4.setFillColor(sf::Color(bojaLatica));
	latica4.setOutlineThickness(5.f);
	latica4.setOutlineColor(sf::Color(outlineLatica));

	window->draw(latica4);

	sf::CircleShape l4(40.f, 10);
	l4.setPosition(cvijetX - 70, cvijetY - 15);
	l4.setFillColor(sf::Color(bojaL));
	l4.setOutlineThickness(10.f);
	l4.setOutlineColor(sf::Color(outlineL));

	window->draw(l4);

	sf::CircleShape latica5(70.f, 10);
	latica5.setPosition(cvijetX - 70, cvijetY + 50);
	latica5.setFillColor(sf::Color(bojaLatica));
	latica5.setOutlineThickness(5.f);
	latica5.setOutlineColor(sf::Color(outlineLatica));

	window->draw(latica5);

	sf::CircleShape l5(40.f, 10);
	l5.setPosition(cvijetX - 40, cvijetY + 80);
	l5.setFillColor(sf::Color(bojaL));
	l5.setOutlineThickness(10.f);
	l5.setOutlineColor(sf::Color(outlineL));

	window->draw(l5);

	// ------------------------------------------ centar cvijeta ------------------------------------------
	sf::CircleShape cvijet(50.f);

	cvijet.setPosition(cvijetX, cvijetY);

	cvijet.setFillColor(sf::Color(255, 240, 0));

	cvijet.setOutlineThickness(20.f);
	cvijet.setOutlineColor(sf::Color(255, 213, 0));

	window->draw(cvijet);

	// ------------------------------------------ animirano sunce ------------------------------------------
	sf::Time elapsed = clock.getElapsedTime();
	sf::Time period = sf::seconds(5.f);

	float kut = 2.f * 3.14159f * (elapsed.asSeconds() / period.asSeconds());
	float r = radius + 5.f * (std::sin(kut) + 1.f) / 2.f;

	sf::CircleShape sunce(r);
	sunce.setPosition(10.f, 10.f);
	sunce.setFillColor(sf::Color(255, 240, 0));

	window->draw(sunce);
}
