#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {

public:

    Cvijet(sf::RenderWindow* window);
    void draw();

private:

    sf::RenderWindow* window_;
    sf::Clock frameClock_;
    sf::CircleShape sunce_;

};

