#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>

using namespace std;
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

void Cvijet::draw_flower(float x, float y, Color c)
{
    float px, py;

    sf::RectangleShape line(sf::Vector2f(3.5f, 60.f));
    line.setFillColor(Color(0,100,0,255));
   
    sf::CircleShape middle(13.f);
    middle.setFillColor(c);

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

    Color red = Color::Yellow;
    draw_flower(100, 460, red);
    draw_flower(50, 440, red);
    draw_flower(200, 450, red);
    draw_flower(500, 460, red);
    draw_flower(600, 500, red);
    draw_flower(450, 430, red);
    draw_flower(750, 500, red);
    draw_flower(60, 500, red);
    draw_flower(150, 490, red);
    draw_flower(510, 500, red);

    // y je od 520 do 430
    // x je od 30 do 750
}

Cvijet::Bee::Bee(sf::RenderWindow* window)
{
    this->window = window;
   
    font.loadFromFile("Presley.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setPosition(300, 300);
    text.setFillColor(sf::Color::Blue);
    text.setString("to move...");

    body.setRadius(13);
    body.setFillColor(sf::Color::Yellow);
    body.setOutlineThickness(2);
    body.setOutlineColor(sf::Color::Black);
    body.setPosition(x, y);

    head.setRadius(8);
    head.setFillColor(sf::Color::Yellow);
    head.setOutlineThickness(1.5);
    head.setOutlineColor(sf::Color::Black);
    head.setPosition(x - 10, y + 5);

    sf::CircleShape sting_(10, 3);
    sting = sting_;

    sting.setPosition(x + 15, y + 8);
    sting.setFillColor(sf::Color::Black);
    sting.rotate(-40);

    wing1.setRadius(7);
    wing1.setPosition(x, y - 7);
    wing1.setFillColor(sf::Color(240, 240, 240, 255));
    wing1.setOutlineColor(sf::Color::Black);
    wing1.setOutlineThickness(1);

    wing2.setRadius(7);
    wing2.setPosition(x + 9, y - 7);
    wing2.setFillColor(sf::Color(240, 240, 240, 255));
    wing2.setOutlineColor(sf::Color::Black);
    wing2.setOutlineThickness(1);

    up = false;
    down = false;
    left = false;
    right = false;
}

void Cvijet::Bee::draw() 
{
    window->draw(body);
    window->draw(head);
    window->draw(sting);
    window->draw(wing1);
    window->draw(wing2);
}

void Cvijet::Bee::processEvents(sf::Keyboard::Key key, bool checkPressed)
{
    if (checkPressed == true) {
        if (key == sf::Keyboard::Up)
            up = true;
        if (key == sf::Keyboard::Down)
            down = true;
        if (key == sf::Keyboard::Left)
            left = true;
        if (key == sf::Keyboard::Right)
            right = true;
    }

    if (checkPressed == false) {
        up = false;
        down = false;
        left = false;
        right = false;
    }
}

void Cvijet::Bee::fly(sf::Vector2f move)
{
    body.move(move);
    head.move(move);
    sting.move(move);
    wing1.move(move);
    wing2.move(move);
}

void Cvijet::Bee::highlight_flower(float x, float y)
{
    Cvijet fl(window);
    sf::Vector2f pos = head.getPosition();
    if (pos.x >= x - 20 && pos.x <= x + 15 && pos.y >= y - 30 && pos.y <= y + 10) {
        Color c = Color::Red;
        fl.draw_flower(x, y, c);
        mid = true;
    }
}

void Cvijet::Bee::update()
{
    sf::Vector2f movement;
    if (up)
        movement.y -= 3.0f;
    if (down)
        movement.y += 3.0f;
    if (left)
        movement.x -= 3.0f;
    if (right) {
        movement.x += 3.0f;
    }

   
    
    if (mid) {
        text.setString("Success!");
    }
    
    highlight_flower(100, 460);
    highlight_flower(50, 440);
    highlight_flower(200, 450);
    highlight_flower(500, 460);
    highlight_flower(600, 500);
    highlight_flower(450, 430);
    highlight_flower(750, 500);
    highlight_flower(60, 500);
    highlight_flower(150, 490);
    highlight_flower(510, 500);
    
    fly(movement);
    window->draw(text);
}

