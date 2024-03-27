#include "Cvijet.h"
Cvijet::Cvijet(sf::RenderWindow* window) : window(window){}

void Cvijet::draw() {

 
    sf::RectangleShape stab(sf::Vector2f(10, 150));
    stab.setFillColor(sf::Color(0, 255, 0)); 
    stab.setPosition(400, 250); 


    sf::CircleShape cvijet(30.f);
    cvijet.setFillColor(sf::Color(255, 255, 0));
    cvijet.setPosition(375, 200);

    cvijet.setOutlineThickness(40.f);
    cvijet.setOutlineColor(sf::Color(250, 0, 0));

    


    sf::ConvexShape list;
    list.setFillColor(sf::Color(0, 255, 0));
    list.setPosition(380, 300);


    list.setPointCount(3);

    list.setPoint(0, sf::Vector2f(20.f, 40.f));
    list.setPoint(1, sf::Vector2f(75.f, 10.f));
    list.setPoint(2, sf::Vector2f(125.f, 60.f));


    
    float protekloVrijeme = frameClock.getElapsedTime().asSeconds();
    float trenutniRadijus;
    float napredakAnimacije = fmod(protekloVrijeme, vrijemeCiklusa) / vrijemeCiklusa;


    
    if (napredakAnimacije < 0.5f) {
        trenutniRadijus = maksimalniRadijus - (maksimalniRadijus - minimalniRadijus) * (napredakAnimacije / 0.5f);
    }
    else {
        trenutniRadijus = minimalniRadijus + (maksimalniRadijus - minimalniRadijus) * ((napredakAnimacije - 0.5f) / 0.5f);
    }


    sf::CircleShape sunce(trenutniRadijus);
    sunce.setFillColor(sf::Color(255, 255, 0));
    sunce.setPosition(25,25);



    window->draw(stab);
    window->draw(cvijet);
    window->draw(list);
    window->draw(sunce);
}

