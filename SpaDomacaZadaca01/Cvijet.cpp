#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

Cvijet::Cvijet(RenderWindow* window)
{
    this->window = window;
}

void Cvijet::draw()
{

    //Noc
    Texture nightTexture;
    try 
    {
        if (!nightTexture.loadFromFile("textures/noc.jpg")) 
        {
            throw runtime_error("Noc, 404");
        }
    }
    catch (runtime_error error) 
    {
        cout << error.what();
    }
    RectangleShape night(Vector2f(window->getSize().x / 2.f, window->getSize().y));
    night.setTexture(&nightTexture);

    //Dan
    Texture dayTexture;
    try 
    {
        if (!dayTexture.loadFromFile("textures/dan.jpg")) 
        {
            throw runtime_error("Dan, 404");
        }
    }
    catch (runtime_error error) 
    {
        cout << error.what();
    }
    RectangleShape day(Vector2f(window->getSize().x / 2, window->getSize().y));
    day.setTexture(&dayTexture);
    day.setPosition(window->getSize().x / 2.f, 0);

    //Mjesec
    Texture moonTexture;
    try 
    {
        if (!moonTexture.loadFromFile("textures/mjesec.png")) 
        {
            throw runtime_error("Mjesec, 404");
        }
    }
    catch (runtime_error error) 
    {
        cout << error.what();
    }
    CircleShape moon(110.f);
    moon.setTexture(&moonTexture);
    moon.setPosition(10.f, 10.f);

    //Sunce
    Texture sunTexture;
    try 
    {
        if (!sunTexture.loadFromFile("textures/sunce.png")) 
        {
            throw runtime_error("Sunce, 404");
        }
    }
    catch (runtime_error error) 
    {
        cout << error.what();
    }
    CircleShape sun(95.f);
    sun.setTexture(&sunTexture);
    sun.setPosition(530.f, 115.f);

    ////1. CVIJET
    //Stabljika
    RectangleShape stem(Vector2f(5.f, 260.f));
    stem.setFillColor(Color(133, 203, 27));
    stem.setPosition(195.f, 360.f);

    //Sredina
    Texture tuzanTexture;
    try 
    {
        if (!tuzanTexture.loadFromFile("textures/tuzan.png")) 
        {
            throw runtime_error("Tuzan, 404");
        }
    }
    catch (runtime_error error) 
    {
        cout << error.what();
    }
    CircleShape tuzan(50.f);
    tuzan.setTexture(&tuzanTexture);
    tuzan.setPosition(stem.getPosition().x - 47.f, stem.getPosition().y - 88.f);

    //2. CVIJET
    //Stabljika
    RectangleShape stem2(Vector2f(5.f, 260.f));
    stem2.setFillColor(Color(133, 203, 27));
    stem2.setPosition(595.f, 360.f);

    //List
    ConvexShape leaf;
    leaf.setPointCount(4);
    leaf.setPoint(0, Vector2f(30.f, -10.f));
    leaf.setPoint(1, Vector2f(80.f, -30.f));
    leaf.setPoint(2, Vector2f(20.f, 10.f));
    leaf.setPoint(3, Vector2f(0.f, 25.f));
    leaf.setFillColor(Color(133, 203, 27));
    leaf.setPosition(stem2.getPosition().x, stem2.getPosition().y + 70.f);

    //Sredina
    Texture sretanTexture;
    try 
    {
        if (!sretanTexture.loadFromFile("textures/sretan.png")) 
        {
            throw runtime_error("Sretan, 404");
        }
    }
    catch (runtime_error error) 
    {
        cout << error.what();
    }
    CircleShape sretan(40.f);
    sretan.setTexture(&sretanTexture);
    sretan.setPosition(stem2.getPosition().x - 39.f, stem2.getPosition().y - 80.f);

    //Trava
    Texture grassTexture;
    try 
    {
        if (!grassTexture.loadFromFile("textures/trava.png")) 
        {
            throw runtime_error("Trava, 404");
        }
    }
    catch (runtime_error error) 
    {
        cout << error.what();
    }
    RectangleShape grass(Vector2f(800.f, 200.f));
    grass.setTexture(&grassTexture);
    grass.setPosition(0.f, 400.f);

    // Kisa
    int a, b, c, d, e, array[100];
    int part = 1;

    //Pohrana kapljica u rain polju
    RectangleShape rain[200];
    for (int i = 0; i < 100; i++) 
    {
        rain[i].setFillColor(Color::Blue);
    }
    srand(time(NULL));

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            if (event.type == Event::Closed)
                window->close();
        }

        //Rotacija sunca
        sun.setOrigin(sun.getRadius(), sun.getRadius());
        sun.rotate(1);

        window->clear();

        //DIO GDJE KAPLJICE MIRUJU NA VRHU
        //Varijable su inicijalizirane sa random brojem pomocu rand() funkcije
        //Generira se random broj u rangu od 1 do 55 i od 3 do 9
        //setSize() funkcija postavlja sirinu svake kapljice na 3 i random visinu (a)
        //setPosition() funkcija postavlja svaku kapljicu na random x koordinatu i -10 y koordinatu kako bi kapljica bila na vrhu zaslona
        if (part == 1) 
        {
            for (int i = 0; i < 100; i++)
            {
                a = 1 + rand() % (55);
                array[i] = 3 + rand() % (7);
                e = 1 + rand() % (399);
                b = 1 + rand() % (255);
                c = 1 + rand() % (255);
                d = 1 + rand() % (255);
                rain[i].setSize(Vector2f(3, a));
                rain[i].setPosition(e, -10);
                rain[i].setFillColor(Color(157, 207, 225));
            }
        }

        window->draw(night);
        window->draw(day);
        window->draw(moon);
        window->draw(sun);
        window->draw(stem);
        window->draw(leaf);
        window->draw(stem2);
        window->draw(grass);

        //Latice prvog cvijeta
        float petalRadius = 47.f;
        float petalSpacing = 30.f;
        float petalAngle = 0.f;
        for (int i = 0; i < 3; i++) 
        {
            petalAngle += 30.f;
            float angleRad = petalAngle * (M_PI / 90.f);
            float x = petalRadius * cos(angleRad);
            float y = petalRadius * sin(angleRad);
            CircleShape petal(petalSpacing);
            petal.setPosition(tuzan.getPosition().x + x + 19.f, tuzan.getPosition().y + y + 10.f);
            petal.setFillColor(Color::White);
            petal.setOutlineThickness(1);
            petal.setOutlineColor(Color::Black);
            window->draw(petal);
        }
        //Latice drugog cvijeta
        float petal2Radius = 47.f;
        float petal2Spacing = 30.f;
        float petal2Angle = 0.f;
        for (int i = 0; i < 10; i++) 
        {
            petal2Angle += 30.f;
            float angleRad = petal2Angle * (M_PI / 90.f);
            float x = petal2Radius * cos(angleRad);
            float y = petal2Radius * sin(angleRad);
            CircleShape petal2(petal2Spacing);
            petal2.setPosition(sretan.getPosition().x + x + 11.f, sretan.getPosition().y + y + 8.f);
            petal2.setFillColor(Color::White);
            petal2.setOutlineThickness(1);
            petal2.setOutlineColor(Color::Black);
            window->draw(petal2);
        }

        window->draw(tuzan);
        window->draw(sretan);

        //Animacija kapljica
        for (int i = 0; i < 100; i++) 
        {
            window->draw(rain[i]);
        }

        for (int i = 0; i < 100; i++)
        {
            if (rain[i].getPosition().y > 670) 
            {
                e = 1 + rand() % (399);
                rain[i].setPosition(e, -5);
                array[i] = 3 + rand() % (10);
                b = 1 + rand() % (255);
                c = 1 + rand() % (255);
                d = 1 + rand() % (255);
            }
        }

        window->display();

        for (int i = 0; i < 100; i++)
        {
            rain[i].move(Vector2f(0, array[i]));
        }

        part = 2;

    }

}
