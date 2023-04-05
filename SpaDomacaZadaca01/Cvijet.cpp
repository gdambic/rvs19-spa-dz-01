#include "Cvijet.h"

Cvijet::Cvijet(float x, float y)
{

    center.setRadius(30);
    center.setFillColor(sf::Color::Yellow);
    center.setOutlineColor(sf::Color::Black);
    center.setOutlineThickness(2);
    sf::Vector2f centerPosition(119, 119);
    center.setPosition(centerPosition);

    petal.setPointCount(4);
    petal.setPoint(0, sf::Vector2f(30,0));
    petal.setPoint(1, sf::Vector2f(60,30));
    petal.setPoint(2, sf::Vector2f(30,60));
    petal.setPoint(3, sf::Vector2f(0,30));
    petal.setFillColor(sf::Color::Magenta);
    petal.setOutlineColor(sf::Color::Black);
    petal.setOutlineThickness(2);
    sf::Vector2f petalPosition(150, 150);
    petal.setPosition(petalPosition);

    stem.setSize(sf::Vector2f(25,200));
    stem.setFillColor(sf::Color::Green);
    sf::Vector2f stemPosition(137,175);
    stem.setPosition(stemPosition);

    cup.setSize(sf::Vector2f(100, 70));
    cup.setFillColor(sf::Color(101, 67, 33));
    sf::Vector2f cupPosition(100, 310);
    cup.setPosition(cupPosition);
}

void Cvijet::draw(sf::RenderWindow& window) {

    window.draw(this->center);
    window.draw(this->stem);
    window.draw(this->cup);
    for (int i = 0; i < 5; ++i)
    {
        window.draw(this->petal);
        this->petal.rotate(42);
    }
}

void Cvijet::user_movement(float speed, sf::RenderWindow& window)
{
    float offsetX = 0;
    float offsetY = 0;

    while (window.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            offsetX = -speed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            offsetX = speed;
        }
        else
        {
            offsetX = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            offsetY = -speed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            offsetY = speed;
        }
        else
        {
            offsetY = 0;
        }

        if (center.getPosition().x + offsetX < 0)
        {
            offsetX = -center.getPosition().x; 
        }
        if (center.getPosition().x + offsetX > window.getSize().x - center.getRadius())
        {
            offsetX = window.getSize().x - center.getRadius() - center.getPosition().x; 
        }
        if (center.getPosition().y + offsetY < 0)
        {
            offsetY = -center.getPosition().y; 
        }
        if (center.getPosition().y + offsetY > window.getSize().y - center.getRadius())
        {
            offsetY = window.getSize().y - center.getRadius() - center.getPosition().y; 
        }

        
        center.setPosition(center.getPosition().x + offsetX, center.getPosition().y + offsetY);
        petal.setPosition(petal.getPosition().x + offsetX, petal.getPosition().y + offsetY);
        stem.setPosition(stem.getPosition().x + offsetX, stem.getPosition().y + offsetY);
        cup.setPosition(cup.getPosition().x + offsetX, cup.getPosition().y + offsetY);

        
        window.clear(sf::Color::White);
        draw(window);
        window.display();
    }
   
}
