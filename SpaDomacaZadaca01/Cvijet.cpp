#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window) : win(window)
{
}

void Cvijet::loadTextures()
{
    GrassTexture.loadFromFile("GrassTexture.png");
    ConcreteTexture.loadFromFile("ConcreteTexture.png");
    SkyTexture.loadFromFile("SkyTexture.png");
    SunTexture.loadFromFile("SunTexture.png");
    SkateTexture.loadFromFile("SkejterTexture.png");
    HouseTexture.loadFromFile("HouseTexture.png");
    FlowersTexture.loadFromFile("FlowersTexture.png");
}

void Cvijet::draw()
{
    loadTextures();
    
    //nacrtaj nebo
    sf::RectangleShape sky(sf::Vector2f(800.f, 350.f));
    sky.setTexture(&SkyTexture);
    win.draw(sky);

    //nacrtaj travu
    sf::RectangleShape grass(sf::Vector2f(800.f, 250.f));
    grass.setTexture(&GrassTexture);
    grass.setPosition(sf::Vector2f(0.f, 350.f));
    win.draw(grass);

    //nacrtaj kucu
    sf::RectangleShape house(sf::Vector2f(500.f, 500.f));
    house.setTexture(&HouseTexture);
    win.draw(house);

    //nacrtaj sunce
    sf::CircleShape sunce(80.f);
    sunce.setTexture(&SunTexture);
    sunce.setPosition(650, -50);
    win.draw(sunce);

    //nacrtaj quarter pipe
    sf::RectangleShape quar(sf::Vector2f(800.f, 600.f));
    quar.setTexture(&ConcreteTexture);
    win.draw(quar);

    //nacrtaj skejtic
    sf::RectangleShape skate(sf::Vector2f(120.f, 120.f));
    skate.setTexture(&SkateTexture);
    skate.setPosition(skejticX, skejticY);
    win.draw(skate);

    //nacrtaj cvijece
    sf::RectangleShape cvijece(sf::Vector2f(800.f, 360.f));
    cvijece.setTexture(&FlowersTexture);
    cvijece.setPosition(0, 240);
    win.draw(cvijece);

    sf::Time elapsed = frameClock.getElapsedTime();
    if (elapsed.asMicroseconds() >= 500) {
        if (smjer)
            skejticX += 5;
        if (!smjer)
            skejticX -= 5;
    }

    if (skejticX == 600 || skejticX == 500)
        smjer = !smjer;
}