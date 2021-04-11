#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;
class Cvijet
{   private:

	RenderWindow *window;
	CircleShape tucak;
	CircleShape octagon;
	CircleShape latice;
	ConvexShape stabljika;
	ConvexShape stabljika2;
	ConvexShape stabljika3;
	ConvexShape stabljika4;

public: 

	  Cvijet(RenderWindow *window);
      void draw();
	  
	  

};

