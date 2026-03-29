#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
    radijusSunca = 50.f;
    smanjujeSe = true;
}

void Cvijet::draw()
{
    //pokušao sam da bude što ljepše



    //animacija sunca i sunce

    if (frameClock.getElapsedTime().asMilliseconds() > 25)
    {
        if (smanjujeSe)
            radijusSunca -= 0.5f;
        else
            radijusSunca += 0.5f;

        if (radijusSunca <= 25.f)
            smanjujeSe = false;

        if (radijusSunca >= 50.f)
            smanjujeSe = true;

        frameClock.restart();
    }
    sf::CircleShape sunce(radijusSunca);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition(650.f + (50.f - radijusSunca), 70.f + (50.f - radijusSunca));

    // tlo
    sf::RectangleShape tlo(sf::Vector2f(800.f, 140.f));
    tlo.setFillColor(sf::Color::Green);
    tlo.setPosition(0.f, 460.f);

    // stabljika
    sf::RectangleShape stabljika(sf::Vector2f(12.f, 220.f));
    stabljika.setFillColor(sf::Color::Green);
    stabljika.setPosition(394.f, 260.f);

    // list [ zeznuto ;) ]
    sf::ConvexShape list;
    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(400.f, 360.f));
    list.setPoint(1, sf::Vector2f(320.f, 330.f));
    list.setPoint(2, sf::Vector2f(270.f, 360.f));
    list.setPoint(3, sf::Vector2f(360.f, 385.f));
    list.setFillColor(sf::Color::Green);

    // latice
    sf::CircleShape latica(42.f);
    latica.setFillColor(sf::Color::Red);
    latica.setOrigin(42.f, 42.f);

    // centar cvijeta, pa sa time i crtam latice
    float cx = 400.f;
    float cy = 210.f;

    sf::CircleShape latica1 = latica;
    latica1.setPosition(cx + 2.f, cy - 52.f);

    sf::CircleShape latica2 = latica;
    latica2.setPosition(cx + 48.f, cy - 12.f);

    sf::CircleShape latica3 = latica;
    latica3.setPosition(cx + 34.f, cy + 46.f);

    sf::CircleShape latica4 = latica;
    latica4.setPosition(cx - 38.f, cy + 44.f);

    sf::CircleShape latica5 = latica;
    latica5.setPosition(cx - 50.f, cy - 16.f);

    sf::CircleShape latica6 = latica;
    latica6.setPosition(cx - 3.f, cy + 3.f);

    // centar cvijeta
    sf::CircleShape centar(38.f);
    centar.setFillColor(sf::Color::Yellow);
    centar.setOrigin(38.f, 38.f);
    centar.setPosition(cx, cy);

    window->draw(sunce);
    window->draw(tlo);
    window->draw(stabljika);
    window->draw(list);

    window->draw(latica1);
    window->draw(latica2);
    window->draw(latica3);
    window->draw(latica4);
    window->draw(latica5);
    window->draw(latica6);

    window->draw(centar);
}