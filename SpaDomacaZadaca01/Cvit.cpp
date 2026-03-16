#include "Cvit.h"
Cvit::Cvit(sf::RenderWindow& window)
{
	this->window = &window;
}
void Cvit::draw()
{
    sf::Clock frameClock;
    
    window->setFramerateLimit(60);
    
    while (window->isOpen())
    {        
        sf::CircleShape sun(50.f);
        sun.setFillColor(sf::Color::Yellow);
        sun.setOutlineThickness(5);
        sun.setOutlineColor(sf::Color(255, 165, 0));
        sun.setOrigin(50.f, 50.f);
        sun.setPosition(100.f, 100.f);
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        rectangle.setSize(sf::Vector2f(10000.f, 10000.f));
        rectangle.setFillColor(sf::Color(173, 216, 230));
        sf::RectangleShape floor(sf::Vector2f(120.f, 50.f));
        floor.setSize(sf::Vector2f(10000.f, 10000.f));
        floor.setPosition(0.f, 350.f);
        floor.setFillColor(sf::Color(124, 252, 0));
        sf::RectangleShape stem(sf::Vector2f(10.f, 150.f));
        stem.setFillColor(sf::Color(34, 139, 34));
        stem.setPosition(195.f, 200.f);
        sf::CircleShape center(20.f);
        center.setFillColor(sf::Color::Yellow);
        center.setOrigin(25.f, 25.f);
        center.setPosition(205.f, 205.f);
        sf::CircleShape petal(50.f);
        petal.setFillColor(sf::Color(255, 182, 193));
        petal.setOrigin(30.f, 30.f);
        petal.setPosition(180.f, 180.f);
        sf::CircleShape leaf(15.f);
        leaf.setFillColor(sf::Color(34, 139, 34));
        leaf.setOrigin(30.f, 30.f);
        leaf.setPosition(230.f, 320.f);
        sf::CircleShape leafl(15.f);
        leafl.setFillColor(sf::Color(34, 139, 34));
        leafl.setOrigin(30.f, 30.f);
        leafl.setPosition(200.f, 300.f);
        
        float time = frameClock.getElapsedTime().asSeconds();
        float scale = 1.0f + (0.2f * std::sin(time * 1.0f));
        
        sun.setScale(scale, scale);
        window->draw(rectangle);
        window->draw(floor);
        window->draw(stem);
        window->draw(petal);
        window->draw(center);
        window->draw(leaf);
        window->draw(leafl);
        window->draw(sun);
        window->display();
    }
}