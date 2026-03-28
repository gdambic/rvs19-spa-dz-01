#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* prozor)
    : prozor(prozor), sredinaRadius(22.f), smanjuje(true)

{
    const sf::Vector2f centar(400.f, 220.f);

    const float radiusi[10] = { 18.f, 16.f, 16.f, 18.f, 15.f, 18.f, 16.f, 16.f, 12.f, 12.f };
    const sf::Vector2f pozicije[10] =
    {
        { 400.f, 182.f },
        { 428.f, 192.f },
        { 438.f, 220.f },
        { 428.f, 248.f },
        { 400.f, 258.f },
        { 372.f, 248.f },
        { 362.f, 220.f },
        { 372.f, 192.f },
        { 388.f, 202.f },
        { 412.f, 202.f }
    };


    const sf::Color boje[10] =
    {
        sf::Color(145, 90, 210),
        sf::Color(200, 120, 235),
        sf::Color(255, 170, 210),
        sf::Color(170, 105, 230),
        sf::Color::White,
        sf::Color(170, 105, 230),
        sf::Color(200, 120, 235),
        sf::Color(145, 90, 210),
        sf::Color::White,
        sf::Color(255, 210, 240)
    };

    for (std::size_t i = 0; i < latice.size(); ++i)
    {
        latice[i].setRadius(radiusi[i]);
        latice[i].setOrigin(radiusi[i], radiusi[i]);
        latice[i].setPosition(pozicije[i]);
        latice[i].setFillColor(boje[i]);
        latice[i].setOutlineThickness(1.f);
        latice[i].setOutlineColor(sf::Color(255, 255, 255, 80));
    }

    sredina.setRadius(sredinaRadius);
    sredina.setOrigin(sredinaRadius, sredinaRadius);
    sredina.setPosition(centar);
    sredina.setFillColor(sf::Color(255, 245, 210));
    sredina.setOutlineThickness(2.f);
    sredina.setOutlineColor(sf::Color(140, 80, 200));

    stapka.setSize(sf::Vector2f(10.f, 120.f));
    stapka.setOrigin(5.f, 0.f);
    stapka.setPosition(400.f, 240.f);
    stapka.setFillColor(sf::Color(80, 170, 80));

    listLijevi.setSize(sf::Vector2f(46.f, 14.f));
    listLijevi.setOrigin(0.f, 7.f);
    listLijevi.setPosition(392.f, 290.f);
    listLijevi.setRotation(-28.f);
    listLijevi.setFillColor(sf::Color(70, 160, 80));

    listDesni.setSize(sf::Vector2f(46.f, 14.f));
    listDesni.setOrigin(0.f, 7.f);
    listDesni.setPosition(408.f, 312.f);
    listDesni.setRotation(34.f);
    listDesni.setFillColor(sf::Color(70, 160, 80));
}

void Cvijet::draw()
{
    if (frameClock.getElapsedTime().asMilliseconds() >= 80)
    {
        if (smanjuje)
            sredinaRadius -= 0.5f;
        else
            sredinaRadius += 0.5f;

        if (sredinaRadius <= 15.f)
        {
            sredinaRadius = 15.f;
            smanjuje = false;
        }

        if (sredinaRadius >= 22.f)
        {
            sredinaRadius = 20.f;
            smanjuje = true;
        }

        sredina.setRadius(sredinaRadius);
        sredina.setOrigin(sredinaRadius, sredinaRadius);
        frameClock.restart();
    }

    prozor->draw(stapka);
    prozor->draw(listLijevi);
    prozor->draw(listDesni);

    for (const auto& latica : latice)
        prozor->draw(latica);

    prozor->draw(sredina);
}

