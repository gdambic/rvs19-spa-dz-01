#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
    radius = 50.f;
    smanjujeSe = false;
}

void Cvijet::draw()
{
    if (frameClock.getElapsedTime().asMilliseconds() > 30)
    {
        if (smanjujeSe)
            radius -= 1.f;
        else
            radius += 1.f;

        if (radius >= 60.f)
            smanjujeSe = true;
        if (radius <= 40.f)
            smanjujeSe = false;

        frameClock.restart();
    }

    sf::CircleShape krug(radius);
    krug.setFillColor(sf::Color::Yellow);
    krug.setPosition(200, 200);

    window->draw(krug);
}