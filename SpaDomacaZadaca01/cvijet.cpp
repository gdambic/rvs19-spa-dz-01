#include "Cvijet.h"
using namespace sf;

Cvijet::Cvijet(RenderWindow& window) :window(window)
{
}

void Cvijet::draw()
{
    sunce.setRadius(20);
    sunce.setPosition(0.f, 0.f);
    sunce.setFillColor(Color(200, 200, 0));
   
    zbica.setSize(Vector2f(25.f, 250.f));
    zbica.setPosition(146.f, 298.f);
    zbica.setFillColor(Color(0, 170, 0));

    cvetic.setRadius(90);
    cvetic.setOutlineThickness(50);
    cvetic.setOutlineColor(Color(200, 0, 0));
    cvetic.setPosition(69.f, 69.f);
    cvetic.setFillColor(Color(200, 200, 0));
   
    list.setPointCount(4);
    list.setPoint(0, Vector2f(172.f, 420.f));
    list.setPoint(1, Vector2f(220.f, 350.f));
    list.setPoint(2, Vector2f(480.f, 300.f));
    list.setPoint(3, Vector2f(270.f, 420.f));
    list.setFillColor(Color(0, 170, 0));

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (clock.getElapsedTime().asSeconds() > 1.0f) {
            if (sunce.getRadius() == 30.f)
                sunce.setRadius(10.f);
            else
                sunce.setRadius(30.f);

            clock.restart();
        }

        window.clear();

        window.draw(sunce);

        window.draw(zbica);

        window.draw(cvetic);

        window.draw(list);

        window.display();
    }
}