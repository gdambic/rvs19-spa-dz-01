#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cvijet {
private:
    sf::RenderWindow* MyWindow;
public:
    Cvijet(sf::RenderWindow* window);
    void draw();
};