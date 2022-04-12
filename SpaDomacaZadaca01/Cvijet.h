#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::RectangleShape stabiljka;
	sf::ConvexShape listL;
	sf::ConvexShape listD;
	sf::CircleShape glava;
	sf::Texture poz;
	sf::Texture st;
	sf::Texture ls;
	sf::Texture gl;
	sf::Sprite pozadina;
	float rot = 1;
	float rotD = 0;
	float rotL = 0;
	float gla = 180;
	float sta = 265;
	bool nazad = false;
	sf::Clock frameClock;
	sf::Clock frameClock2;
public:
	Cvijet(sf::RenderWindow* window);
	void PostaviPozicije();
	void draw();
	void ProvjeriTeksture(sf::Texture& tx, std::string naziv);
	void KreirajDesniList(sf::ConvexShape& list, float pozicijaX, float pozicijaY);
	void KreirajLijeviList(sf::ConvexShape& list, float pozicijaX, float pozicijaY);
	void AnimacijaOkretanja();
	void AnimacijaPomicanja();
};

