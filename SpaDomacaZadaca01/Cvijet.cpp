#include "Cvijet.h"
#include "Petal.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;

    //VELICINE PUPOLJKA
    head.setRadius(50.f);
    head.setFillColor(sf::Color(sf::Color::Yellow));
    head.setPosition(350.f, 300.f);
    head.setOutlineColor(sf::Color(200, 200, 0));
    head.setOutlineThickness(10.f);

    //VELICINE PETELJKE
    stem.setSize(sf::Vector2f(10.f,200.f));
    stem.setFillColor(sf::Color::Green);
    stem.setOutlineColor(sf::Color(0, 100, 0));
    stem.setOutlineThickness(2.f);
    stem.setPosition(395.f, 400.f);


    //POSTAVLJANJE LSITA
    leaf.setPointCount(6);
    leaf.setPoint(0,sf::Vector2f(0, 0));
    leaf.setPoint(1,sf::Vector2f(20, -10));
    leaf.setPoint(2,sf::Vector2f(50, -15));
    leaf.setPoint(3,sf::Vector2f(80, 0));
    leaf.setPoint(4,sf::Vector2f(50, 15));
    leaf.setPoint(5,sf::Vector2f(20, 10));      
    leaf.setFillColor(sf::Color::Green);
    leaf.setOutlineThickness(3);
    leaf.setOutlineColor(sf::Color(0, 100, 0));
    leaf.setPosition(400.f, 500.f);


    //POSTAVLJANJE SUNCA
    sun.setRadius(50.f);
    sun.setFillColor(sf::Color(255, 200, 0));
    sun.setPosition(150.f, 100.f);
    sun.setOutlineColor(sf::Color::Yellow);
    sun.setOutlineThickness(10.f);
    sun.setOrigin(75.f, 50.f);

    for (int i = 0; i < 10; i++) //napravi 10 latica 
    {
        petals[i].set_position(400.f, 350.f); //cenatr cvijeta
        petals[i].set_rotation(i * 36.f); //360 /10
    }

}

void Cvijet::draw() {


   
    this->window->draw(sun);
    this->window->draw(leaf);
    this->window->draw(stem);
    this->window->draw(head);
    for (int i = 0; i < 10; i++) //koristi draw function unutar petal da nacrta 10 latica
    {
        petals[i].draw(*this->window);
    }
 

    float time = clock.getElapsedTime().asSeconds();
    float pulse = std::sin(time * 2.f) * 0.3;
    float new_radius = sun.getRadius() + pulse;

    sun.setRadius(new_radius);
    sun.setOrigin(new_radius, new_radius);


}