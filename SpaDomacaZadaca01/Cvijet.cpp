#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Cvijet.h"

using namespace std;

Cvijet::Cvijet(sf::RenderWindow *window)
{
}

void Cvijet::scale_leaf(sf::ConvexShape &leaf, float scaleFactor) {

    for (int i = 0; i < leaf.getPointCount(); ++i)
    {
        sf::Vector2f vertex = leaf.getPoint(i);
        leaf.setPoint(i, sf::Vector2f(vertex.x * scaleFactor, vertex.y * scaleFactor));
    }

}
void Cvijet::set_point_leaf(sf::ConvexShape& leaf) {
    leaf.setPoint(0, sf::Vector2f(200.f, 0.f)); // Top 
    leaf.setPoint(1, sf::Vector2f(200.f, 200.f)); // Right 
    leaf.setPoint(2, sf::Vector2f(100.f, 400.f)); // Bottom 
    leaf.setPoint(3, sf::Vector2f(100.f, 200.f)); // Left 
}

void Cvijet::set_leaf(sf::ConvexShape& leaf, sf::Color color, float x, float y, float angle, float scaleFactor) {
    leaf.setPointCount(4);
    set_point_leaf(leaf);
    leaf.setFillColor(color);
    leaf.setPosition(x, y);
    leaf.rotate(angle);
    scale_leaf(leaf, scaleFactor);
}

