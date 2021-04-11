#include "Cvijet.h"
#include <vector>
#include <iostream>

using namespace std;

void Cvijet::centarCvijetaSet()
{
	flowerCenterRadius = 15;
	flowerCenterX = 200;
	flowerCenterY = 200;
	flowerCenterColor = sf::Color(178, 102, 255, 255);

	centarCvijeta.setRadius(flowerCenterRadius);
	centarCvijeta.setFillColor(flowerCenterColor);
	centarCvijeta.setOutlineColor(sf::Color::Black);
	centarCvijeta.setOutlineThickness(1);

	centarCvijeta.setPosition(sf::Vector2f(flowerCenterX, flowerCenterY));
	centarCvijeta.setOrigin(sf::Vector2f(flowerCenterRadius, flowerCenterRadius));
}

void Cvijet::krugLatica1Set()
{
	petals1 = 8;
	petal1Radius = 10;
	petal1Color = sf::Color(51, 51, 255, 255);

	krugLatica1 = vector<sf::CircleShape>(petals1);

	float alpha = 2 * 3.14159f / petals1;

	for (unsigned int i = 0; i < krugLatica1.size(); i++)
	{
		sf::CircleShape& petal(krugLatica1[i]);

		petal.setRadius(petal1Radius);
		petal.setFillColor(petal1Color);
		petal.setOutlineColor(sf::Color::Black);
		petal.setOutlineThickness(1);

		float xposition = flowerCenterX + (flowerCenterRadius + petal1Radius) * cos(alpha * i);
		float yposition = flowerCenterY + (flowerCenterRadius + petal1Radius) * sin(alpha * i);

		petal.setPosition(sf::Vector2f(xposition, yposition));
		petal.setOrigin(sf::Vector2f(petal1Radius, petal1Radius));
	}
}

void Cvijet::krugLatica2Set()
{
	petals2 = 16;
	petal2Radius = 7;
	petal2Color = sf::Color(51, 255, 255, 255);

	krugLatica2 = vector<sf::CircleShape>(petals2);

	float alpha = 2 * 3.14159f / petals2;

	for (unsigned int i = 0; i < krugLatica2.size(); i++)
	{
		sf::CircleShape& petal(krugLatica2[i]);

		petal.setRadius(petal2Radius);
		petal.setFillColor(petal2Color);
		petal.setOutlineColor(sf::Color::Black);
		petal.setOutlineThickness(1);

		float xposition = flowerCenterX + (flowerCenterRadius + petal1Radius * 1.2f + petal2Radius) * cos(alpha * i);
		float yposition = flowerCenterY + (flowerCenterRadius + petal1Radius * 1.2f + petal2Radius) * sin(alpha * i);

		petal.setPosition(sf::Vector2f(xposition, yposition));
		petal.setOrigin(sf::Vector2f(petal2Radius, petal2Radius));
	}
}

void Cvijet::stabljikaSet()
{
	stalkHeight = 150;
	stalkWidth = 5;
	stabljikaColor = sf::Color(0, 153, 0, 255);

	float stalkX = flowerCenterX;
	float stalkY = flowerCenterY + flowerCenterRadius;

	stabljika.setSize(sf::Vector2f(stalkWidth, stalkHeight));
	stabljika.setFillColor(stabljikaColor);
	stabljika.setOutlineColor(sf::Color::Black);
	stabljika.setOutlineThickness(1);

	stabljika.setPosition(sf::Vector2f(stalkX - (stalkWidth / 2), stalkY));
}

void Cvijet::listicSet()
{

	float stalkX = flowerCenterX;
	float stalkY = flowerCenterY + flowerCenterRadius;

	float listicPositionX = 270;
	float listicPositionY = 276;

	listicColor = sf::Color(0, 153, 0, 255);

	listic.setPointCount(4);

	float pointOneX = 0.0f;
	float pointOneY = 0.0f;

	float pointTwoX = pointOneX - 3.86f * 12;
	float pointTwoY = pointOneY + 1.64f * 12;

	float pointThreeX = pointOneX - 5.68f * 12;
	float pointThreeY = pointOneY + 4.04f * 12;

	float pointFourX = pointOneX - 3.0f * 12;
	float pointFourY = pointOneY + 3.0f * 12;

	listic.setPoint(0, sf::Vector2f(pointOneX, pointOneY));
	listic.setPoint(1, sf::Vector2f(pointTwoX, pointTwoY));
	listic.setPoint(2, sf::Vector2f(pointThreeX, pointThreeY));
	listic.setPoint(3, sf::Vector2f(pointFourX, pointFourY));

	listic.setFillColor(listicColor);
	listic.setOutlineColor(sf::Color::Black);
	listic.setOutlineThickness(1);

	listic.setPosition(sf::Vector2f(listicPositionX, listicPositionY));
}

void Cvijet::sunceSet()
{
	sunceRadius = 40;
	sunceColor = sf::Color(255, 255, 102, 255);

	sunce.setRadius(sunceRadius);
	sunce.setFillColor(sunceColor);
	sunce.setOutlineColor(sf::Color::Black);
	sunce.setOutlineThickness(1);

	sunce.setPosition(sf::Vector2f(suncePositionX, suncePositionY));
}

void Cvijet::backgroundSet()
{
	travaColor = sf::Color(153, 255, 153, 255);
	neboColor = sf::Color(204, 229, 255, 255);

	float backgroundTravaWidth = 512;
	float backgroundTravaHeight = 146;
	float bTPositionX = 0;
	float bTPositionY = 366;

	float backgroundNeboWidth = 512;
	float backgroundNeboHeight = 366;
	float bNPositionX = 0;
	float bNPositionY = 0;

	backgroundTrava.setSize(sf::Vector2f(backgroundTravaWidth, backgroundTravaHeight));
	backgroundTrava.setFillColor(travaColor);
	backgroundTrava.setOutlineColor(sf::Color::Black);
	backgroundTrava.setOutlineThickness(0);

	backgroundTrava.setPosition(sf::Vector2f(bTPositionX, bTPositionY));

	backgroundNebo.setSize(sf::Vector2f(backgroundNeboWidth, backgroundNeboHeight));
	backgroundNebo.setFillColor(neboColor);
	backgroundNebo.setOutlineColor(sf::Color::Black);
	backgroundNebo.setOutlineThickness(0);

	backgroundNebo.setPosition(sf::Vector2f(bNPositionX, bNPositionY));

}

Cvijet::Cvijet(sf::RenderWindow* rw)
{
	this->drawWindow = rw;

	centarCvijetaSet();
	krugLatica1Set();
	krugLatica2Set();
	stabljikaSet();
	listicSet();
	sunceSet();

	backgroundSet();
}

void Cvijet::draw()
{
	this->drawWindow->draw(backgroundTrava);
	this->drawWindow->draw(backgroundNebo);

	this->drawWindow->draw(listic);
	this->drawWindow->draw(stabljika);

	for (int j = 0; j < (int)krugLatica2.size(); j++)
	{
		this->drawWindow->draw(krugLatica2[j]);
	}

	for (int i = 0; i < (int)krugLatica1.size(); i++)
	{
		this->drawWindow->draw(krugLatica1[i]);
	}

	this->drawWindow->draw(centarCvijeta);

	sf::Vector2f delta(20, 5);
	float moveInterval = 0.25f;

	if (clock.getElapsedTime().asSeconds() > moveInterval) {
		sunce.move(delta);
		if (sunce.getPosition().x > this->drawWindow->getSize().x) {
			sunce.setPosition(sf::Vector2f(suncePositionX, suncePositionY));
		}
		clock.restart();
	}
	this->drawWindow->draw(sunce);
}