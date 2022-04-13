#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class Cvijet
{
private:
	RenderWindow* window;		// otvaranje crnog ekrana
	Clock clock;				// sat za animaciju

public:
	Cvijet (RenderWindow* window);	//konstruktor Cvijet
	void draw();				// metoda za crtanje

	
};

