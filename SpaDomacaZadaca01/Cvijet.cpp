#include "Cvijet.h"
#include <cmath>

const float PI = 3.14159265f;

Cvijet::Cvijet(sf::RenderWindow* prozor)
    : prozor(prozor),
    sunce_polumjer(45.f), sunce_smjer(-1.f),
    oblak_prvi_x(100.f), oblak_drugi_x(380.f),
    oblak_prvi_smjer(1.f), oblak_drugi_smjer(-1.f)
{
    nebo.setSize(sf::Vector2f(600.f, 440.f));
    nebo.setFillColor(sf::Color(135, 206, 235));
    nebo.setPosition(0.f, 0.f);

    trava.setSize(sf::Vector2f(600.f, 160.f));
    trava.setFillColor(sf::Color(34, 139, 34));
    trava.setPosition(0.f, 440.f);

    sunce.setRadius(sunce_polumjer);
    sunce.setOrigin(sunce_polumjer, sunce_polumjer);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition(70.f, 70.f);

    float polumjer_prvi[3] = { 30.f, 40.f, 28.f };
    float pomak_prvi[3] = { 0.f, 35.f, 65.f };
    for (int i = 0; i < 3; i++) {
        oblak_prvi[i].setRadius(polumjer_prvi[i]);
        oblak_prvi[i].setOrigin(polumjer_prvi[i], polumjer_prvi[i]);
        oblak_prvi[i].setFillColor(sf::Color::White);
        oblak_prvi[i].setPosition(oblak_prvi_x + pomak_prvi[i], 100.f);
    }

    float polumjer_drugi[3] = { 25.f, 38.f, 24.f };
    float pomak_drugi[3] = { 0.f, 30.f, 58.f };
    for (int i = 0; i < 3; i++) {
        oblak_drugi[i].setRadius(polumjer_drugi[i]);
        oblak_drugi[i].setOrigin(polumjer_drugi[i], polumjer_drugi[i]);
        oblak_drugi[i].setFillColor(sf::Color::White);
        oblak_drugi[i].setPosition(oblak_drugi_x + pomak_drugi[i], 80.f);
    }

    for (int i = 0; i < 6; i++) {
        latica[i].setRadius(26.f);
        latica[i].setOrigin(26.f, 26.f);
        latica[i].setFillColor(sf::Color(148, 0, 211));
        float kut = i * (PI / 3.f);
        latica[i].setPosition(300.f + 30.f * std::cos(kut), 260.f + 30.f * std::sin(kut));
    }

    srediste.setRadius(22.f);
    srediste.setOrigin(22.f, 22.f);
    srediste.setFillColor(sf::Color::Yellow);
    srediste.setPosition(300.f, 260.f);

    stabljika.setSize(sf::Vector2f(10.f, 140.f));
    stabljika.setFillColor(sf::Color(0, 160, 0));
    stabljika.setPosition(295.f, 300.f);

    list_lijevi.setPointCount(3);
    list_lijevi.setPoint(0, sf::Vector2f(300.f, 370.f));
    list_lijevi.setPoint(1, sf::Vector2f(230.f, 340.f));
    list_lijevi.setPoint(2, sf::Vector2f(270.f, 400.f));
    list_lijevi.setFillColor(sf::Color(50, 205, 50));

    list_desni.setPointCount(3);
    list_desni.setPoint(0, sf::Vector2f(305.f, 390.f));
    list_desni.setPoint(1, sf::Vector2f(375.f, 360.f));
    list_desni.setPoint(2, sf::Vector2f(350.f, 420.f));
    list_desni.setFillColor(sf::Color(50, 205, 50));
}

void Cvijet::draw()
{
    float proteklo = sat.restart().asSeconds();

    sunce_polumjer += sunce_smjer * 15.f * proteklo;
    if (sunce_polumjer <= 38.f) { sunce_polumjer = 38.f; sunce_smjer = 1.f; }
    else if (sunce_polumjer >= 52.f) { sunce_polumjer = 52.f; sunce_smjer = -1.f; }
    sunce.setRadius(sunce_polumjer);
    sunce.setOrigin(sunce_polumjer, sunce_polumjer);

    oblak_prvi_x += oblak_prvi_smjer * 30.f * proteklo;
    if (oblak_prvi_x > 480.f) oblak_prvi_smjer = -1.f;
    else if (oblak_prvi_x < 80.f) oblak_prvi_smjer = 1.f;

    oblak_drugi_x += oblak_drugi_smjer * 20.f * proteklo;
    if (oblak_drugi_x > 500.f) oblak_drugi_smjer = -1.f;
    else if (oblak_drugi_x < 60.f) oblak_drugi_smjer = 1.f;

    float pomak_prvi[3] = { 0.f, 35.f, 65.f };
    float pomak_drugi[3] = { 0.f, 30.f, 58.f };
    for (int i = 0; i < 3; i++)
        oblak_prvi[i].setPosition(oblak_prvi_x + pomak_prvi[i], 100.f);
    for (int i = 0; i < 3; i++)
        oblak_drugi[i].setPosition(oblak_drugi_x + pomak_drugi[i], 80.f);

    prozor->draw(nebo);
    prozor->draw(trava);
    prozor->draw(sunce);
    for (int i = 0; i < 3; i++) prozor->draw(oblak_prvi[i]);
    for (int i = 0; i < 3; i++) prozor->draw(oblak_drugi[i]);
    prozor->draw(stabljika);
    prozor->draw(list_lijevi);
    prozor->draw(list_desni);
    for (int i = 0; i < 6; i++) prozor->draw(latica[i]);
    prozor->draw(srediste);
}