//leaf animation
void animate(sf::ConvexShape& leaf) {
    if (leaf.getPosition().x == 660.f)
    {
        leaf.setPosition(700, leaf.getPosition().y);
    }
    else leaf.setPosition(660, leaf.getPosition().y);

}
void Cvijet::draw(sf::RenderWindow& window)
{
    // leaf1
    sf::ConvexShape leaf1;
    set_leaf(leaf1, sf::Color::Yellow, 170.f, 360.f, 8.f, 0.5f);

    // leaf2
    sf::ConvexShape leaf2;
    set_leaf(leaf2, sf::Color::Red, 160.f, 350.f, 12.f, 0.5f);

    // leaf3
    sf::ConvexShape leaf3;
    set_leaf(leaf3, sf::Color::Yellow, 160.f, 330.f, 18.f, 0.5f);

    // leaf4
    sf::ConvexShape leaf4;
    set_leaf(leaf4, sf::Color::Red, 160.f, 305.f, 25.f, 0.5f);

    // leaf5
    sf::ConvexShape leaf5;
    set_leaf(leaf5, sf::Color::Yellow, 160.f, 290.f, 30.f, 0.5f);

    // leaf6
    sf::ConvexShape leaf6;
    set_leaf(leaf6, sf::Color::Red, 160.f, 280.f, 35.f, 0.5f);

    // leaf7
    sf::ConvexShape leaf7;
    set_leaf(leaf7, sf::Color::Yellow, 160.f, 270.f, 38.f, 0.5f);

    // leaf8
    sf::ConvexShape leaf8;
    set_leaf(leaf8, sf::Color::Red, 160.f, 260.f, 41.f, 0.5f);

    // leaf9
    sf::ConvexShape leaf9;
    set_leaf(leaf9, sf::Color::Yellow, 166.f, 250.f, 47.f, 0.5f);

    // leaf9
    sf::ConvexShape leaf10;
    set_leaf(leaf10, sf::Color::Red, 172.f, 240.f, 50.f, 0.5f);

    // leaf9
    sf::ConvexShape leaf11;
    set_leaf(leaf11, sf::Color::Yellow, 178.f, 230.f, 53.f, 0.5f);

    // leaf9
    sf::ConvexShape leaf12;
    set_leaf(leaf12, sf::Color::Red, 180.f, 220.f, 56.f, 0.5f);

    sf::ConvexShape leaf13;
    set_leaf(leaf13, sf::Color::Yellow, 184.f, 210.f, 62.f, 0.5f);

    sf::ConvexShape leaf14;
    set_leaf(leaf14, sf::Color::Red, 192.f, 200.f, 65.f, 0.5f);

    sf::ConvexShape leaf15;
    set_leaf(leaf15, sf::Color::Yellow, 198.f, 190.f, 68.f, 0.5f);

    sf::ConvexShape leaf16;
    set_leaf(leaf16, sf::Color::Red, 204.f, 180.f, 71.f, 0.5f);

    sf::ConvexShape leaf17;
    set_leaf(leaf17, sf::Color::Yellow, 215.f, 170.f, 74.f, 0.5f);

    sf::ConvexShape leaf18;
    set_leaf(leaf18, sf::Color::Red, 226.f, 160.f, 79.f, 0.5f);

    sf::ConvexShape leaf19;
    set_leaf(leaf19, sf::Color::Yellow, 237.f, 150.f, 82.f, 0.5f);

    sf::ConvexShape leaf20;
    set_leaf(leaf20, sf::Color::Red, 255.f, 140.f, 90.f, 0.5f);

    sf::ConvexShape leaf21;
    set_leaf(leaf21, sf::Color::Yellow, 270.f, 140.f, 98.f, 0.5f);

    sf::ConvexShape leaf22;
    set_leaf(leaf22, sf::Color::Red, 288.f, 140.f, 106.f, 0.5f);

    sf::ConvexShape leaf23;
    set_leaf(leaf23, sf::Color::Yellow, 305.f, 140.f, 112.f, 0.5f);

    sf::ConvexShape leaf24;
    set_leaf(leaf24, sf::Color::Red, 323.f, 140.f, 118.f, 0.5f);

    sf::ConvexShape leaf25;
    set_leaf(leaf25, sf::Color::Yellow, 340.f, 140.f, 124.f, 0.5f);

    sf::ConvexShape leaf26;
    set_leaf(leaf26, sf::Color::Red, 357.f, 150.f, 130.f, 0.5f);

    sf::ConvexShape leaf27;
    set_leaf(leaf27, sf::Color::Yellow, 374.f, 160.f, 136.f, 0.5f);

    sf::ConvexShape leaf28;
    set_leaf(leaf28, sf::Color::Red, 391.f, 170.f, 142.f, 0.5f);

    sf::ConvexShape leaf29;
    set_leaf(leaf29, sf::Color::Yellow, 408.f, 180.f, 148.f, 0.5f);

    sf::ConvexShape leaf30;
    set_leaf(leaf30, sf::Color::Red, 425.f, 200.f, 156.f, 0.5f);

    sf::ConvexShape leaf31;
    set_leaf(leaf31, sf::Color::Yellow, 442.f, 220.f, 162.f, 0.5f);

    sf::ConvexShape leaf32;
    set_leaf(leaf32, sf::Color::Red, 459.f, 240.f, 170.f, 0.5f);

    sf::ConvexShape leaf33;
    set_leaf(leaf33, sf::Color::Yellow, 473.f, 275.f, 178.f, 0.5f);

    sf::ConvexShape leaf34;
    set_leaf(leaf34, sf::Color::Red, 480.f, 310.f, 190.f, 0.5f);

    sf::ConvexShape leaf35;
    set_leaf(leaf35, sf::Color::Yellow, 470.f, 330.f, 202.f, 0.5f);

    sf::ConvexShape leaf36;
    set_leaf(leaf36, sf::Color::Red, 470.f, 345.f, 214.f, 0.5f);

    sf::ConvexShape leaf37;
    set_leaf(leaf37, sf::Color::Yellow, 450.f, 360.f, 226.f, 0.5f);

    sf::ConvexShape leaf38;
    set_leaf(leaf38, sf::Color::Red, 430.f, 380.f, 238.f, 0.5f);

    sf::ConvexShape leaf39;
    set_leaf(leaf39, sf::Color::Yellow, 410.f, 400.f, 246.f, 0.5f);

    sf::ConvexShape leaf40;
    set_leaf(leaf40, sf::Color::Red, 400.f, 420.f, 254.f, 0.5f);

    sf::ConvexShape leaf41;
    set_leaf(leaf41, sf::Color::Yellow, 360.f, 440.f, 260.f, 0.5f);

    sf::ConvexShape leaf42;
    set_leaf(leaf42, sf::Color::Red, 350.f, 460.f, 266.f, 0.5f);

    sf::ConvexShape leaf43;
    set_leaf(leaf43, sf::Color::Yellow, 340.f, 470.f, 272.f, 0.5f);

    sf::ConvexShape leaf44;
    set_leaf(leaf44, sf::Color::Red, 295.f, 475.f, 278.f, 0.5f);

    sf::ConvexShape leaf45;
    set_leaf(leaf45, sf::Color::Yellow, 270.f, 485.f, 287.f, 0.5f);

    sf::ConvexShape leaf46;
    set_leaf(leaf46, sf::Color::Red, 240.f, 480.f, 296.f, 0.5f);

    sf::ConvexShape leaf47;
    set_leaf(leaf47, sf::Color::Yellow, 230.f, 480.f, 305.f, 0.5f);

    sf::ConvexShape leaf48;
    set_leaf(leaf48, sf::Color::Red, 230.f, 460.f, 314.f, 0.5f);

    sf::ConvexShape leaf49;
    set_leaf(leaf49, sf::Color::Yellow, 200.f, 440.f, 323.f, 0.5f);

    sf::ConvexShape leaf50;
    set_leaf(leaf50, sf::Color::Red, 180.f, 410.f, 350.f, 0.5f);

    sf::ConvexShape leaf51;
    set_leaf(leaf51, sf::Color::Yellow, 170.f, 380.f, 355.f, 0.5f);

    sf::ConvexShape leaf52;
    set_leaf(leaf52, sf::Color::Red, 190.f, 410.f, 335.f, 0.5f);


    sf::RectangleShape line(sf::Vector2f(405, 10));
    line.setFillColor(sf::Color::Green);
    line.setPosition(500.f, 400.f);
    line.rotate(30);


    sf::ConvexShape leaf53;
    set_leaf(leaf53, sf::Color::Green, 660.f, 200.f, 20.f, 0.7f);



    sf::ConvexShape convex;
    convex.setPointCount(20);

    convex.setPosition(300.f, 300.f);

    float radius = 70.f;
    for (int i = 0; i < 20; ++i)
    {
        float angle = i * (2 * M_PI / 20);
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        convex.setPoint(i, sf::Vector2f(x, y));
    }

    convex.setFillColor(sf::Color::Yellow);
    convex.setOutlineThickness(45);
    convex.setOutlineColor(sf::Color::Red);

    sf::Clock frameClock;
    sf::Clock animationTimer;
    float animationInterval = 0.5f;
 
    while (window.isOpen())
    {
        sf::Time elapsedTime = frameClock.restart();
        window.clear();


        if (animationTimer.getElapsedTime().asSeconds() >= animationInterval)
        {
            animate(leaf53);
            animationTimer.restart();
        }

        window.draw(convex);
        window.draw(leaf1);
        window.draw(leaf2);
        window.draw(leaf3);
        window.draw(leaf4);
        window.draw(leaf5);
        window.draw(leaf6);
        window.draw(leaf7);
        window.draw(leaf8);
        window.draw(leaf9);
        window.draw(leaf10);
        window.draw(leaf11);
        window.draw(leaf12);
        window.draw(leaf13);
        window.draw(leaf14);
        window.draw(leaf15);
        window.draw(leaf16);
        window.draw(leaf17);
        window.draw(leaf18);
        window.draw(leaf19);
        window.draw(leaf20);
        window.draw(leaf21);
        window.draw(leaf22);
        window.draw(leaf23);
        window.draw(leaf24);
        window.draw(leaf25);
        window.draw(leaf26);
        window.draw(leaf27);
        window.draw(leaf28);
        window.draw(leaf29);
        window.draw(leaf30);
        window.draw(leaf31);
        window.draw(leaf32);
        window.draw(leaf33);
        window.draw(leaf34);
        window.draw(leaf35);
        window.draw(leaf36);
        window.draw(leaf37);
        window.draw(leaf38);
        window.draw(leaf39);
        window.draw(leaf40);
        window.draw(leaf41);
        window.draw(leaf42);
        window.draw(leaf43);
        window.draw(leaf44);
        window.draw(leaf45);
        window.draw(leaf46);
        window.draw(leaf47);
        window.draw(leaf48);
        window.draw(leaf49);
        window.draw(leaf50);
        window.draw(leaf51);
        window.draw(leaf52);
        window.draw(leaf53);
        window.draw(line);

        window.display();
    }
    
}
