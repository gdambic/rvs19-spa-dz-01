#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
#include<vector>

using namespace sf;

class Cvijet
{
private:
	    
		RenderWindow& window;
		RectangleShape tijelo;
		CircleShape krug;
		CircleShape krug2;
		ConvexShape list;
		ConvexShape list2;
		Clock clock;
		
	public:
		Cvijet(RenderWindow &window);
		void draw();
};

