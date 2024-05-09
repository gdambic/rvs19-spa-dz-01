#ifndef CVIJET_H
#define CVIJET_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet {
private:
    RenderWindow* window;
    CircleShape circle;
    CircleShape circleOuter;
    CircleShape sunshine;
    CircleShape moon;
    RectangleShape rectangle;
    ConvexShape triangle;
    ConvexShape triangle2;
    Clock animationClock;  // Clock for controlling animation timing

public:
    Cvijet(RenderWindow* window);
    void update();  // Add update function for animations
    void draw();
};

#endif // CVIJET_H
