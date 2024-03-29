#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::set_currentRadius(const float currentRadius)
{
	this->currentRadius = currentRadius;
}

void Cvijet::set_growing(const bool growing)
{
	this->growing = growing;
}

float Cvijet::get_currentRadius() const
{
	return currentRadius;
}

bool Cvijet::get_growing() const
{
	return growing;
}

void Cvijet::draw()
{
	sf::CircleShape cvijet(40.f);
	sf::CircleShape brezuljak1(300.f);
	sf::CircleShape brezuljak2(400.f);
	sf::CircleShape sunce(20.f);
	sf::RectangleShape zabIme(sf::Vector2f(20.f, 250.f));
	sf::ConvexShape list;
	

	cvijet.setFillColor(sf::Color(201, 195, 8));
	cvijet.setOutlineThickness(40.f);
	cvijet.setOutlineColor(sf::Color(227, 7, 7));
	cvijet.setPosition(200.f, 150.f);

	brezuljak1.setFillColor(sf::Color(61,156,11));
	brezuljak1.setPosition(-100.f, 500.f);

	brezuljak2.setFillColor(sf::Color(61, 156, 11));
	brezuljak2.setPosition(200.f, 500.f);

	zabIme.setPosition(230.f, 260.f);
	zabIme.setFillColor(sf::Color(95, 227, 7));

	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(50.f, -10.f));
	list.setPoint(2, sf::Vector2f(200.f, 20.f));
	list.setPoint(3, sf::Vector2f(50.f, 60.f));
	list.setFillColor(sf::Color(95, 227, 7));
	list.setPosition(240.f, 350.f);

	sunce.setFillColor(sf::Color(247, 199, 5));
	sunce.setPosition(750.f, 30.f);

	//Crtanje
	window->draw(zabIme);
	window->draw(cvijet);
	window->draw(list);
	window->draw(brezuljak1);
	window->draw(brezuljak2);

	elapsedTime = frameClock.restart();

	//Animacija
	//sto se tu desava boze
	//ovo onaj tip koda koji radi, 
	//ali sam i ja vrlo izgubljen u njemu pa ga necu dirat da se ne pokvari
	if (growing) {
		currentRadius += speed * elapsedTime.asSeconds();
		if (currentRadius >= maxRadius)
		{
			currentRadius = maxRadius;
			set_growing(false);
		}
	}
	else
	{
		currentRadius -= speed * elapsedTime.asSeconds();
		if (currentRadius <= minRadius)
		{
			currentRadius = minRadius;
			set_growing(true);
		}
	}

	//updating sunce
	sunce.setRadius(currentRadius);
	sunce.setOrigin(currentRadius, currentRadius);
	set_currentRadius(currentRadius);

	//animirano sunce
	window->draw(sunce);
}