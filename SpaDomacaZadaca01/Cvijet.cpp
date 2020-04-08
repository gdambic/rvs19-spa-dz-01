#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
    
    this->window = window;

}

void Cvijet::draw() const {
    sf::CircleShape shape(35); 
    shape.setFillColor(sf::Color(255, 255, 0));
    shape.setOutlineThickness(30); 
    shape.setOutlineColor(sf::Color(255, 0, 0)); 
    shape.setPosition(50, 70);
    sf::RectangleShape line(sf::Vector2f(100.f, 5.f));
    line.rotate(90);
    line.setPosition(88, 170);
    line.setFillColor(sf::Color(50, 205, 50));
    sf::ConvexShape convex;
    convex.setPointCount(4);
    convex.setPoint(0, sf::Vector2f(0, 0));
    convex.setPoint(1, sf::Vector2f(110, 25));
    convex.setPoint(2, sf::Vector2f(150, 75));
    convex.setPoint(3, sf::Vector2f(80, 65));
    convex.rotate(130);
    convex.setFillColor(sf::Color(50, 205, 50));
    convex.setPosition(240, 140);
    sf::CircleShape sunce(15);
    sunce.setFillColor(sf::Color(255, 255, 0));
    sunce.setPosition(10, 10);
    sf::Time start = frameclock.getElapsedTime();
    if ((start.asSeconds() > 2.0f) & (start.asSeconds() < 2.3f))
    {
        sunce.setRadius(10.f);
    }
    else if (start.asSeconds() > 2.5f)
    {
        sunce.setRadius(15.f);

    }
    window-> draw(sunce);
    window -> draw(shape);
    window -> draw(line);
    window -> draw(convex);

}



