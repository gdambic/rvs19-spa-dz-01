#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Cvijet
{
private:
    sf::RenderWindow* window;
    sf::CircleShape centar;
    sf::CircleShape centarCvijeta;
    std::vector<sf::CircleShape> latica;
    sf::RectangleShape stem;
    sf::ConvexShape list;

    float minRadius = 50.f;
    float maxRadius = 60.f;
    float trenutniRadius = minRadius;
    bool rast = true;
    sf::Clock animationClock;

    void initializeFlower();

public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};

