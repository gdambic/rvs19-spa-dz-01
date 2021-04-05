#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include<iostream>
#include "cvijetUbojama.h"
#include "kisa.h"
using namespace sf;
class Cvijet
{
private:
	CircleShape shape;
	RenderWindow* window;
	Transform pretvorbe[10000];
	CircleShape* sareniCvijet = new CircleShape[10000];
	bool animiraj;
	int brojLatica;
	cvijetUbojama* sarenko=new cvijetUbojama[5];
	int brojac;
	CircleShape* ciri2 = new CircleShape[10000];
	Transform* pretvorbeMaslacka=new Transform[10000];
	int brojac2;
	int brojLatica2;
	sf::Clock clock;
	sf::Clock clock2;
	kisa* kapljice = new kisa[800];
	int abc = 1;
	int* Vkapljice = new int[800];
	int* xKapljice = new int[800];
	

public:
	void padajKiso();
	void paduckajKiso();
	void randomBrojevi();

	Cvijet(RenderWindow* window);
	void draw();
	//Cvijet(std::string boja);
	sf::CircleShape svet();
	int a();
	void crtajMaslaèak();
	void crtajTravnjak();
	void inSareniCvijet();
	void crtajStabljikuMaslackovu();
};

