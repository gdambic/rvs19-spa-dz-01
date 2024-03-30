#include "Cvijet.h"
#include <iostream>

using namespace sf;

Cvijet::Cvijet(RenderWindow* window)
{
    this->window = window;
}


void Cvijet::draw() {
 
    Time elapsed = clock.getElapsedTime();

    if (elapsed.asSeconds() > 10)
    {
        clock.restart();
    }

    std::cout << elapsed.asSeconds() << std::endl;

    CircleShape sunce(50.f);
    sunce.setFillColor(Color::Yellow);
    sunce.setPosition(600.f, 50.f);

    if (elapsed.asSeconds() < 5)
    {
        sunce.scale(Vector2f(1.f + elapsed.asSeconds() / 10, 1.f + elapsed.asSeconds() / 10));
    }
    else
    {
        sunce.scale(Vector2f(2.f - elapsed.asSeconds() / 10, 2.f - elapsed.asSeconds() / 10));
    }
   
    CircleShape glava(50.f);
    glava.setFillColor(Color::Red);
    glava.setPosition(300.f, 200.f); 

   
    ConvexShape latica;
    latica.setPointCount(4); 
    latica.setPoint(0, Vector2f(320.f, 200.f)); 
    latica.setPoint(1, Vector2f(400.f, 300.f));
    latica.setPoint(2, Vector2f(320.f, 400.f));
    latica.setPoint(3, Vector2f(240.f, 300.f));
    latica.setFillColor(Color::Yellow);
    latica.move(30.f, -50.f);


    
    RectangleShape stabiljka(Vector2f(20.f, 200.f)); 
    stabiljka.setFillColor(Color::Green); 
    stabiljka.setPosition(325.f, 350.f); 
    stabiljka.move(15.f, -50.f);

 
    ConvexShape list;
    list.setPointCount(4);
    list.setFillColor(Color::Green);
    list.setPoint(0, Vector2f(150.f, 250.f));
    list.setPoint(1, Vector2f(250.f, 350.f));
    list.setPoint(2, Vector2f(350.f, 400.f));
    list.setPoint(3, Vector2f(240.f, 300.f));


    window->draw(sunce);
    window->draw(stabiljka);
    window->draw(latica);
    window->draw(glava);
    window->draw(list);
}