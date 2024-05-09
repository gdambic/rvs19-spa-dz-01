#include "Cvijet.h"
#include <cmath>  // Include for sin function

Cvijet::Cvijet(RenderWindow* window) : window(window) {
    // Initialize shapes as before
    circle.setRadius(30);
    circle.setPosition(170, 170);
    circle.setFillColor(Color::Red);

    sunshine.setRadius(150);
    sunshine.setPosition(600, -150);
    sunshine.setFillColor(Color::Yellow);

    moon.setRadius(85);
    moon.setPosition(-150, -85);
    moon.setFillColor(Color::White);


    circleOuter.setRadius(100);
    circleOuter.setPosition(100, 100);
    circleOuter.setFillColor(Color::Yellow);

    rectangle.setSize(Vector2f(14, 300));
    rectangle.setPosition(200, 200);
    rectangle.setFillColor(Color::Green);

    triangle.setPointCount(3);
    triangle.setPoint(0, Vector2f(0, 0));
    triangle.setPoint(1, Vector2f(200, -20));
    triangle.setPoint(2, Vector2f(0, 75));
    triangle.setPosition(200, 350);
    triangle.setFillColor(Color::Green);

    triangle2.setPointCount(3);
    triangle2.setPoint(0, Vector2f(0, 0));
    triangle2.setPoint(1, Vector2f(-100, -20));
    triangle2.setPoint(2, Vector2f(0, 75));
    triangle2.setPosition(200, 350);
    triangle2.setFillColor(Color::Green);
}

void Cvijet::draw() {
    // Handle animation within draw
    float time = animationClock.getElapsedTime().asSeconds();
    float xPosSun = 600.0f + 50.0f * time;  // Move right over time
    float xPosMoon = -150.0f + 50.0f * time;  // Move right over time

    // Horizontal movement

    if (xPosMoon - 100 > window->getSize().x) {
        animationClock.restart();  // Reset clock to loop animation
    }
    sunshine.setPosition(xPosSun, sunshine.getPosition().y);  // Update position
    
    moon.setPosition(xPosMoon, moon.getPosition().y);  // Update position




    window->draw(rectangle);
    window->draw(circleOuter);
    window->draw(sunshine);
    window->draw(moon);
    window->draw(circle);
    window->draw(triangle);
    window->draw(triangle2);
}
