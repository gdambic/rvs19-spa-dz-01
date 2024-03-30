#include "Pozadina.h"

Pozadina::Pozadina(sf::RenderWindow& window)
{
    // Nebo
    sky.setSize(sf::Vector2f(window.getSize().x, window.getSize().y * 0.75f));
    sky.setFillColor(sf::Color(135, 206, 235)); 

    // Zemlja
    ground.setSize(sf::Vector2f(window.getSize().x, window.getSize().y * 0.25f));
    ground.setFillColor(sf::Color(0, 100, 0)); 
    ground.setPosition(0, window.getSize().y * 0.75f); 
}

void Pozadina::draw(sf::RenderWindow& window)
{
 
    window.draw(sky);
    window.draw(ground);
}
