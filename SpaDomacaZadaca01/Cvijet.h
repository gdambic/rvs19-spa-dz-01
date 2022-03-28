#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
	private: 
		RenderWindow *window;
		Clock frameClock;
		CircleShape flower;
		CircleShape sun;
		RectangleShape stem;
		ConvexShape leaf;

		void set_param();
		void anim_sun();

	public:
		Cvijet(RenderWindow *window);
		void draw();
		void anim();
};

