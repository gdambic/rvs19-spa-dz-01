#define _USE_MATH_DEFINES
#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <string>


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
    
    //loading the textures
    if (!stem_texture.loadFromFile("stem_texture_file.jpg")){
        std::cout << "404" << std::endl;
    }
    if (!gynoecium_texture.loadFromFile("gynoecium_texture_file.jpg")){
        std::cout << "404" << std::endl;
    }
    if (!petal_disk_texture.loadFromFile("petal_disk_texture_file.jpg")){
        std::cout << "404" << std::endl;
    }
    if (!leaf_texture.loadFromFile("leaf_texture_file.jpg")){
        std::cout << "404" << std::endl;
    }
    if (!grass_texture.loadFromFile("grass_texture_file.jpg")){
        std::cout << "404" << std::endl;
    }
    if (!sky_texture.loadFromFile("sky_texture_file.jpg")) {
        std::cout << "404" << std::endl;
    }
}

void Cvijet::draw(sf::RenderWindow& window)
{
   
    //drawing the SKY
    sf::RectangleShape sky(sf::Vector2f(800.f, 800.f));
    sky.setPosition(sf::Vector2f(0.f, 0.f));
    sky.setTexture(&sky_texture);
    window.draw(sky);

 
    double sunSize_change = 1.f;
    static bool sun_direction = 1;
    static sf::CircleShape sun(50); //initialising the sun
    static sf::Vector2f sunPosition(50.f, 50.f); //initial location of the sun
    sun.setPosition(sunPosition);
    
    //driving the sun pulsationg
    if (sun_direction == 1 && sun.getRadius() < 100.f) {
        sun.setRadius(sun.getRadius() + sunSize_change);
    }
    else if (sun_direction == 0 && sun.getRadius() > 40.f) {
        sun.setRadius(sun.getRadius() - sunSize_change);
    }
    if (sun.getRadius() == 100.f || sun.getRadius() == 40.f) {
        sun_direction = !sun_direction;
    }

    //drawing the sun
    sun.setFillColor(sf::Color::Yellow);
    window.draw(sun);
   

    //drawing the floor
    sf::RectangleShape grass(sf::Vector2f(800.f, 100.f));
    grass.setPosition(sf::Vector2f(0.f, 500.f));
    grass.setTexture(&grass_texture);
    window.draw(grass);
    
    //drawing the stem
    sf::RectangleShape line(sf::Vector2f(300.f, 10.f));
    line.setPosition(sf::Vector2f(330.f, 280.f));
    line.setTexture(&stem_texture);
    line.rotate(90);
    window.draw(line);
   
    //Drawing the Petal disk
    sf::CircleShape PetalDisk(55.f);
    PetalDisk.setPosition(sf::Vector2f(276.f, 244.f));
    PetalDisk.setTexture(&petal_disk_texture);
    window.draw(PetalDisk);

    //Drawing the Gynoecium
    sf::CircleShape Gynoecium(25.f);
    Gynoecium.setPosition(sf::Vector2f(305.f, 275.f));
    Gynoecium.setTexture(&gynoecium_texture);
    window.draw(Gynoecium);

    //Drawing the leaf
    sf::ConvexShape leaf;
    leaf.setPointCount(3);
    leaf.setPoint(0, sf::Vector2f(330.f, 480.f));
    leaf.setPoint(1, sf::Vector2f(400.f, 500.f));
    leaf.setPoint(2, sf::Vector2f(500.f, 400.f));
    leaf.setTexture(&leaf_texture);
    window.draw(leaf);





   
    
   
}
