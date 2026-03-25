#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
    Cvijet(sf::RenderWindow* window);
    void draw();

private:
    sf::RenderWindow* m_window;

    sf::CircleShape m_latice;
    sf::CircleShape m_srediste;
    sf::RectangleShape m_stabljika;
    sf::ConvexShape m_list;
    sf::CircleShape m_tocka;
    sf::Clock m_frameClock;
    float m_tockaRadius;
    bool m_growing;
};