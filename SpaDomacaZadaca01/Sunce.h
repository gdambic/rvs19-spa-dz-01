#pragma once
#include<SFML/Graphics.hpp>
#include"Tocka.h"

class Sunce {
	sf::RenderWindow* RenWin;
	sf::Clock PocetakPostojanja;

	Tocka Pozicija;
public:
	Sunce(sf::RenderWindow* Ren);

	void SetPoz(Tocka Poz);
	void SetPoz(double x, double y);

	void draw();
};

