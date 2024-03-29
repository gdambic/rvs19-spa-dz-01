#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window) : win(window)
{

}

void Cvijet::draw()
{
    sf::CircleShape krug2(20.f);
    krug2.setFillColor(sf::Color(255, 255, 0));
    krug2.setPosition(5, 5);



    sf::Vector2f velocity;
    velocity.x = 2;
    velocity.y = 0.25;

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        //zalazak sunca
        sf::Vector2f pos = krug2.getPosition();
        pos.x += velocity.x;
        pos.y += velocity.y;
        krug2.setPosition(pos);

        //krug i boja
        sf::CircleShape krug(50.f);
        krug.setFillColor(sf::Color(255, 255, 0));
        //rub krua i boja
        krug.setOutlineThickness(30.f);
        krug.setOutlineColor(sf::Color(250, 0, 0));
        krug.setPosition(100, 100);
        win.draw(krug);



        sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
        line.setFillColor(sf::Color(0, 240, 0));
        line.rotate(90.f);
        line.setPosition(150, 230);

        win.draw(line);

       

        sf::ConvexShape convex;
        convex.setFillColor(sf::Color(0, 240, 0));
        convex.setPointCount(4);
        convex.setPoint(0, sf::Vector2f(150.f, 300.f));
        convex.setPoint(1, sf::Vector2f(130.f, 280.f));
        convex.setPoint(2, sf::Vector2f(70.f, 200.f));
        convex.setPoint(3, sf::Vector2f(50.f, 220.f));
        win.draw(convex);

        sf::ConvexShape convex2;
        convex2.setFillColor(sf::Color(0, 240, 0));
        convex2.setPointCount(4);
        convex2.setPoint(0, sf::Vector2f(150.f, 340.f));
        convex2.setPoint(1, sf::Vector2f(200.f, 300.f));
        convex2.setPoint(2, sf::Vector2f(190.f, 280.f));
        convex2.setPoint(3, sf::Vector2f(170.f, 310.f));
        win.draw(convex2);

    
        win.draw(krug2);
        win.display();
        win.clear();
    }

}
