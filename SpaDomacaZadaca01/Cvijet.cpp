#include "Cvijet.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Cvijet::Cvijet(RenderWindow* prozor)
    : prozor(prozor), sunRadius(20.f), sunGrowing(false), oblakOffset(0.f)
{
    nebo.setSize(Vector2f(800.f, 420.f));
    nebo.setPosition(0.f, 0.f);
    nebo.setFillColor(Color(100, 170, 230));

    trava.setSize(Vector2f(800.f, 130.f));
    trava.setPosition(0.f, 420.f);
    trava.setFillColor(Color(80, 160, 60));

    zemlja.setSize(Vector2f(800.f, 50.f));
    zemlja.setPosition(0.f, 520.f);
    zemlja.setFillColor(Color(110, 75, 40));

    float oblakRadijusi1[] = { 30.f, 38.f, 28.f, 22.f };
    float oblakX1[]        = { 150.f, 185.f, 220.f, 245.f };
    float oblakY1[]        = { 95.f,  75.f,  85.f,  100.f };
    for (int i = 0; i < 4; i++)
    {
        oblak1[i].setRadius(oblakRadijusi1[i]);
        oblak1[i].setOrigin(oblakRadijusi1[i], oblakRadijusi1[i]);
        oblak1[i].setPosition(oblakX1[i], oblakY1[i]);
        oblak1[i].setFillColor(Color(255, 255, 255, 220));
    }

    float oblakRadijusi2[] = { 25.f, 34.f, 22.f };
    float oblakX2[]        = { 530.f, 562.f, 592.f };
    float oblakY2[]        = { 120.f, 104.f, 118.f };
    for (int i = 0; i < 3; i++)
    {
        oblak2[i].setRadius(oblakRadijusi2[i]);
        oblak2[i].setOrigin(oblakRadijusi2[i], oblakRadijusi2[i]);
        oblak2[i].setPosition(oblakX2[i], oblakY2[i]);
        oblak2[i].setFillColor(Color(255, 255, 255, 200));
    }

    sunceGlow.setRadius(34.f);
    sunceGlow.setOrigin(34.f, 34.f);
    sunceGlow.setPosition(70.f, 65.f);
    sunceGlow.setFillColor(Color(255, 240, 100, 80));

    sunce.setRadius(sunRadius);
    sunce.setOrigin(sunRadius, sunRadius);
    sunce.setPosition(70.f, 65.f);
    sunce.setFillColor(Color(255, 230, 50));
    sunce.setOutlineColor(Color(240, 180, 20));
    sunce.setOutlineThickness(2.f);

    stablo.setSize(Vector2f(12.f, 190.f));
    stablo.setOrigin(6.f, 0.f);
    stablo.setPosition(400.f, 320.f);
    stablo.setFillColor(Color(60, 160, 60));
    stablo.setOutlineColor(Color(30, 110, 30));
    stablo.setOutlineThickness(1.5f);

    list.setPointCount(4);
    list.setPoint(0, Vector2f(0.f,   0.f));
    list.setPoint(1, Vector2f(72.f, -18.f));
    list.setPoint(2, Vector2f(88.f,  14.f));
    list.setPoint(3, Vector2f(16.f,  30.f));
    list.setFillColor(Color(50, 170, 50));
    list.setOutlineColor(Color(30, 110, 30));
    list.setOutlineThickness(1.f);
    list.setPosition(404.f, 380.f);

    listMali.setPointCount(4);
    listMali.setPoint(0, Vector2f(0.f,    0.f));
    listMali.setPoint(1, Vector2f(-58.f, -14.f));
    listMali.setPoint(2, Vector2f(-70.f,  10.f));
    listMali.setPoint(3, Vector2f(-12.f,  24.f));
    listMali.setFillColor(Color(45, 160, 45));
    listMali.setOutlineColor(Color(30, 110, 30));
    listMali.setOutlineThickness(1.f);
    listMali.setPosition(396.f, 430.f);

    float cx = 400.f;
    float cy = 290.f;

    for (int i = 0; i < 8; i++)
    {
        float angle = i * (2.f * (float)M_PI / 8.f);
        float px = cx + 52.f * std::cos(angle);
        float py = cy + 52.f * std::sin(angle);

        latice[i].setRadius(40.f);
        latice[i].setFillColor(Color(220, 40, 100));
        latice[i].setOutlineColor(Color(170, 10, 70));
        latice[i].setOutlineThickness(1.2f);
        latice[i].setOrigin(40.f, 40.f);
        latice[i].setPosition(px, py);
    }

    for (int i = 0; i < 8; i++)
    {
        float angle = i * (2.f * (float)M_PI / 8.f) + (float)M_PI / 8.f;
        float px = cx + 38.f * std::cos(angle);
        float py = cy + 38.f * std::sin(angle);

        laticeUnutarnje[i].setRadius(22.f);
        laticeUnutarnje[i].setFillColor(Color(255, 160, 50));
        laticeUnutarnje[i].setOutlineColor(Color(200, 110, 20));
        laticeUnutarnje[i].setOutlineThickness(0.8f);
        laticeUnutarnje[i].setOrigin(22.f, 22.f);
        laticeUnutarnje[i].setPosition(px, py);
    }

    sredisteSjaj.setRadius(36.f);
    sredisteSjaj.setOrigin(36.f, 36.f);
    sredisteSjaj.setPosition(cx, cy);
    sredisteSjaj.setFillColor(Color(255, 200, 50, 120));

    srediste.setRadius(26.f);
    srediste.setFillColor(Color(200, 130, 20));
    srediste.setOutlineColor(Color(140, 80, 10));
    srediste.setOutlineThickness(2.f);
    srediste.setOrigin(26.f, 26.f);
    srediste.setPosition(cx, cy);
}

