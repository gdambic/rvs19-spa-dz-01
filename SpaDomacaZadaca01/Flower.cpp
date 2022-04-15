#include "Flower.h"

Flower::Flower(sf::RenderWindow &window) 
{

    this->window = window;

    //Set Entity parameters for head
    FLower::head = sf::CircleShape(50.f);
    Flower::head.setFillColor(sf::Color(50, 150, 250));
    Flower::head.setOutlineThickness(20.f);
    Flower::head.setOutlineColor(sf::Color(150, 250, 50));

    //Set Origin and Position for head
    Flower::Head.setOrigin(30.f,30.f);
    Flower::Head.setPosition(80.f,80.f);

    //Set Params for stem
    Flower::stem = sf::RecatngleShape(sf::Vector2f(520.f, 20.f));
    FLower::stem.setFillColor(sf::Color(0,0,255));
    Flower::stem.setPosition(80.f,80.f);
    Flower::stem.rotate(90.f);

    //BigLeaf
    Flower::leaf1.setPointCount(4):

    Flower::leaf1.setPoint(0, sf::Vector2f(80.f, 0.f));
    Flower::leaf1.setPoint(1, sf::Vector2f(100.f, 40.f));
    Flower::leaf1.setPoint(2, sf::Vector2f(100.f, 140.f));
    Flower::leaf1.setPoint(3, sf::Vector2f(80.f, 90.f));

    Flower::leaf1.setFillColor(sf::Color(0,0,255));

    //SmallLeaf
    Flower::leaf2.setPointCount(4):

    Flower::leaf2.setPoint(0, sf::Vector2f(80.f, 0.f));
    Flower::leaf2.setPoint(1, sf::Vector2f(40.f, 50.f));
    Flower::leaf2.setPoint(2, sf::Vector2f(20.f, 100.f));
    Flower::leaf2.setPoint(3, sf::Vector2f(80.f, 60.f));

    Flower::leaf2.setFillColor(sf::Color(0,0,255));
}

Flower::Draw() {
    window.draw(stem);
    window.draw(flower);
    window.draw(leaf1);
    window.draw(leaf2);
}