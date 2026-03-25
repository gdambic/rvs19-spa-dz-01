#include "Cvijet.h"
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow& win) : window(win)
{
    float centerX = window.getSize().x / 2.0f;
    float centerY = window.getSize().y / 2.0f;

    center.setRadius(40);
    center.setFillColor(sf::Color::Yellow);
    center.setOrigin(40, 40);
    center.setPosition(centerX, centerY);

    for (int i = 0; i < 6; i++)
    {
        petals[i].setRadius(30);
        petals[i].setFillColor(sf::Color::Cyan);
        petals[i].setOrigin(30, 30);
    }
    stem.setSize(sf::Vector2f(10, 150));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(centerX - 5, centerY + 40);


    leaf.setPointCount(3);
    leaf.setPoint(0, sf::Vector2f(centerX, centerY + 80));
    leaf.setPoint(1, sf::Vector2f(centerX + 100, centerY + 50));
    leaf.setPoint(2, sf::Vector2f(centerX + 20, centerY + 120));
    leaf.setFillColor(sf::Color::Green);


    sunRadius = 20.0f;
    shrinking = true;

    sun.setRadius(sunRadius);
    sun.setFillColor(sf::Color::Yellow);
    sun.setOrigin(sunRadius, sunRadius);
    sun.setPosition(70, 70);

    time = 0.0f;

}

void Cvijet::draw()
{ 

    float deltaTime = frameClock.restart().asSeconds();
    time += deltaTime;

    

    
    float speed = 20.0f;

    
    if (shrinking)
    {
        sunRadius -= speed * deltaTime;
        if (sunRadius <= 15.0f)
            shrinking = false;
    }
    else
    {
        sunRadius += speed * deltaTime;
        if (sunRadius >= 20.0f)
            shrinking = true;
    }

    
    sun.setRadius(sunRadius);
    sun.setOrigin(sunRadius, sunRadius); 
    sun.setPosition(70, 70);

    
    window.draw(sun);

    float centerX = center.getPosition().x;
    float centerY = center.getPosition().y;
    for (int i = 0; i < 6; i++)
    {
        float baseAngle = i * 60 * 3.14159f / 180;
        float sway = sin(time * 2.0f) * 0.2f;
        float x = centerX + cos(baseAngle + sway) * 90;
        float y = centerY + sin(baseAngle + sway) * 90;
        petals[i].setPosition(x, y);
        window.draw(petals[i]);
    }

        window.draw(center);
        window.draw(stem);
        window.draw(leaf);
}
