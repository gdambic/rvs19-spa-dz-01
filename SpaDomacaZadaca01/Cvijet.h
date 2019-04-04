#pragma once
#include <vector>
#include <math.h>


class Cvijet {
private:
    sf::RenderWindow *window;
    sf::Clock clock;
    bool radiusDirectionPlus = true;
    float radius = 40.f;
    
public:
    Cvijet(sf::RenderWindow *window);
    void draw();
};




