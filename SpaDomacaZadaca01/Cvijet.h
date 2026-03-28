#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Cvijet {
private:
    RenderWindow* window;

    ConvexShape stabljika;
    CircleShape tucak;
    vector<CircleShape> latice;
    ConvexShape listLijevo;
    ConvexShape listDesno;
    ConvexShape listDesnoDole;
    RectangleShape nebo;
    RectangleShape trava;

    CircleShape sunce;
    CircleShape o1, o2, o3;
    CircleShape o4, o5, o6;

    Clock frameClock;

public:
	Cvijet(RenderWindow* target);
	void draw();
};