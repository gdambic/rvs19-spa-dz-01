#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class Cvijet
{
public:
	Cvijet(RenderWindow& window);
	void draw(RenderWindow& window);
private:
	CircleShape glava, lijevo_oko, desno_oko;
};

