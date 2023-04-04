#define _USE_MATH_DEFINES
#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
    

    if (!stem_texture.loadFromFile("texture_01.jpg"))
    {
        std::cout << "err" << std::endl;
    }
    if (!center_texture.loadFromFile("tucakPt2detalj.jpg"))
    {
        std::cout << "err" << std::endl;
    }
    if (!petal_texture.loadFromFile("petalTest2.jpg"))
    {
        std::cout << "err" << std::endl;
    }
    if (!leaf_texture.loadFromFile("leafTexturedolszadnjiputvnwoghwoh.jpg"))
    {
        std::cout << "err" << std::endl;
    }
    if (!grass_texture.loadFromFile("grassTexture.jpg"))
    {
        std::cout << "err" << std::endl;
    }
}

void Cvijet::draw(sf::RenderWindow& window)
{
   

    static sf::CircleShape sun(50.f);
    static sf::Vector2f sunPosition(300.f, 100.f);
    static double xVelocity = 3;
    static double yVelocity = 3;

    
    if (sunPosition.x + sun.getRadius() >= window.getSize().x || sunPosition.x - sun.getRadius() <= 0)
    {
        xVelocity = -xVelocity;
    }
    
    sunPosition.x += xVelocity;
    sunPosition.y += yVelocity;
    sun.setPosition(sunPosition);

    
    sun.setFillColor(sf::Color::Yellow);
    window.draw(sun);
   
    sf::RectangleShape grass(sf::Vector2f(800.f, 100.f));
    grass.setPosition(sf::Vector2f(0.f, 500.f));
    grass.setTexture(&grass_texture);

    window.draw(grass);

    sf::RectangleShape line(sf::Vector2f(300.f, 5.f));
    line.setPosition(sf::Vector2f(330.f, 280.f));
    line.setTexture(&stem_texture);
    line.rotate(90);
    window.draw(line);
   
  
    double radius_x = 50;
    double radius_y = 20;
    unsigned short quality = 70;

    sf::ConvexShape ellipse;
    ellipse.setPointCount(quality);

    for (unsigned short i = 0; i < quality; i++)
    {
        double rad = (360 / quality * i) / (360 / M_PI / 2);
        double x = cos(rad) * radius_x;
        double y = sin(rad) * radius_y;

        ellipse.setPoint(i, sf::Vector2f(x, y));
    }

    //leaf
   

    double radius_lx = 70;
    double radius_ly = 15;
    unsigned short leaf_quality = 100;

    sf::ConvexShape leaf_ellipse;
    leaf_ellipse.setPointCount(leaf_quality);

    for (unsigned short i = 0; i < leaf_quality; i++)
    {
        double lrad = (360 / leaf_quality * i) / (360 / M_PI / 2);
        double lx = cos(lrad) * radius_lx;
        double ly = sin(lrad) * radius_ly;

        leaf_ellipse.setPoint(i, sf::Vector2f(lx, ly));
    }
    
    ellipse.setPosition(330.f, 230.f);
    ellipse.rotate(90.f);
    ellipse.setTexture(&petal_texture);
    window.draw(ellipse);
    ellipse.rotate(90.f);
    ellipse.setPosition(260.f, 300.f);  
    window.draw(ellipse);
    ellipse.setPosition(400.f, 300.f);
    window.draw(ellipse);
    ellipse.rotate(90.f);
    ellipse.setPosition(330.f, 370.f);
    window.draw(ellipse);
    ellipse.rotate(45.f);
    ellipse.setPosition(375.f, 255.f);
    window.draw(ellipse);
    ellipse.rotate(90.f);
    ellipse.setPosition(285.f, 255.f);
    window.draw(ellipse);
    ellipse.rotate(90.f);
    ellipse.setPosition(285.f, 345.f);
    window.draw(ellipse);
    ellipse.rotate(90.f);
    ellipse.setPosition(375.f, 345.f);
    window.draw(ellipse);

    //ellipse.setTexture(&petal_texture);

    //for (int i = 0; i < 8; i++) {
    //    ellipse.setRotation(45.f * i);
    //    ellipse.setPosition(sf::Vector2f(330.f, 300.f));
    //    window.draw(ellipse);
    //} //ruzno


    sf::CircleShape center(25.f);
    center.setPosition(sf::Vector2f(305.f, 275.f));
    center.setTexture(&center_texture);
    window.draw(center);

    sf::Vector2f leaf_position(280.f, 500.f);
     
    leaf_ellipse.rotate(45.f);
    leaf_ellipse.setPosition(leaf_position);
    leaf_ellipse.setTexture(&leaf_texture);
    window.draw(leaf_ellipse);

   
    
   
}
