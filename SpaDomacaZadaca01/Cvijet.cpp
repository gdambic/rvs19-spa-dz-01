#include "Cvijet.h"
#include <vector>
#include <SFML/Graphics.hpp>


Cvijet::Cvijet(RenderWindow* window): window(window)
{   
    float radijus = 14;
    tucak.setRadius(radijus);
    tucak.setFillColor(sf::Color::Yellow);
    tucak.setOrigin(radijus, radijus);
    tucak.setOutlineColor(sf::Color::White);
    tucak.setOutlineThickness(1);

    float radijus2 = 60;
    latice.setRadius(radijus2);
    latice.setFillColor(sf::Color::Red);
    latice.setPointCount(8);
    latice.setOrigin(radijus2, radijus2);
    latice.setOutlineColor(sf::Color::White);
    latice.setOutlineThickness(1);

    float radijus3 = 90;
    octagon.setRadius(radijus3);
    octagon.setFillColor(sf::Color::Magenta);
    octagon.setOrigin(radijus3, radijus3);
    octagon.setPointCount(8);
    octagon.setOutlineColor(sf::Color::White);
    octagon.setOutlineThickness(1);

   
    stabljika.setPointCount(8);
    stabljika.setPoint(0, sf::Vector2f(-2.0f, 30.0f)); 
    stabljika.setPoint(1, sf::Vector2f(-2.0f, 110.0f));
    stabljika.setPoint(2, sf::Vector2f(-2.0f, 110.0f));
    stabljika.setPoint(3, sf::Vector2f(-2.0f, 180.0f));
    stabljika.setPoint(4, sf::Vector2f(2.0f, 180.0f));
    stabljika.setPoint(5, sf::Vector2f(2.0f, 100.0f));
    stabljika.setPoint(6, sf::Vector2f(2.0f, 90.0f));
    stabljika.setPoint(7, sf::Vector2f(2.0f, 80.0f));
    stabljika.setFillColor(sf::Color::Color(0,100,0));

    stabljika2.setPointCount(8);
    stabljika2.setPoint(0, sf::Vector2f(-2.0f, 90.0f));
    stabljika2.setPoint(1, sf::Vector2f(-2.0f, 100.0f));
    stabljika2.setPoint(2, sf::Vector2f(-2.0f, 90.0f));
    stabljika2.setPoint(3, sf::Vector2f(-2.0f, 45.0f));
    stabljika2.setPoint(4, sf::Vector2f(2.0f, 30.0f));
    stabljika2.setPoint(5, sf::Vector2f(2.0f, 110.0f));
    stabljika2.setPoint(6, sf::Vector2f(2.0f, 110.0f));
    stabljika2.setPoint(7, sf::Vector2f(2.0f, 180.0f));
    stabljika2.setFillColor(sf::Color::Color(0, 100, 0));


    stabljika3.setPointCount(10);
    stabljika3.setPoint(0, sf::Vector2f(-2.0f, 60.0f));
    stabljika3.setPoint(1, sf::Vector2f(-2.0f, 220.0f));
    stabljika3.setPoint(2, sf::Vector2f(-2.0f, 60.0f));
    stabljika3.setPoint(3, sf::Vector2f(-2.0f, 220.0f));
    stabljika3.setPoint(4, sf::Vector2f(-2.0f, 360.0f));
    stabljika3.setPoint(5, sf::Vector2f(2.0f, 360.0f));
    stabljika3.setPoint(6, sf::Vector2f(2.0f, 200.0f));
    stabljika3.setPoint(7, sf::Vector2f(140.0f, 30.0f));
    stabljika3.setPoint(8, sf::Vector2f(2.0f, 180.0f));
    stabljika3.setPoint(9, sf::Vector2f(2.0f, 160.0f));
    stabljika3.setFillColor(sf::Color::Color(0, 100, 0));

    stabljika4.setPointCount(10);
    stabljika4.setPoint(0, sf::Vector2f(-2.0f, 360.0f));
    stabljika4.setPoint(1, sf::Vector2f(-2.0f, 200.0f));
    stabljika4.setPoint(2, sf::Vector2f(-140.0f, 30.0f));
    stabljika4.setPoint(3, sf::Vector2f(-2.0f, 180.0f));
    stabljika4.setPoint(4, sf::Vector2f(-2.0f, 160.0f));
    stabljika4.setPoint(5, sf::Vector2f(2.0f, 60.0f));
    stabljika4.setPoint(6, sf::Vector2f(2.0f, 220.0f));
    stabljika4.setPoint(7, sf::Vector2f(2.0f, 60.0f));
    stabljika4.setPoint(8, sf::Vector2f(2.0f, 220.0f));
    stabljika4.setPoint(9, sf::Vector2f(2.0f, 360.0f));
    stabljika4.setFillColor(sf::Color::Color(0, 100, 0));

    
    
}

void Cvijet::draw()
{
    window->draw(stabljika);
    window->draw(stabljika2);
    window->draw(stabljika3);
    window->draw(stabljika4);
    window->draw(octagon);
    window->draw(latice);
    window->draw(tucak);
    
    
}
