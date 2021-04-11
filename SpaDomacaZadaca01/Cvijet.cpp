
#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>

//(0x8A, 0x2B, 0xE2) ljubicasta

using namespace std;

Cvijet::Cvijet(sf::RenderWindow* adresa)
{
	this->adresa = adresa;
	

	neboTexture.loadFromFile("nebo.jpg");
	nebo.setTexture(&neboTexture);
	nebo.setSize(sf::Vector2f(800.f, 400.f));
	nebo.setPosition(0.f, 0.f);

	livada.setSize(sf::Vector2f(800.f, 200.f));
	livada.setPosition(0.f, 400.f);
	livadaTexture.loadFromFile("livada.jpg");
	livada.setTexture(&livadaTexture);

	stabljika.setSize(sf::Vector2f(180.f, 5.f));
	stabljika.setRotation(90.f);
	stabljika.setFillColor(sf::Color(0, 150, 0));
	stabljika.setPosition(312.f, 250.f);

	stabljika1.setSize(sf::Vector2f(70.f, 5.f));
	stabljika1.setRotation(135.f);
	stabljika1.setFillColor(sf::Color(0, 150, 0));
	stabljika1.setPosition(360.f, 320.f);

	cvijetic.setRadius(40.f);
	cvijetic.setPointCount(8);
	cvijetic.setPosition(270.f, 190.f);
	cvijeticTexture.loadFromFile("cvit.jpg");
	cvijetic.setTexture(&cvijeticTexture);
	cvijetic.setOutlineThickness(7.f);
	cvijetic.setOutlineColor(sf::Color(0x8A, 0x2B, 0xE2));

	cvijetic1.setRadius(10.f);
	cvijetic1.setPointCount(8);
	cvijetic1.setPosition(355.f, 300.f);
	cvijetic1Texture.loadFromFile("cvit.jpg");
	cvijetic1.setTexture(&cvijetic1Texture);
	cvijetic1.setOutlineThickness(4.f);
	cvijetic1.setOutlineColor(sf::Color(0x8A, 0x2B, 0xE2));
	
}

void Cvijet::draw() {
	
	sf::CircleShape latica1(10.f);
	latica1.setPosition(258.f, 179.f);
	latica1.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica1.setOutlineThickness(2.f);
	latica1.setOutlineColor(sf::Color::Yellow);
	
	sf::CircleShape latica2(10.f);
	latica2.setPosition(241.f, 219.f);
	latica2.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica2.setOutlineThickness(2.f);
	latica2.setOutlineColor(sf::Color::Yellow);
	
	sf::CircleShape latica3(10.f);
	latica3.setPosition(258.f, 261.f);
	latica3.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica3.setOutlineThickness(2.f);
	latica3.setOutlineColor(sf::Color::Yellow);
	

	sf::CircleShape latica4(10.f);
	latica4.setPosition(299.f, 278.f);
	latica4.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica4.setOutlineThickness(2.f);
	latica4.setOutlineColor(sf::Color::Yellow);
	

	sf::CircleShape latica5(10.f);
	latica5.setPosition(343.f, 261.f);
	latica5.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica5.setOutlineThickness(2.f);
	latica5.setOutlineColor(sf::Color::Yellow);
	

	sf::CircleShape latica6(10.f);
	latica6.setPosition(359.f, 219.f);
	latica6.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica6.setOutlineThickness(2.f);
	latica6.setOutlineColor(sf::Color::Yellow);
	

	sf::CircleShape latica7(10.f);
	latica7.setPosition(343.f, 179.f);
	latica7.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica7.setOutlineThickness(2.f);
	latica7.setOutlineColor(sf::Color::Yellow);
	

	sf::CircleShape latica8(10.f);
	latica8.setPosition(299.f, 162.f);
	latica8.setFillColor(sf::Color(0x8A, 0x2B, 0xE2));
	latica8.setOutlineThickness(2.f);
	latica8.setOutlineColor(sf::Color::Yellow);
	

	adresa->draw(nebo);
	adresa->draw(livada);
	adresa->draw(stabljika);
	adresa->draw(stabljika1);
	adresa->draw(cvijetic);
	adresa->draw(cvijetic1);

	adresa->draw(latica1);
	adresa->draw(latica2);
	adresa->draw(latica3);
	adresa->draw(latica4);
	adresa->draw(latica5);
	adresa->draw(latica6);
	adresa->draw(latica7);
	adresa->draw(latica8);



}


