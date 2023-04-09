#pragma once
#include <SFML/Graphics.hpp>

class Cvijet {
public:
    Cvijet(sf::RenderWindow* window);
    void draw();

private:
    sf::RenderWindow* m_window;
    sf::CircleShape m_center;
    sf::CircleShape m_petals[15];
    sf::RectangleShape m_stem;  
    sf::CircleShape m_sun;
    sf::RectangleShape m_sky;
    sf::RectangleShape m_ground;
    sf::Clock m_clock;
};