#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow* prozor)
{
    window = prozor;
}


    void Cvijet::draw()
    {
        sf::RectangleShape stabljika(sf::Vector2f(10, 150));
        stabljika.setPosition(395, 300);
        stabljika.setFillColor(sf::Color::Green);

        sf::CircleShape sredina(30);
        sredina.setPosition(370, 230);
        sredina.setFillColor(sf::Color::Yellow);

        sf::CircleShape latica1(25);
        latica1.setPosition(370, 180+pomak);
        latica1.setFillColor(sf::Color::Red);

        sf::CircleShape latica2(25);
        latica2.setPosition(370, 280);
        latica2.setFillColor(sf::Color::Red);

        sf::CircleShape latica3(25);
        latica3.setPosition(320, 230);
        latica3.setFillColor(sf::Color::Red);

        sf::CircleShape latica4(25);
        latica4.setPosition(420, 230);
        latica4.setFillColor(sf::Color::Red);

        window->draw(stabljika);
        window->draw(sredina);
        window->draw(latica1);
        window->draw(latica2);
        window->draw(latica3);
        window->draw(latica4);
        if (gore)
        {
            pomak--;
            if (pomak < -10)
                gore = false;
        }
        else
        {
            pomak++;
            if (pomak > 10)
                gore = true;
        }
    }

