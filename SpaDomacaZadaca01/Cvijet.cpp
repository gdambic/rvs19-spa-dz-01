#include "Cvijet.h" 
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
   
}

void Cvijet::draw()
{
    
    draw_background();
    draw_sunce();
    draw_trup();
    draw_outline();
    draw_latice();
       /* sf::Time t = clock.getElapsedTime();
        if (t == 2.27732) window->draw(parts[1]);
        window->draw(parts[0]);
   
        std::cout << t.asSeconds() << endl;*/
    

}


void Cvijet::draw_trup()  {

    sf::RectangleShape stabljika;

    stabljika.setSize(sf::Vector2f(300, 20));
    stabljika.setFillColor(sf::Color(0,125,10));
    stabljika.rotate(-90);
    stabljika.setPosition(450, 600);

    window->draw(stabljika);

    sf::CircleShape glava;
    
    
    glava.setRadius(40);
    glava.setFillColor(sf::Color::Yellow);
    glava.setOrigin(40, 40);
    glava.setPosition(460, 200);
    window->draw(glava);


    sf::ConvexShape list;
   
    list.setPointCount(4);

    list.setPoint(0, sf::Vector2f(470, 500));
    list.setPoint(1, sf::Vector2f(530, 510));
    list.setPoint(2, sf::Vector2f(650, 420));
    list.setPoint(3, sf::Vector2f(530, 450));
    list.setFillColor(sf::Color(0, 125, 10));
 
    window->draw(list);

    efekt.resize(5);
   
    efekt[0].setSize(sf::Vector2f(600, 5));
    efekt[0].setFillColor(sf::Color::Yellow);
    efekt[0].setPosition(460,210);
    efekt[0].rotate(50);

    window->draw(efekt[0]);
}

void Cvijet::draw_latice()
{
    
    sf::CircleShape latice;;
    latice.setRadius(50);
    latice.move(460, 210);
    latice.setRotation(0);
    for (int i = 0; i < 10; i++) {
        
        latice.rotate(40);
    window->draw(latice);
    latice.setFillColor(sf::Color::Magenta);
  // latice.setOutlineThickness(1);
    latice.setOutlineColor(sf::Color::Cyan);
    }
    

    

}

void Cvijet::draw_outline()
{

    sf::CircleShape latice;;
    latice.setRadius(50);
    latice.move(460, 210);
    latice.setRotation(0);
    for (int i = 0; i < 10; i++) {

        latice.rotate(40);
        window->draw(latice);
        latice.setFillColor(sf::Color::Magenta);
        latice.setOutlineThickness(2);
        latice.setOutlineColor(sf::Color(125,125,125));
    }




}

void Cvijet::draw_sunce()
{
    
     int radius = 100;
     sf::CircleShape sunce;
    sunce.setRadius(radius);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setOrigin(radius, radius);
    sunce.setOutlineColor(sf::Color(250,200,100));
    sunce.setOutlineThickness(10);
    sunce.setPosition(20, 20);
    

    window->draw(sunce);

    auto t = clock.getElapsedTime();
    stringstream ss;
    
    ss << t.asSeconds();
    int timer;
    ss >> timer;
    
        vector<sf::RectangleShape> zrake(8);
    
        zrake[0].rotate(2);
        zrake[0].setSize(sf::Vector2f(100, 5));
        zrake[0].setFillColor(sf::Color::Yellow);
        zrake[0].setPosition(165, 5);
        if (timer%2==0)zrake[0].setFillColor(sf::Color::Red);

       /* zrake[1].setSize(sf::Vector2f(100, 5));
        zrake[1].rotate(10);
        zrake[1].setFillColor(sf::Color::Red);
        zrake[1].setPosition(155, 55);*/

        zrake[2].setSize(sf::Vector2f(100, 5));
        zrake[2].rotate(20);
        zrake[2].setFillColor(sf::Color::Yellow);
        zrake[2].setPosition(163, 55);
        if (timer % 2==1)zrake[2].setFillColor(sf::Color::Red);


        zrake[3].setSize(sf::Vector2f(100, 5));
        zrake[3].rotate(37);
        zrake[3].setFillColor(sf::Color::Yellow);
        zrake[3].setPosition(140, 100);
        if (timer % 2 == 0)zrake[3].setFillColor(sf::Color::Red);

        zrake[4].setSize(sf::Vector2f(100, 5));
        zrake[4].rotate(55);
        zrake[4].setFillColor(sf::Color::Yellow);
        zrake[4].setPosition(100, 140);
        if (timer % 2 == 1)zrake[4].setFillColor(sf::Color::Red);

        zrake[5].setSize(sf::Vector2f(100, 5));
        zrake[5].rotate(55);
        zrake[5].setFillColor(sf::Color::Yellow);
        zrake[5].setPosition(100, 140);
        if (timer % 2 == 0)zrake[5].setFillColor(sf::Color::Red);

        zrake[6].setSize(sf::Vector2f(100, 5));
        zrake[6].rotate(70);
        zrake[6].setFillColor(sf::Color::Yellow);
        zrake[6].setPosition(50, 160);
        if (timer % 2 == 1)zrake[6].setFillColor(sf::Color::Red);

        zrake[7].setSize(sf::Vector2f(100, 5));
        zrake[7].rotate(88.5);
        zrake[7].setFillColor(sf::Color::Yellow);
        zrake[7].setPosition(5, 170);
        if (timer % 2 == 0)zrake[7].setFillColor(sf::Color::Red);

    for (unsigned i = 0; i < 8; i++)
    {
        window->draw(zrake[i]);
    }
}

void Cvijet::draw_background()const{
    sf::RectangleShape nebo(sf::Vector2f(1100, 550));
    nebo.setPosition(0, 0);
    nebo.setFillColor(sf::Color(0, 150,250));
    window->draw(nebo);

    sf::RectangleShape trava(sf::Vector2f(1100, 200));
    trava.setPosition(0, 520);
    trava.setFillColor(sf::Color::Green);
    window->draw(trava);
}
