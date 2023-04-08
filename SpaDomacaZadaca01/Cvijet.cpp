#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : w(window) 
{ 
    
} 

void Cvijet::nacrtajcvijet()
{ 
    sf::CircleShape sunce(40.f); 
    sunce.setFillColor(sf::Color(255, 255, 0));
    sunce.setPosition(10, 20);
    w->draw(sunce); 

    sf::RectangleShape stabljika(sf::Vector2f(200.f, 8.f)); 
    stabljika.setFillColor(sf::Color(100, 150, 50)); 
    stabljika.setPosition(400, 300);  
    stabljika.rotate(90.f); 
    w->draw(stabljika); 

    sf::CircleShape cvijet(60.f); 
    cvijet.setFillColor(sf::Color(255, 255, 0)); 
    cvijet.setPosition(350, 200); 
    cvijet.setOutlineThickness(40.f); 
    cvijet.setOutlineColor(sf::Color(250, 0, 0)); 
    w->draw(cvijet); 

    sf::CircleShape list(40.f, 3); 
    list.setFillColor(sf::Color(100, 150, 50)); 
    list.setPosition(460, 400); 
    list.rotate(90.f); 
    w->draw(list); 

    sf::Texture slika; 
    slika.loadFromFile("Slike/Pcela.png"); 
    sf::IntRect datoteka(300, 0, 300, 400); 
    sf::Sprite fotografija(slika, datoteka); 
    sf::Clock vrijeme; 
    if (vrijeme.getElapsedTime().asSeconds() > 1.0f) 
    { 
        if (datoteka.left == 600) 
        { 
            datoteka.left = 0; 
        } 
        else
        {
            datoteka.left += 300; 
        } 
        fotografija.setTextureRect(datoteka); 
        vrijeme.restart(); 
    } 
    
} 
