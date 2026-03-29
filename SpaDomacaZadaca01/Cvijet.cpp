#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
    sunac = 35.f;
    raste = true;

    oblaci = 0.f;
    oblakdesno = true;

    cvijetanim = 0.f;
}

void Cvijet::draw()
{
    if (frameclock.getElapsedTime().asMilliseconds() > 30)
    {
        if (raste)
            sunac += 0.4f;
        else
            sunac -= 0.4f;

        if (sunac >= 50.f)
            raste = false;

        if (sunac <= 35.f)
            raste = true;

        if (oblakdesno)
            oblaci += 0.15f;
        else
            oblaci -= 0.15f;

        if (oblaci >= 25.f)
            oblakdesno = false;

        if (oblaci <= -25.f)
            oblakdesno = true;

        cvijetanim += 0.4f;

        frameclock.restart();
    }

    // nebo
    sf::RectangleShape nebo(sf::Vector2f(800.f, 600.f));
    nebo.setFillColor(sf::Color(120, 200, 255));

    // trava
    sf::RectangleShape trava(sf::Vector2f(800.f, 170.f));
    trava.setFillColor(sf::Color(70, 170, 70));
    trava.setPosition(0.f, 430.f);

    // sunce
    sf::CircleShape sunce(sunac);
    sunce.setFillColor(sf::Color(255, 220, 50));
    sunce.setPosition(30.f, 60.f);

    // oblaci
    sf::CircleShape oblak1(22.f);
    oblak1.setFillColor(sf::Color::White);
    oblak1.setPosition(660.f + oblaci, 80.f);

    sf::CircleShape oblak2(28.f);
    oblak2.setFillColor(sf::Color::White);
    oblak2.setPosition(685.f + oblaci, 65.f);

    sf::CircleShape oblak3(22.f);
    oblak3.setFillColor(sf::Color::White);
    oblak3.setPosition(720.f + oblaci, 80.f);

    sf::CircleShape oblak4(22.f);
    oblak4.setFillColor(sf::Color::White);
    oblak4.setPosition(200.f + oblaci, 80.f);

    sf::CircleShape oblak5(28.f);
    oblak5.setFillColor(sf::Color::White);
    oblak5.setPosition(225.f + oblaci, 65.f);

    sf::CircleShape oblak6(22.f);
    oblak6.setFillColor(sf::Color::White);
    oblak6.setPosition(260.f + oblaci, 80.f);

    sf::CircleShape oblak7(22.f);
    oblak7.setFillColor(sf::Color::White);
    oblak7.setPosition(500.f + oblaci, 80.f);

    sf::CircleShape oblak8(28.f);
    oblak8.setFillColor(sf::Color::White);
    oblak8.setPosition(525.f + oblaci, 65.f);

    sf::CircleShape oblak9(22.f);
    oblak9.setFillColor(sf::Color::White);
    oblak9.setPosition(560.f + oblaci, 80.f);

    // stabljika
    sf::RectangleShape stabljika(sf::Vector2f(14.f, 210.f));
    stabljika.setFillColor(sf::Color(40, 150, 40));
    stabljika.setPosition(393.f, 240.f);

    sf::ConvexShape list1;
    list1.setPointCount(4);
    list1.setPoint(0, sf::Vector2f(398.f, 340.f));
    list1.setPoint(1, sf::Vector2f(330.f, 315.f));
    list1.setPoint(2, sf::Vector2f(290.f, 345.f));
    list1.setPoint(3, sf::Vector2f(360.f, 372.f));
    list1.setFillColor(sf::Color(50, 180, 50));

    sf::ConvexShape list2;
    list2.setPointCount(4);
    list2.setPoint(0, sf::Vector2f(406.f, 390.f));
    list2.setPoint(1, sf::Vector2f(470.f, 365.f));
    list2.setPoint(2, sf::Vector2f(510.f, 390.f));
    list2.setPoint(3, sf::Vector2f(440.f, 420.f));
    list2.setFillColor(sf::Color(50, 180, 50));

    // osnovne latice
    sf::CircleShape laticaVelika(34.f);
    laticaVelika.setFillColor(sf::Color(255, 120, 180));

    sf::CircleShape laticaMala(22.f);
    laticaMala.setFillColor(sf::Color(255, 160, 200));

    float cx = 400.f;
    float cy = 205.f;

    // vanjske latice
    sf::CircleShape l1 = laticaVelika;
    l1.setOrigin(34.f, 89.f);
    l1.setPosition(cx, cy);
    l1.setRotation(cvijetanim);

    sf::CircleShape l2 = laticaVelika;
    l2.setOrigin(-11.f, 64.f);
    l2.setPosition(cx, cy);
    l2.setRotation(cvijetanim);

    sf::CircleShape l3 = laticaVelika;
    l3.setOrigin(-11.f, 6.f);
    l3.setPosition(cx, cy);
    l3.setRotation(cvijetanim);

    sf::CircleShape l4 = laticaVelika;
    l4.setOrigin(34.f, -18.f);
    l4.setPosition(cx, cy);
    l4.setRotation(cvijetanim);

    sf::CircleShape l5 = laticaVelika;
    l5.setOrigin(79.f, 6.f);
    l5.setPosition(cx, cy);
    l5.setRotation(cvijetanim);

    sf::CircleShape l6 = laticaVelika;
    l6.setOrigin(79.f, 64.f);
    l6.setPosition(cx, cy);
    l6.setRotation(cvijetanim);

    // unutarnje latice
    sf::CircleShape m1 = laticaMala;
    m1.setOrigin(22.f, 52.f);
    m1.setPosition(cx, cy);
    m1.setRotation(cvijetanim);

    sf::CircleShape m2 = laticaMala;
    m2.setOrigin(-3.f, 37.f);
    m2.setPosition(cx, cy);
    m2.setRotation(cvijetanim);

    sf::CircleShape m3 = laticaMala;
    m3.setOrigin(-3.f, 7.f);
    m3.setPosition(cx, cy);
    m3.setRotation(cvijetanim);

    sf::CircleShape m4 = laticaMala;
    m4.setOrigin(22.f, -8.f);
    m4.setPosition(cx, cy);
    m4.setRotation(cvijetanim);

    sf::CircleShape m5 = laticaMala;
    m5.setOrigin(47.f, 7.f);
    m5.setPosition(cx, cy);
    m5.setRotation(cvijetanim);

    sf::CircleShape m6 = laticaMala;
    m6.setOrigin(47.f, 37.f);
    m6.setPosition(cx, cy);
    m6.setRotation(cvijetanim);

    // centar
    sf::CircleShape centar(28.f);
    centar.setFillColor(sf::Color(255, 210, 50));
    centar.setOrigin(28.f, 28.f);
    centar.setPosition(cx, cy);

    // crtanje
    window->draw(nebo);
    window->draw(sunce);

    window->draw(oblak1);
    window->draw(oblak2);
    window->draw(oblak3);
    window->draw(oblak4);
    window->draw(oblak5);
    window->draw(oblak6);
    window->draw(oblak7);
    window->draw(oblak8);
    window->draw(oblak9);
    window->draw(trava);
    window->draw(stabljika);
    window->draw(list1);
    window->draw(list2);
    window->draw(l1);
    window->draw(l2);
    window->draw(l3);
    window->draw(l4);
    window->draw(l5);
    window->draw(l6);
    window->draw(m1);
    window->draw(m2);
    window->draw(m3);
    window->draw(m4);
    window->draw(m5);
    window->draw(m6);

    window->draw(centar);
}