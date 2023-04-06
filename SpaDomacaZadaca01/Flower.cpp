#include "Flower.h"
#include <vector>


Flower::Flower(sf::RenderWindow* window)
{

    this->window = window;
    this->FlowerHead = sf::CircleShape(60.f);
    this->Stem = sf::ConvexShape();
    this->Moon = sf::CircleShape();
    this->Leaf = sf::ConvexShape();
    this->frameClock = sf::Clock();
    this->constant = 1.f;
    this->Octagon = sf::CircleShape(60.f, 8);
}

void Flower::draw()
{
    float time = frameClock.getElapsedTime().asSeconds(); 
    float scale = 1 + sin(time) * 0.5f; 
    Moon.setRadius(60.f * scale); 
    Moon.setPosition(30, 30);
    Moon.setFillColor(sf::Color::White);
    window->draw(Moon);

  



    Stem.setPointCount(4);
    Stem.setPoint(0, sf::Vector2f(250.f, 600.f));
    Stem.setPoint(1, sf::Vector2f(250.f, 200.f));
    Stem.setPoint(2, sf::Vector2f(300.f, 200.f));
    Stem.setPoint(3, sf::Vector2f(300.f, 600.f));
    Stem.setFillColor(sf::Color::Green);
    window->draw(Stem);

    Leaf.setPointCount(3);
    Leaf.setPoint(0, sf::Vector2f(250.f, 500.f));
    Leaf.setPoint(1, sf::Vector2f(350.f, 200.f));
    Leaf.setPoint(2, sf::Vector2f(300.f, 600.f));
    Leaf.setOutlineThickness(1.f);
    Leaf.setOutlineColor(sf::Color::White);
    Leaf.setFillColor(sf::Color::Green);
    window->draw(Leaf);

    FlowerHead.setPosition(210.f, 160.f);
    FlowerHead.setFillColor(sf::Color::Magenta);
    FlowerHead.setOutlineColor(sf::Color::White);
    window->draw(FlowerHead);

    Octagon.setPosition(210.f, 160.f);
    Octagon.setFillColor(sf::Color::Yellow);
    window->draw(Octagon);
}



sf::CircleShape Flower::get_Moon() const
{
    return Moon;
}

void Flower::set_Moon(const sf::CircleShape Moon)
{
    this->Moon = Moon;
}

sf::CircleShape Flower::get_FlowerHead() const
{
    return FlowerHead;
}
void Flower::set_FlowerHead(const sf::CircleShape FlowerHead)
{
    this->FlowerHead = FlowerHead;
}

sf::ConvexShape Flower::get_Stem() const
{
    return Stem;
}

void Flower::set_Stem(const sf::ConvexShape Stem)
{
    this->Stem = Stem;
}

sf::ConvexShape Flower::get_Leaf() const
{
    return Leaf;
}

void Flower::set_Leaf(const sf::ConvexShape Leaf)
{
    this->Leaf = Leaf;
}


float Flower::get_const() const
{
    return constant;
}

void Flower::set_const()
{
    this->constant = constant;
}

sf::CircleShape Flower::get_Octagon() const
{
    return Octagon;
}

void Flower::set_Octagon(const sf::CircleShape Octagon)
{
    this->Octagon = Octagon;
}

