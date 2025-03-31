#include "Cvijet.h"
#include <vector>
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	zrake_sunca.setPrimitiveType(sf::Lines);
	zrake_sunca.resize(48);
}

void Cvijet::draw()
{
	//SredinaCvijeta
	sf::CircleShape SredinaCvijeta(75.f);
	SredinaCvijeta.setPosition(150.f, 150.f);
	SredinaCvijeta.setFillColor(sredinaColor);
	SredinaCvijeta.setOutlineThickness(10.f);
	SredinaCvijeta.setOutlineColor(laticeColor);

	//Stabljika
	sf::RectangleShape stabljika(sf::Vector2f(200.f, 5.f));
	stabljika.rotate(90.f);
	stabljika.setPosition(SredinaCvijeta.getPosition().x * 1.5, SredinaCvijeta.getPosition().y + SredinaCvijeta.getRadius() * 2);
	stabljika.setFillColor(stabljikaColor);


	//List na stabljiki (manji)
	sf::ConvexShape list_manji;
	list_manji.setPointCount(4);
	list_manji.setPoint(0, sf::Vector2f(0.f, 0.f));
	list_manji.setPoint(1, sf::Vector2f(30.f, 60.f));
	list_manji.setPoint(2, sf::Vector2f(0.f, 120.f));
	list_manji.setPoint(3, sf::Vector2f(-30.f, 60.f));
	list_manji.rotate(-140.f);
	list_manji.setPosition(sf::Vector2f(stabljika.getPosition().x, stabljika.getPosition().y + stabljika.getSize().x - 50));
	list_manji.setFillColor(stabljikaColor);

	//List na stabljiki (veci)
	sf::ConvexShape list_veci;
	list_veci.setPointCount(4);
	list_veci.setPoint(0, sf::Vector2f(0.f, 0.f));
	list_veci.setPoint(1, sf::Vector2f(50.f, 70.f));
	list_veci.setPoint(2, sf::Vector2f(0.f, 140.f));
	list_veci.setPoint(3, sf::Vector2f(-50.f, 70.f));
	list_veci.rotate(130.f);
	list_veci.setPosition(sf::Vector2f(stabljika.getPosition().x, stabljika.getPosition().y + stabljika.getSize().x - 20));
	list_veci.setFillColor(stabljikaColor);


	//Sunce gore lijevo
	sunce.setRadius(30.f);
	sunce.setPosition(40.f, 40.f);
	sunce.setFillColor(sunceColor);


	window->draw(stabljika);
	window->draw(list_manji);
	window->draw(list_veci);
	window->draw(SredinaCvijeta);
	window->draw(zrake_sunca);
	window->draw(sunce);
}

void Cvijet::setColor(const int dio, const sf::Color& rgb_boja) {
	switch (dio) {
	case 0:
		sredinaColor = rgb_boja;
	case 1:
		laticeColor = rgb_boja;
	case 2:
		stabljikaColor = rgb_boja;
	case 3:
		sunceColor = rgb_boja;
	}
}

void Cvijet::update(float deltaTime)
{
	sf::Vector2f sunCenter(sunce.getPosition().x + sunce.getRadius(), sunce.getPosition().y + sunce.getRadius());
	for (int i = 0; i < 24; ++i)
	{
		float angle = i * (360.f / 24.f);

		float xEnd = sunCenter.x + (40.f * (deltaTime * 100)) * std::cos(angle * 3.14159f / 180.f);
		float yEnd = sunCenter.y + (40.f * (deltaTime * 100)) * std::sin(angle * 3.14159f / 180.f);

		zrake_sunca[i * 2].position = sunCenter;
		zrake_sunca[i * 2 + 1].position = sf::Vector2f(xEnd, yEnd);

		zrake_sunca[i * 2].color = sunceColor;
		zrake_sunca[i * 2 + 1].color = sunceColor;
	}
}
