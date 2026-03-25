#include "Cvijet.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Cvijet::Cvijet(sf::RenderWindow* prozor)
    : prozor(prozor), sunRadius(20.f), sunSpeed(5.f), sunGrowing(false)
{
    initShapes();
}

void Cvijet::initShapes()
{
    // --- Stabljika ---
    stabljika.setSize(sf::Vector2f(10.f, 150.f));
    stabljika.setFillColor(sf::Color(0, 180, 0));
    stabljika.setPosition(295.f, 250.f);

    // --- Latice (6 komada oko sredista) ---
    for (int i = 0; i < 6; i++) {
        latica[i].setRadius(35.f);
        latica[i].setFillColor(sf::Color(220, 20, 60)); // crvena
        latica[i].setOrigin(35.f, 35.f);

        float kut = i * (360.f / 6) * (M_PI / 180.f);
        float x = 300.f + std::cos(kut) * 45.f;
        float y = 200.f + std::sin(kut) * 45.f;
        latica[i].setPosition(x, y);
    }

    // --- Srediste ---
    srediste.setRadius(40.f);
    srediste.setFillColor(sf::Color(255, 215, 0)); // zlatna
    srediste.setOrigin(40.f, 40.f);
    srediste.setPosition(300.f, 200.f);

    // --- List (konveksni oblik) ---
    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(300.f, 280.f));
    list.setPoint(1, sf::Vector2f(370.f, 310.f));
    list.setPoint(2, sf::Vector2f(340.f, 340.f));
    list.setPoint(3, sf::Vector2f(300.f, 320.f));
    list.setFillColor(sf::Color(0, 200, 0));

    // --- Sunce ---
    sunce.setRadius(sunRadius);
    sunce.setFillColor(sf::Color(255, 255, 0));
    sunce.setOrigin(sunRadius, sunRadius);
    sunce.setPosition(80.f, 80.f);
}

void Cvijet::draw()
{
    // --- Animacija sunca ---
    float elapsed = frameClock.restart().asSeconds();

    if (sunGrowing) {
        sunRadius += sunSpeed * elapsed * 30.f;
        if (sunRadius >= 20.f) {
            sunRadius = 20.f;
            sunGrowing = false;
        }
    } else {
        sunRadius -= sunSpeed * elapsed * 30.f;
        if (sunRadius <= 15.f) {
            sunRadius = 15.f;
            sunGrowing = true;
        }
    }

    sunce.setRadius(sunRadius);
    sunce.setOrigin(sunRadius, sunRadius);

    // --- Crtanje ---
    prozor->draw(stabljika);
    prozor->draw(list);

    for (int i = 0; i < 6; i++) {
        prozor->draw(latica[i]);
    }

    prozor->draw(srediste);
    prozor->draw(sunce);
}
