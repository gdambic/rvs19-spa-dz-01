#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Cvijet
{
public:
    Cvijet(RenderWindow* window);
    void draw();
private:
    RenderWindow* window;
    CircleShape sunce;
    RectangleShape stabljika;
    ConvexShape desni_list;
    ConvexShape lijevi_list;
    CircleShape krug;
    CircleShape latica;
    Clock frameClock;
};

