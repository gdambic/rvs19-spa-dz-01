#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Cvijet
{
public:
	Cvijet (RenderWindow &window);
	void draw(RenderWindow &window);
	void anim(Clock &clock, RenderWindow& window);

private:
	CircleShape glava, okoL, okoLU, okoR, okoRU, okoLA;
	RectangleShape usta, stabiljka;
	ConvexShape list;
};
