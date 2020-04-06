#pragma once
#include"SFML/Graphics.hpp"
using namespace sf;

class Kisa : public RectangleShape {
	;

	float x;
	float y;
	float z;
	float yspeed;

public:
	Kisa();
	void pada();

};