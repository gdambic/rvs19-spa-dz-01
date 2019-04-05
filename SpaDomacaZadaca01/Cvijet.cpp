#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;
}

void Cvijet::draw()
{
	window->draw(kruznica);
	window->draw(tjelo_cvijeta);
	window->draw(list_romb);

	if (n<= 100)
	{
		window->draw(sunce1);
	}
	else if (n>=100&&n<=200)
	{
		window->draw(sunce2);
	}
	else
	{
		n = 0;
	}
	n++;
}

sf::CircleShape Cvijet::napravi_sunce(float radius)
{
	sf::CircleShape krug(radius);
	krug.setFillColor(sf::Color::Yellow);
	krug.setPosition(radius /2, radius/2);

	return krug;
}

sf::CircleShape Cvijet::napravi_krug(float radius)
{
	sf::CircleShape krug(radius);
	krug.setFillColor(sf::Color::Yellow);
	krug.setOutlineThickness(radius / 3);
	krug.setOutlineColor(sf::Color::Red);
	krug.setPosition((radius / 3) + 50, (radius / 3) + 50);

	return krug;
}

sf::RectangleShape Cvijet::napravi_tjelo(float sirina, float visina, float radius)
{
	sf::RectangleShape tjelo(sf::Vector2f(sirina, visina));
	tjelo.setFillColor(sf::Color::Green);
	sf::Vector2f pozicija(tjelo_x, tjelo_y);
	tjelo.setPosition(pozicija);

	return tjelo;
}

sf::ConvexShape Cvijet::napravi_list()
{
	sf::ConvexShape romb;
	romb.setFillColor(sf::Color::Green);
	romb.setPointCount(4);
	romb.setPoint(0, sf::Vector2f(115.f, 275.f));
	romb.setPoint(1, sf::Vector2f(185.f, 255.f));
	romb.setPoint(2, sf::Vector2f(285.f, 275.f));
	romb.setPoint(3, sf::Vector2f(185.f, 295.f));
	romb.setPosition(-110.f, 100.f);
	romb.rotate(-30.f);

	return romb;
}
