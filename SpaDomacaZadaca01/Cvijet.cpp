#include "Cvijet.h"
Cvijet::Cvijet(RenderWindow* win) : window(win), kut(0)
{
    sunce.setRadius(50);
    sunce.setFillColor(Color::Yellow);
    sunce.setOrigin(50, 50);
    sunce.setPosition(100, 100);

    
    sredina.setRadius(30);
    sredina.setFillColor(Color::Red);
    sredina.setPosition(200, 320);

     latice.setPointCount(4);
     latice.setFillColor(Color::Magenta);
     latice.setPoint(0, Vector2f(0, 0));
     latice.setPoint(1, Vector2f(20, -70));
     latice.setPoint(2, Vector2f(40, 0));
     latice.setPoint(3, Vector2f(20, 70));
     latice.setOrigin(20, 0);
     latice.setPosition(200, 320);
 

    stabljika.setSize(Vector2f(10, 100));
    stabljika.setFillColor(Color::Green);
    stabljika.setPosition(205, 380);

    list.setSize(Vector2f(30, 10));
    list.setFillColor(Color::Green);
    list.setPosition(195, 440);

    for (int i = 0; i < 8; i++) {
        zrake[i].setSize(Vector2f(20, 5));
        zrake[i].setFillColor(Color::Yellow);
        zrake[i].setOrigin(10, 2.5);
        float angle = i * 45 * (3.14159265 / 180);
        float offsetX = sunce.getRadius() * cos(angle);
        float offsetY = sunce.getRadius() * sin(angle);
        zrake[i].setPosition(sunce.getPosition().x + offsetX, sunce.getPosition().y + offsetY);
        zrake[i].setRotation(i * 45);
    }
}

void Cvijet::crtaj()
{

    this->animirajSunce();
    window->draw(sunce);
    for (int i = 0; i < 8; i++) {
        window->draw(zrake[i]);
    }
    window->draw(sredina);
    window->draw(latice);
    window->draw(stabljika);
    window->draw(list);
}

void Cvijet::update()
{
    kut += 0.05f;
    float offset = 360.0f / 6;


        float angle = kut * offset;
        float x = cos(angle * 3.14 / 180.0f) * 100;
        float y = sin(angle * 3.14 / 180.0f) * 100;
        latice.setPosition(sredina.getPosition().x + x, sredina.getPosition().y + y);
   
}

void Cvijet::animirajSunce()
{
    float novaPozicijaX = sunce.getPosition().x + 1.0f;
    if (novaPozicijaX > 800)
    {
        novaPozicijaX = 0;
    }
    sunce.setPosition(novaPozicijaX, sunce.getPosition().y);
}

void Cvijet::postaviPoziciju(float x, float y)
{
    float deltaX = x - sredina.getPosition().x;
    float deltaY = y - sredina.getPosition().y;

    sunce.move(deltaX, deltaY);
    for (int i = 0; i < 8; i++) {
        zrake[i].move(deltaX, deltaY);
    }
   
    latice.move(deltaX, deltaY);
    stabljika.move(deltaX, deltaY);
    list.move(deltaX, deltaY);
}