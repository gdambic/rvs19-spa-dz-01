#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window(window) {
    // Definirajte cvijet
    flowerHead = sf::CircleShape(134.f, 8);
    flowerHead.setRadius(40);
    flowerHead.setFillColor(sf::Color::Red);
    flowerHead.setPosition(372, 185); 
  
    stem.setSize(sf::Vector2f(10, 100));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(395, 250); 


    leaf.setPointCount(3); // trokut
    leaf.setPoint(0, sf::Vector2f(395, 300));
    leaf.setPoint(1, sf::Vector2f(470, 280));
    leaf.setPoint(2, sf::Vector2f(395, 280));
    leaf.setFillColor(sf::Color::Green);

   
    center.setRadius(15);
    center.setFillColor(sf::Color::Yellow); 
    center.setPosition(397, 211); 
}

void Cvijet::draw() {
    window->draw(stem);
    window->draw(flowerHead);
    window->draw(leaf);
    window->draw(center);

}