void Cvijet::draw()
{
    float dt = frameClock.restart().asSeconds();

    oblakOffset += 18.f * dt;
    if (oblakOffset > 900.f)
        oblakOffset = -300.f;

    prozor->draw(nebo);

    for (int i = 0; i < 4; i++)
    {
        CircleShape c = oblak1[i];
        c.setPosition(oblak1[i].getPosition() + Vector2f(oblakOffset * 0.6f, 0.f));
        if (c.getPosition().x - c.getRadius() > 800.f)
            c.setPosition(c.getPosition() - Vector2f(1100.f, 0.f));
        prozor->draw(c);
    }

    for (int i = 0; i < 3; i++)
    {
        CircleShape c = oblak2[i];
        c.setPosition(oblak2[i].getPosition() + Vector2f(oblakOffset * 0.4f, 0.f));
        if (c.getPosition().x - c.getRadius() > 800.f)
            c.setPosition(c.getPosition() - Vector2f(1100.f, 0.f));
        prozor->draw(c);
    }

    prozor->draw(trava);
    prozor->draw(zemlja);

    if (sunGrowing)
    {
        sunRadius += 12.f * dt;
        if (sunRadius >= 24.f) { sunRadius = 24.f; sunGrowing = false; }
    }
    else
    {
        sunRadius -= 12.f * dt;
        if (sunRadius <= 16.f) { sunRadius = 16.f; sunGrowing = true; }
    }

    sunce.setRadius(sunRadius);
    sunce.setOrigin(sunRadius, sunRadius);

    float glowR = sunRadius + 14.f;
    sunceGlow.setRadius(glowR);
    sunceGlow.setOrigin(glowR, glowR);

    prozor->draw(sunceGlow);
    prozor->draw(sunce);

    prozor->draw(stablo);
    prozor->draw(list);
    prozor->draw(listMali);

    for (int i = 0; i < 8; i++)
        prozor->draw(latice[i]);

    for (int i = 0; i < 8; i++)
        prozor->draw(laticeUnutarnje[i]);

    prozor->draw(sredisteSjaj);
    prozor->draw(srediste);
}
