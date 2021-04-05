#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
using namespace sf;

class sareniCvijet
{
private:
	Transform pretvorbe[10000];
	CircleShape* sCvijet = new CircleShape[10000];
	int brojLatica;
	int brojac;
	int velicina; int x0; int y0;
public:
	sareniCvijet(int velicina, int x0, int y0);
	sareniCvijet();
};

