#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderTarget* window)
{
	_window = window;
	smjer_povecanja = 1.f;
	sredina.setRadius(70);
	sredina.setFillColor(sf::Color(255, 255, 51));
	sredina.setOutlineThickness(40);
	sredina.setOutlineColor(sf::Color(255, 0, 0));
	sredina.setPosition(330, 50);

	stabljika.setSize(sf::Vector2f(10, 370));
	stabljika.setPosition(395, 230);
	stabljika.setFillColor(sf::Color(0, 255, 0));

	list.setPointCount(3);
	list.setPoint(0, sf::Vector2f(400, 450));
	list.setPoint(1, sf::Vector2f(700, 350));
	list.setPoint(2, sf::Vector2f(450, 300));
	list.setFillColor(sf::Color(0, 255, 0));

	sunce.setRadius(40);
	sunce.setFillColor(sf::Color(255, 255, 51));
	sunce.setOutlineThickness(20);
	sunce.setOutlineColor(sf::Color(203, 203, 35));
	sunce.setPosition(50, 50);
}

void Cvijet::draw(sf::Clock& clock)
{
	float velicina = sunce.getRadius();
	sf::Time time = clock.restart();
	if (velicina <= 40.f) smjer_povecanja = 1.f;
	if (velicina >= 80.f) smjer_povecanja = -1.f;
	velicina += smjer_povecanja * 20.f * time.asSeconds();
	sunce.setRadius(velicina);
	sunce.setPosition(sf::Vector2f{ 100.F - velicina, 100.F - velicina });

	_window->draw(sredina);
	_window->draw(stabljika);
	_window->draw(list);
	_window->draw(sunce);
}

