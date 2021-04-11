#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Cvijet
{
public:
    Cvijet(sf::RenderWindow* window);
    void draw();
private:
    sf::Clock clock;
    sf::RenderWindow* window;
    sf::CircleShape testic;
    void draw_sunce();
    void draw_trup();
    void draw_latice();
    void draw_background()const;

    vector<sf::RectangleShape> efekt;
};
