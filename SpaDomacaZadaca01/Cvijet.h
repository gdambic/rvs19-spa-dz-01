#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
private:
    RenderWindow* prozor;

    RectangleShape nebo;
    RectangleShape trava;
    RectangleShape zemlja;
    CircleShape    oblak1[4];
    CircleShape    oblak2[3];

    CircleShape    sunce;
    CircleShape    sunceGlow;
    RectangleShape stablo;
    ConvexShape    list;
    ConvexShape    listMali;
    CircleShape    latice[8];
    CircleShape    laticeUnutarnje[8];
    CircleShape    srediste;
    CircleShape    sredisteSjaj;

    Clock frameClock;
    float sunRadius;
    bool  sunGrowing;
    float oblakOffset;

public:
    Cvijet(RenderWindow* prozor);
    void draw();
};
