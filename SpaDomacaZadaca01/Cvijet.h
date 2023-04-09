#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
private:
    sf::RenderWindow* Window;
    sf::CircleShape UnutarnjiCvijet;
    sf::CircleShape VanjskiCvijet;
    sf::RectangleShape Stabljika;
    sf::ConvexShape List;
    sf::CircleShape Sunce;
    sf::Clock vrijeme;
    sf::Time protekloVrijeme;

public:
    Cvijet(sf::RenderWindow* Window);
    sf::CircleShape set_Sunce();
    sf::CircleShape set_UnutarnjiCvijet();
    sf::CircleShape set_VanjskiCvijet();
    sf::RectangleShape set_Stabljika();
    sf::ConvexShape set_List();
    void draw();
    void animateSunce();
};
