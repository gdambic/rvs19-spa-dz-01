#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow& window) : window(window)
{}

sf::CircleShape Cvijet::get_crveniKrug()
{

	crveniKrug.setRadius(120.f);
	crveniKrug.setFillColor(sf::Color::Red);
	crveniKrug.setPosition(sf::Vector2f(20, 20));

	return crveniKrug;
}

sf::CircleShape Cvijet::get_zutiKrug()
{
	zutiKrug.setRadius(75.f);
	zutiKrug.setFillColor(sf::Color::Yellow);
	zutiKrug.setPosition(sf::Vector2f(65, 65));

	return zutiKrug;
}

sf::CircleShape Cvijet::get_maliKrug()
{
	maliKrug.setRadius(20.f);
	maliKrug.setFillColor(sf::Color::Yellow);
	maliKrug.setPosition(sf::Vector2f(10, 10));

	return maliKrug;
}

sf::ConvexShape Cvijet::get_listBiljke()
{
	listBiljke.setPointCount(4);
	listBiljke.setFillColor(sf::Color::Green);
	listBiljke.setPoint(0, sf::Vector2f(150.f, 350.f));
	listBiljke.setPoint(1, sf::Vector2f(250.f, 365.f));
	listBiljke.setPoint(2, sf::Vector2f(425.f, 275.f));
	listBiljke.setPoint(3, sf::Vector2f(250.f, 300.f));

	return listBiljke;
}

sf::RectangleShape Cvijet::get_linija()
{
	sf::RectangleShape linija; //Ako ovo ne napravim i ovdje, linija se brzo vrti, neki bug (vidi se ako se commenta ova linija i pokrene)
	linija.setSize(sf::Vector2f(200, 15));
	linija.setFillColor(sf::Color::Green);
	linija.setPosition(sf::Vector2f(150, 259));
	linija.rotate(90.f);

	return linija;
}

void Cvijet::draw() {

	maliKrug = get_maliKrug();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if (clock.getElapsedTime().asSeconds() > 1.0f) {

			if (maliKrug.getRadius() == 20.f)
			{
				maliKrug.setRadius(10.f);
				maliKrug.setPosition(sf::Vector2f(20, 20));
			}
			else {
				maliKrug.setRadius(20.f);
				maliKrug.setPosition(sf::Vector2f(10, 10));
			}

			clock.restart();
		}

		window.clear();

		window.draw(get_crveniKrug());
		window.draw(get_zutiKrug());
		window.draw(get_linija());
		window.draw(get_listBiljke());
		window.draw(maliKrug);

		window.display();
	}
}