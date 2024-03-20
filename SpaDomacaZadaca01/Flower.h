#pragma once
#include <SFML/Graphics.hpp>

class Flower {
public:
    Flower(sf::RenderWindow* window);
    void draw();

private:
    sf::RenderWindow* m_window;
    sf::CircleShape m_center;
    sf::CircleShape m_petals;
    sf::RectangleShape m_stem;
    sf::ConvexShape m_leaf;
};
