#include "Cvijet.h"
#include <cmath>
Cvijet::Cvijet(RenderWindow* window) 
{
	this->window = window;
}

void Cvijet::draw()
{
        

    float time = frameClock.getElapsedTime().asSeconds();

    //pretvaram vrijeme u int da bi mogao prebrojati sekunde
    int whole_second = static_cast<int>(time);
    bool isSecondEven = (whole_second % 2 == 0);
   


    //zemlja
    RectangleShape ground(Vector2f(800.f, 50.f)); // sirina, visina
    ground.setPosition(0.f, 550.f);
    ground.setFillColor(Color(50, 117, 43));

    //stabljika
    RectangleShape stem(Vector2f(10.f, 250.f)); // sirina, visina
    stem.setPosition(350.f, 300.f); // x, y
    stem.setFillColor(Color(34, 135, 34));

    //list
    CircleShape leaf(20.f, 100.f); 
    leaf.setScale(1, 2.7);
    leaf.setFillColor(Color(34, 135, 34));
    leaf.setRotation(-45.f);
    leaf.setPosition(347.f, 350.f); 

    //dio lista
    RectangleShape vein(Vector2f(2.5, 90)); 
    vein.setPosition(365.f, 340.f);
    vein.setRotation(-45.f);
    vein.setFillColor(Color(34, 170, 34));    
    
    //latice
    CircleShape petal(80.f, 8.f);
    petal.setFillColor(Color(245, 220, 81));
    petal.setOrigin(0,0);
    petal.setPosition(275.f, 145.f);

    //sredina cvijeta
    CircleShape center(40.f, 10.f);
    center.setFillColor(Color(199, 95, 66));
    center.setPosition(315.f, 190.f);

    //sunce :)
    CircleShape sun(15.f); 
    sun.setPosition(150.f, 50.f);
    sun.setOrigin(15.f, 15.f);
    

    //oblak se sastoji od vise krugova
    CircleShape circle1(20.f);
    circle1.setFillColor(Color::White);
    circle1.setPosition(160.f, 50.f);

    CircleShape circle2(30.f);
    circle2.setFillColor(Color::White);
    circle2.setPosition(175.f, 35.f);

    CircleShape circle3(25.f);
    circle3.setFillColor(Color::White);
    circle3.setPosition(200.f, 50.f);

    CircleShape circle4(20.f);
    circle4.setFillColor(Color::White);
    circle4.setPosition(230.f, 45.f);

    CircleShape circle5(15.f);
    circle5.setFillColor(Color::White);
    circle5.setPosition(250.f, 55.f);


    float leaf_rotation = 0.f;
    float vein_rotation = 0.f;
    float sun_scale;
    if (isSecondEven)
    {
        leaf_rotation = -45.f;
        vein_rotation = -45.f;
        sun_scale = 1.f;
        sun.setFillColor(Color(240, 232, 30));
    }
    else
    {
        leaf_rotation = -65.f;
        vein_rotation = -65.f;
        sun_scale = 2.f;
        sun.setFillColor(Color(240, 217, 30));
    }

    leaf.setRotation(leaf_rotation);
    vein.setRotation(vein_rotation);
    sun.setScale(sun_scale, sun_scale);

    window->draw(ground);
    window->draw(stem);
    window->draw(leaf);
    window->draw(vein);
    window->draw(petal);
    window->draw(center);
    window->draw(sun);
    window->draw(circle1);
    window->draw(circle2);
    window->draw(circle3);
    window->draw(circle4);
    window->draw(circle5);

    
}
