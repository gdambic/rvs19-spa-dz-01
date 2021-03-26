#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;
Cvijet::Cvijet(){
    //default
}

Cvijet::Cvijet(string imgDirectoryShrek, string imgDirectoryFiona, string imgDirectoryDonkie, RenderWindow *window) : mWindow(window)
{
    if (!pTextureShrek.loadFromFile(imgDirectoryShrek) && !pTextureFiona.loadFromFile(imgDirectoryFiona) && !pTextureDonkie.loadFromFile(imgDirectoryDonkie))
    {
        cerr << "Cannot load texture" << endl;
    }
    pTextureFiona.loadFromFile(imgDirectoryFiona);
    pTextureDonkie.loadFromFile(imgDirectoryDonkie);
    pSpriteShrek.setTexture(pTextureShrek);
    pSpriteFiona.setTexture(pTextureFiona);
    pSpriteDonkie.setTexture(pTextureDonkie);
}

float Cvijet::get_xShrek()
{
    return xShrek;
}

float Cvijet::get_yShrek()
{
    return yShrek;
}

void Cvijet::drawCvijet()
{
    rectangle.setSize(Vector2f(300, 20));
    rectangle.setFillColor(Color::Green);
    rectangle.setRotation(90);
    rectangle.setPosition(200, 250);
    mWindow->draw(rectangle);

    shape.setPointCount(5);
    shape.setFillColor(Color::Green);
    shape.setPoint(0, sf::Vector2f(0.f, 0.f));
    shape.setPoint(1, sf::Vector2f(150.f, 100.f));
    shape.setPoint(2, sf::Vector2f(120.f, 90.f));
    shape.setPoint(3, sf::Vector2f(30.f, 100.f));
    shape.setPoint(4, sf::Vector2f(0.f, 50.f));
    shape.setPosition(360, 350);
    shape.setRotation(120);
    mWindow->draw(shape);

    circle.setRadius(70);
    circle.setFillColor(Color::Yellow);
    circle.setOutlineThickness(45);
    circle.setOutlineColor(Color::Red);
    circle.setPosition(120, 100);
    mWindow->draw(circle);
}

void Cvijet::drawShrek()
{
    xShrek = pSpriteShrek.getPosition().x;
    yShrek = pSpriteShrek.getPosition().y;
    mWindow->draw(pSpriteShrek);
}

void Cvijet::drawFiona()
{
    pSpriteFiona.setPosition(1000, 500);
    mWindow->draw(pSpriteFiona);
}


void Cvijet::moveShrek(char direction, float speed)
{
    if (direction == 'w')
    {
        pSpriteShrek.move(0, -speed);
    } 
    else if (direction == 's')
    {
        pSpriteShrek.move(0, speed);
    }
    else if (direction == 'a')
    {
        pSpriteShrek.move(-speed, 0);
    }
    else if (direction == 'd')
    {
        pSpriteShrek.move(speed, 0);
    }
}

void Cvijet::drawText(string fontDirectory)
{
    if (!font.loadFromFile(fontDirectory))
    {
        cerr << "Cannot load font";
    }
    text.setFont(font);
    text.setString("PRONADI FIONU ??? (NAVIGIRANJE SHREKA SA: WSAD)");
    text.setCharacterSize(30);
    text.setFillColor(Color::Green);
    text.setStyle(Text::Bold);
    text.setPosition(300, 0);
    mWindow->draw(text);
}

void Cvijet::drawDonkie()
{
    mWindow->draw(pSpriteDonkie);
}

void Cvijet::moveDonkie()
{
    pomagac += 5;
    if (pomagac <= 500)
    {
        x += 5;
        pSpriteDonkie.setPosition(x, y);

    }
    else if (pomagac <= 1000)
    {
        y -= 5;
        pSpriteDonkie.setPosition(x, y);

    }
    else if (pomagac <= 1500)
    {
        x -= 5;
        pSpriteDonkie.setPosition(x, y);

    }
    else if (pomagac <= 2000)
    {
        y += 5;
        pSpriteDonkie.setPosition(x, y);
    }
    else
    {
        pomagac = 0;
    }
}