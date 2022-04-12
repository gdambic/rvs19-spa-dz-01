#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
	private: 
		RenderWindow *window;
		Clock flowerClock;
		CircleShape flower;
		Clock sunClock;
		CircleShape sun;
		RectangleShape stem;
		ConvexShape leaf;

		void set_param();
		void anim_sun();
		void anim_flower();

	public:
		Cvijet(RenderWindow *window);
		void draw();
};

