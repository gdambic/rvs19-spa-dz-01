#include "Flower.h"

Flower::Flower(sf::RenderWindow *window) 
{

    this->window = window;

    //Set Entity parameters for head
    Flower::head = sf::CircleShape(50.f);
    Flower::head.setFillColor(sf::Color(180, 180, 0));
    Flower::head.setOutlineThickness(50.f);
    Flower::head.setOutlineColor(sf::Color(255, 0, 0));

    //Set Origin and Position for head
    Flower::head.setOrigin(50.f,50.f);
    Flower::head.setPosition(385.f,200.f);

    //Set Params for stem
    Flower::stem = sf::RectangleShape(sf::Vector2f(400.f, 30.f));
    Flower::stem.setFillColor(sf::Color(0,100,0));
    Flower::stem.setPosition(400.f,200.f);
    Flower::stem.rotate(90.f);

    //BigLeaf
    Flower::leaf1.setPointCount(4);

    sf::Vector2f bigPos = sf::Vector2f(370.f, 500.f);
    float bigScale = 1.5f;

    Flower::leaf1.setPoint(0, bigPos + sf::Vector2f(0.f, 0.f) * bigScale);
    Flower::leaf1.setPoint(1, bigPos + sf::Vector2f(-50.f, -20.f) * bigScale);
    Flower::leaf1.setPoint(2, bigPos + sf::Vector2f(-80.f, -100.f) * bigScale);
    Flower::leaf1.setPoint(3, bigPos + sf::Vector2f(-20.f, -60.f) * bigScale);

    Flower::leaf1.setFillColor(sf::Color(0,140,0));

    //SmallLeaf
    Flower::leaf2.setPointCount(4);
    
    sf::Vector2f smallPos = sf::Vector2f(400.f, 400.f);
    float smallScale = 1.2f;

    Flower::leaf2.setPoint(0, smallPos + sf::Vector2f(0.f, 0.f) * smallScale);
    Flower::leaf2.setPoint(1, smallPos + sf::Vector2f(40.f, -20.f) * smallScale);
    Flower::leaf2.setPoint(2, smallPos + sf::Vector2f(80.f, -100.f) * smallScale);
    Flower::leaf2.setPoint(3, smallPos + sf::Vector2f(20.f, -60.f) * smallScale);

    Flower::leaf2.setFillColor(sf::Color(0,140,0));

    // make sun
    Flower::sun = sf::CircleShape(50.f);
    Flower::sun.setFillColor(sf::Color(255, 255, 0));
    Flower::sun.setPosition(100.f, 100.f);
    Flower::sun.setOrigin(50.f, 50.f);
    

    

}

void Flower::draw() {
    window->draw(stem);
    window->draw(head);
    window->draw(leaf1);
    window->draw(leaf2);

    window->draw(sun);
    Flower::sun.setScale(sin(Flower::frameClock.getElapsedTime().asSeconds()) * 0.4 + 1, sin(Flower::frameClock.getElapsedTime().asSeconds()) * 0.4 + 1);
}