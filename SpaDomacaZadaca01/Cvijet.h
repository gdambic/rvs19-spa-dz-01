#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
public:
    Cvijet(sf::RenderWindow* window);
    void draw();
   

private:
    sf::RenderWindow* window;
    sf::CircleShape flowerHead;
    sf::RectangleShape stem;
    sf::ConvexShape leaf;
    sf::CircleShape center; 

    
};
