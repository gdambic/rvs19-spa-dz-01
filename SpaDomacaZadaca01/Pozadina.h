#pragma once
#include <SFML/Graphics.hpp>
class Pozadina
{
private:
    sf::RectangleShape sky;
    sf::RectangleShape ground;

public:
    Pozadina(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
};

