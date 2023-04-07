#include "Flower.h"


Flower::Flower(sf::RenderWindow* window) {
	this->window = window; 
}

void Flower::draw()
{
    sf::CircleShape center(80.f);
    center.setFillColor(sf::Color::Red);
    center.setOutlineColor(sf::Color::White);
    center.setOutlineThickness(2.f);
    center.setPosition(sf::Vector2f(window->getSize().x / 2 - center.getRadius(),
        window->getSize().y / 2 - center.getRadius()));;

   sf::CircleShape petalShape(60.f);
    petalShape.setFillColor(sf::Color::Yellow);
    petalShape.setOutlineColor(sf::Color::White);
    petalShape.setOutlineThickness(2.f);
    petalShape.setPosition(sf::Vector2f(window->getSize().x / 2 - petalShape.getRadius(),
        window->getSize().y / 2 - petalShape.getRadius()));

    sf::RectangleShape stem(sf::Vector2f(10, 400));
    stem.setPosition(sf::Vector2f(window->getSize().x / 2 - stem.getSize().x / 2, 300));
    stem.setFillColor(sf::Color::Green);
    
    window->draw(stem);
    window->draw(center); 
    window->draw(petalShape);
   
}

