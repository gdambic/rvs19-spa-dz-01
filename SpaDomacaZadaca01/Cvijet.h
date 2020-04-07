#pragma once
#include <SFML/Graphics.hpp>



using namespace std;

class Cvijet
{
private:
    sf::RenderWindow* window;
    sf::Clock frameclock;
    sf::CircleShape shape;
    sf::RectangleShape line;
    sf::ConvexShape convex;
    sf::CircleShape sunce;
public:
    Cvijet(sf::RenderWindow* window);
    void draw() const;



};

