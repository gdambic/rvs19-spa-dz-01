#include "Cvijet.h"
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow* win)
{
    window = win;

    x = 400;
    y = 300;
    radius = 80;
    angle = 0;

    for (int i = 0; i < 8; i++)
    {
        sf::CircleShape petal(radius / 3);
        petal.setFillColor(sf::Color::Magenta);
        petal.setOrigin(radius / 3, radius / 3);
        petals.push_back(petal);
    }

    center.setRadius(radius / 4);
    center.setFillColor(sf::Color::Yellow);
    center.setOrigin(radius / 4, radius / 4);
    center.setPosition(x, y);
}

void Cvijet::draw()
{
    angle += 0.02f;

    
    float stemHeight = 120;

    sf::RectangleShape stem(sf::Vector2f(6, stemHeight));
    stem.setFillColor(sf::Color(0, 180, 0));
    stem.setOrigin(3, 0);
    stem.setPosition(x, y);
    window->draw(stem);

   
    float centerX = x;
    float centerY = y;

    
    centerY = y; 

    center.setPosition(centerX, centerY);

    
    for (int i = 0; i < petals.size(); i++)
    {
        float petalAngle = angle + i * (2 * 3.14159f / petals.size());

        float px = centerX + cos(petalAngle) * radius;
        float py = centerY + sin(petalAngle) * radius;

        petals[i].setPosition(px, py);
        petals[i].setScale(1.2f, 1.8f);
        petals[i].setFillColor(sf::Color(255, 105, 180));

        window->draw(petals[i]);
    }

    
    window->draw(center);
}