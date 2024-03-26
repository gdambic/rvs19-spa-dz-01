#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window(window)
{
}

void Cvijet::draw()
{
	sf::RectangleShape rect(sf::Vector2f(5, 200)); 
    rect.setFillColor(sf::Color(33, 77, 20));
    rect.setPosition(200, 250); 


    sf::CircleShape circle(25.f); 
    circle.setFillColor(sf::Color(230, 216, 110));
    circle.setPosition(175, 200);

    circle.setOutlineThickness(30.f);
    circle.setOutlineColor(sf::Color(214, 153, 224));

    


    sf::ConvexShape leaf;
    leaf.setFillColor(sf::Color(33, 77, 20));
    leaf.setPosition(115, 350);


    leaf.setPointCount(4);

    leaf.setPoint(0, sf::Vector2f(20.f, 40.f));
    leaf.setPoint(1, sf::Vector2f(75.f, 10.f)); 
    leaf.setPoint(2, sf::Vector2f(125.f, 60.f));
    leaf.setPoint(3, sf::Vector2f(140.f, 20.f));


    float time_elapsed = frameClock.getElapsedTime().asSeconds();
    float animation_time = fmod(time_elapsed, cycle) / cycle; 
    

    float curr_r;
    if (animation_time < 0.5f) {
        curr_r = max_r - (max_r - min_r) * (animation_time / 0.5f);
    }
    else {
        curr_r = min_r + (max_r - min_r) * ((animation_time - 0.5f) / 0.5f);
    }

    sf::CircleShape sun(curr_r);
    sun.setFillColor(sf::Color(255, 255, 0));
    sun.setPosition(25,25);


    window->draw(rect);
    window->draw(circle);
    window->draw(leaf);
    window->draw(sun);
}
