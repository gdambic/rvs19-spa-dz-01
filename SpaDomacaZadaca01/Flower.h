#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;

class Flower
{
private:
    sf::RenderWindow* window;
    sf::Clock frameClock;

public:
    Flower(sf::RenderWindow* window, sf::Clock frameClock);
    void draw_flower();
    

 
};



