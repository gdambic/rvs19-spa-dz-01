#include "Cvijet.h"
#include <iostream>
#include <random>


//I'd love to split this into multiple classes, but as the instructions say all drawing is done with Cvijet::draw()

//this peace of code executes multiple times so I made it a function
void animate(sf::RectangleShape* wind) {
    if (wind->getPosition().x < 1440.f)
    {
        wind->setPosition(wind->getPosition().x + 10, wind->getPosition().y);
    }
    else wind->setPosition(-250, wind->getPosition().y);


}

//basic constructor code
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window; //no need for jumps or checks, this piece of code is not input-based (hard-coded)
}

//main function
void Cvijet::draw()
{
    sf::err().rdbuf(NULL); //disables default error messaging, it's slow and inefficient

    //loading textures
        //images are all jpgs as they are more efficient and there is no need for transparency, even though png looks better jpg takes up a lot less space and is thus a better choice
    sf::Texture background_texture;
    try {
        if (!background_texture.loadFromFile("images/background_texture.jpg")) {
            throw std::runtime_error("Error loading sky texture! 404, not found!");
        }
    }
    catch (std::runtime_error err) { std::cout << err.what(); }

    sf::Texture sun_texture;
    try {
        if (!sun_texture.loadFromFile("images/sun_texture.jpg")) {
            throw std::runtime_error("Error loading sun texture! 404, not found!");
        }
    }
    catch (std::runtime_error err) { std::cout << err.what(); }

    sf::Texture stem_texture;
    try {
        if (!stem_texture.loadFromFile("images/stem_texture.jpg")) {
            throw std::runtime_error("Error loading stem texture! 404, not found!");
        }
    }
    catch (std::runtime_error err) { std::cout << err.what(); }

    sf::Texture leaf_texture;
    try {
        if (!leaf_texture.loadFromFile("images/leaf_texture.jpg")) {
            throw std::runtime_error("Error loading leaf texture! 404, not found!");
        }
    }
    catch (std::runtime_error err) { std::cout << err.what(); }

    sf::Texture sflower_texture;
    try {
        if (!sflower_texture.loadFromFile("images/sflower_texture.jpg")) {
            throw std::runtime_error("Error loading sunflower texture! 404, not found!");
        }
    }
    catch (std::runtime_error err) { std::cout << err.what(); }

    sf::Texture crown_texture;
    try {
        if (!crown_texture.loadFromFile("images/crown_texture.jpg")) {
            throw std::runtime_error("Error loading flower crown texture! 404, not found!");
        }
    }
    catch (std::runtime_error err) { std::cout << err.what(); }

    //I used integers where floating point variables weren't a necessity, where they were I used float instead of double as it it's more efficient and the precision double offers is quite unnecesarry in this scenario

    //background
    sf::Sprite background(background_texture);
    background.setScale(
        float(window->getSize().x) / background.getTexture()->getSize().x,
        float(window->getSize().y) / background.getTexture()->getSize().y);

    //sun
    sf::CircleShape sun(80);
    sun.setPosition(-40,-40);
    sun.setOutlineColor(sf::Color::Red);
    sun.setOutlineThickness(3);
    sun.setTexture(&sun_texture);
    sun.setTextureRect(sf::IntRect(10, 10, 1000, 1000));

    //stem
    sf::RectangleShape stem(sf::Vector2f(200, 3));
    stem.rotate(90);
    stem.setTexture(&stem_texture);
    stem.setPosition(100, 400);

    //flower leaf1
    sf::ConvexShape leaf1;
    leaf1.setPointCount(7);
    leaf1.setPoint(0, sf::Vector2f(60.f, 0.f));
    leaf1.setPoint(1, sf::Vector2f(50.f, 20.f));
    leaf1.setPoint(2, sf::Vector2f(30.f, 40.f));
    leaf1.setPoint(3, sf::Vector2f(20.f, 60.f));
    leaf1.setPoint(4, sf::Vector2f(20.f, 80.f));
    leaf1.setPoint(5, sf::Vector2f(50.f, 100.f));
    leaf1.setPoint(6, sf::Vector2f(80.f, 80.f));
    leaf1.setFillColor(sf::Color::Green);
    leaf1.rotate(40);
    leaf1.setPosition(125, 400);
    leaf1.setTexture(&leaf_texture);

    //flower leaf2
    sf::ConvexShape leaf2;
    leaf2.setPointCount(7);
    leaf2.setPoint(0, sf::Vector2f(60.f, 0.f));
    leaf2.setPoint(1, sf::Vector2f(50.f, 20.f));
    leaf2.setPoint(2, sf::Vector2f(30.f, 40.f));
    leaf2.setPoint(3, sf::Vector2f(20.f, 60.f));
    leaf2.setPoint(4, sf::Vector2f(20.f, 80.f));
    leaf2.setPoint(5, sf::Vector2f(50.f, 100.f));
    leaf2.setPoint(6, sf::Vector2f(80.f, 80.f));
    leaf2.setFillColor(sf::Color::Green);
    leaf2.rotate(-40);
    leaf2.scale(-1, 1);
    leaf2.setPosition(70, 400);
    leaf2.setTexture(&leaf_texture);

    //flower crown
    sf::CircleShape f_crown(65, 8);
    f_crown.setPosition(34, 285);
    f_crown.setTexture(&crown_texture);
    f_crown.setOutlineColor(sf::Color::Black);
    f_crown.setOutlineThickness(1);

    //flower center
    sf::CircleShape f_center(50);
    f_center.setPosition(49, 300);
    f_center.setTexture(&sflower_texture);

    //wind models
        //wind group 1
    sf::RectangleShape wind1(sf::Vector2f(200, 1));
    wind1.setPosition(-300, 500);
    wind1.setFillColor(sf::Color(255, 255, 255, 128)); //color set to white with alpha at half transparency
    sf::RectangleShape wind2(sf::Vector2f(200, 1));
    wind2.setPosition(-350, 550);
    wind2.setFillColor(sf::Color(255, 255, 255, 128));
    sf::RectangleShape wind3(sf::Vector2f(200, 1));
    wind3.setPosition(-350, 450);
    wind3.setFillColor(sf::Color(255, 255, 255, 128));
        //wind group 2
    sf::RectangleShape wind4(sf::Vector2f(200, 1));
    wind4.setPosition(0, 200);
    wind4.setFillColor(sf::Color(255, 255, 255, 128));
    sf::RectangleShape wind5(sf::Vector2f(200, 1));
    wind5.setPosition(-50, 250);
    wind5.setFillColor(sf::Color(255, 255, 255, 128));
    sf::RectangleShape wind6(sf::Vector2f(200, 1));
    wind6.setPosition(-50, 150);
    wind6.setFillColor(sf::Color(255, 255, 255, 128));

    //loop that listens for the open event so it knows when to stop running the draw and display functions
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

        //wind animation
        animate(&wind1);
        animate(&wind2);
        animate(&wind3);
        animate(&wind4);
        animate(&wind5);
        animate(&wind6);

        //flower swing animation
            //it's inside of a loop so there's no need to make it a function other than to look good
        if (wind4.getPosition().x > 0 &&wind4.getPosition().x<500 && f_center.getRotation() < 3.9) {
            f_center.rotate(0.1);
            f_center.setPosition(f_center.getPosition().x + 0.5, f_center.getPosition().y);
            stem.rotate(0.1);
            stem.setPosition(stem.getPosition().x + 0.5, stem.getPosition().y);
            f_crown.rotate(0.1);
            f_crown.setPosition(f_crown.getPosition().x + 0.5, f_crown.getPosition().y);
            leaf1.rotate(0.1);
            leaf1.setPosition(leaf1.getPosition().x + 0.5, leaf1.getPosition().y);
            leaf2.rotate(0.1);
            leaf2.setPosition(leaf2.getPosition().x + 0.5, leaf2.getPosition().y);
        }
        else if (wind4.getPosition().x > 500 && f_center.getRotation() > 0.1) {
            f_center.rotate(-0.1);
            f_center.setPosition(f_center.getPosition().x - 0.5, f_center.getPosition().y);
            stem.rotate(-0.1);
            stem.setPosition(stem.getPosition().x - 0.5, stem.getPosition().y);
            f_crown.rotate(-0.1);
            f_crown.setPosition(f_crown.getPosition().x - 0.5, f_crown.getPosition().y);
            leaf1.rotate(-0.1);
            leaf1.setPosition(leaf1.getPosition().x - 0.5, leaf1.getPosition().y);
            leaf2.rotate(-0.1);
            leaf2.setPosition(leaf2.getPosition().x - 0.5, leaf2.getPosition().y);
        }

        //drawing(loading) all the models
        window->draw(background);
        window->draw(sun);
        window->draw(stem);
        window->draw(leaf1);
        window->draw(leaf2);
        window->draw(f_crown);
        window->draw(f_center);
        window->draw(wind1);
        window->draw(wind2);
        window->draw(wind3);
        window->draw(wind4);
        window->draw(wind5);
        window->draw(wind6);

        //displaying everything
        window->display();
    }
}

