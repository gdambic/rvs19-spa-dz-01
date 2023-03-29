#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

void Cvijet::draw_petal(float x, float y, float px, float py)
{
    sf::CircleShape petal(8.5f);
    petal.setFillColor(Color::Red);

    float p1, p2;
    p1 = x; p2 = y;
    p1 -= px;
    p2 -= py;
    petal.setPosition(p1, p2);
    
    window->draw(petal);
}

void Cvijet::draw_cloud(float x, float y, bool r)
{

    draw_cloud_part(x, y, r);
    draw_cloud_part(x + 100, y, r);
    draw_cloud_part(x + 25, y - 10, r);
    draw_cloud_part(x + 25, y + 10, r);
    draw_cloud_part(x + 55, y + 10, r);
    draw_cloud_part(x + 55, y - 10, r);
    draw_cloud_part(x + 80, y - 10, r);
    draw_cloud_part(x + 80, y + 10, r);
}

void Cvijet::draw_cloud_part(float x, float y, bool r)
{
    Time elapsed = clock.getElapsedTime();
    float p = elapsed.asSeconds() * 70;

    CircleShape c(30);
    c.setFillColor(Color(240, 240, 240, 255));
    c.setPosition(x+p, y);

    if (r) {
        if (x + p >= 900) {
            clock.restart();
        }
    }
    window->draw(c);
}

void Cvijet::draw_flower(float x, float y)
{
    float px, py;

    sf::RectangleShape line(sf::Vector2f(3.5f, 60.f));
    line.setFillColor(Color(0,100,0,255));
   
    sf::CircleShape middle(13.f);
    middle.setFillColor(Color::Yellow);

    sf::CircleShape side(13.f, 3);
    side.setFillColor(Color(0, 100, 0, 255));
    side.setPosition(x-19, y+5);
    side.rotate(10.f);

    sf::CircleShape side2(13.f, 3);
    side2.setFillColor(Color(0, 100, 0, 255));
    side2.setPosition(x-2, y + 20);
    side2.rotate(-10.f);

    line.setPosition(x, y);
  
    px = x; py = y;
    px -= 11;
    py -= 23;

    middle.setPosition(px, py);
    
    window->draw(line);
    window->draw(middle);
    draw_petal(x, y, 20, 12);
    draw_petal(x, y, 21, 27);
    draw_petal(x, y, -7, 27);
    draw_petal(x, y, -5, 12);
    draw_petal(x, y, 7, 36);
    window->draw(side);
    window->draw(side2);
}

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw(float radius)
{
   
    ground.setSize(Vector2f(800.f, 120.f));
    ground.setFillColor(Color(50,240,50,255));
    ground.setPosition(0, 480);

    sun.setFillColor(Color::Yellow);
    sun.setPosition(35, 28);
  
    sun.setRadius(radius);

    window->draw(ground);
    window->draw(sun);

    draw_cloud(-160, 30, 0); 
    draw_cloud(-460, 70, 0); 
    draw_cloud(-760, 45, 1); 

    draw_flower(100, 460);
    draw_flower(50, 440);
    draw_flower(200, 450);
    draw_flower(500, 460);
    draw_flower(600, 500);
    draw_flower(450, 430);
    draw_flower(750, 500);
    draw_flower(60, 500);
    draw_flower(150, 490);
    draw_flower(510, 500);

    // y je od 520 do 430
    // x je od 30 do 750
}

