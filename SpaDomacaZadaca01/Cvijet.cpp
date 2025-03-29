#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) 
{
    this->window = window;
    clock.restart();
}

float Cvijet::get_oscillationProgress(float progress) 
{
    return std::sin(progress * PI);
}

float Cvijet::get_current_size(float minSize, float maxSize, float oscillationProgress) 
{
    return minSize + (maxSize - minSize) * (oscillationProgress + 1.f) / 2.f;
}

void Cvijet::sun_animate(sf::CircleShape& sun, float minSize, float maxSize, float duratation) 
{
    elapsed_time = clock.getElapsedTime(); 
    float progress_sun = elapsed_time.asSeconds() / duratation;
    
    if(progress_sun > 1.f)
    {
        clock.restart();
        progress_sun = 0.f;
    }

    float op_sun = get_oscillationProgress(progress_sun);
    float currentSize_sun = get_current_size(minSize, maxSize, op_sun);
    
    sun.setRadius(currentSize_sun);  
    sun.setOrigin(currentSize_sun, currentSize_sun);
}


void Cvijet::draw() 
{
    elapsed_time = clock.getElapsedTime(); // Update time

    // Sun
    sf::CircleShape sun(15.f);
    sun.setPosition(40, 40);
    sun.setFillColor(yellow);

    // Grana
    sf::RectangleShape grana(sf::Vector2f(150.f, 5.f));
    grana.setFillColor(green);
    grana.rotate(90.f); 
    grana.setPosition(150.f, 200.f); 

    // Cvijet
    sf::CircleShape flower(40.f);
    flower.setFillColor(green);
    flower.setOutlineThickness(10.f);
    flower.setOutlineColor(red);

    float cvijetOffsetX = grana.getPosition().x - flower.getRadius();  
    float cvijetOffsetY = grana.getPosition().y - grana.getSize().y / 2 - flower.getRadius();
    flower.setPosition(cvijetOffsetX, cvijetOffsetY);

    // Leaf
    sf::ConvexShape leaf;
    leaf.setPointCount(4); 
    leaf.setPoint(0, sf::Vector2f(0.f, 0.f));      
    leaf.setPoint(1, sf::Vector2f(25.f, -50.f));  
    leaf.setPoint(2, sf::Vector2f(42.f, 0.f));    
    leaf.setPoint(3, sf::Vector2f(25.f, 75.f));   
    leaf.rotate(-120.f);
    leaf.setPosition(150.f, 200.f); 
    leaf.setFillColor(green);       
    leaf.setPosition(grana.getPosition().x + 50, grana.getPosition().y + 100);

    // Animations
    sun_animate(sun, 15, 20, 1.f);

    window->draw(sun);
    window->draw(grana);
    window->draw(flower);
    window->draw(leaf);
}