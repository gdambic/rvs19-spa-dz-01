#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "stabljike.h"
using namespace sf;

class cvijetUbojama
{
private:
	Transform* pretvorbe=new Transform[10000];
	CircleShape* sCvijet = new CircleShape[10000];
	int brojLatica;
	int brojac;
	stabljike s;
	RenderWindow* window;
	int velicina; int x0; int y0;
public:
	cvijetUbojama(int velicina, int x0, int y0);
	cvijetUbojama();
	void konstruktor(float velicina, int x0, int y0,sf::RenderWindow* window);
	Transform at(int a);
	CircleShape na(int a);
	void zapocni(int a0, int b0);
};

