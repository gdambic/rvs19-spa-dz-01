#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;
}

void Cvijet::draw()
{

    timePassed += clock.restart().asSeconds();

    if (timePassed >= 1.f)
    {
        timePassed = 0.f;
        movingRight = !movingRight;
    }

    sf::CircleShape sunce(50.f);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition(-50, -50);
    sunce.setOutlineThickness(2.f);
    sunce.setOutlineColor(sf::Color(255, 95, 31));

    sf::RectangleShape sunceAura(sf::Vector2f(2.f, 30.f));
    sunceAura.setFillColor(sf::Color(255, 95, 31));
    sunceAura.setPosition(80, 50);
    sunceAura.setRotation(120);

    sf::RectangleShape sunceAura1(sf::Vector2f(2.f, 30.f));
    sunceAura1.setFillColor(sf::Color(255, 95, 31));
    sunceAura1.setPosition(40, 85);
    sunceAura1.setRotation(130);

    if (movingRight)
    {
        sunceAura.move(moveDistance, 0);
        sunceAura1.move(moveDistance, 0);
    }
    else
    {
        sunceAura.move(-moveDistance, 0);
        sunceAura1.move(-moveDistance, 0);
    }

    sf::CircleShape vrhCvijeta(50.f);
    vrhCvijeta.setFillColor(sf::Color::Yellow);
    vrhCvijeta.setPosition(350, 200);
    vrhCvijeta.setOutlineThickness(10.f);
    vrhCvijeta.setOutlineColor(sf::Color::Red);

    sf::RectangleShape tanjiDioCvijeta(sf::Vector2f(10.f, 150.f));
    tanjiDioCvijeta.setFillColor(sf::Color::Green);
    tanjiDioCvijeta.setPosition(395, 250);

    sf::CircleShape lijevaRukaCvijeta(20.f);
    lijevaRukaCvijeta.setFillColor(sf::Color::Green);
    lijevaRukaCvijeta.setScale(1.5f, 0.7f);
    lijevaRukaCvijeta.setPosition(340, 320);

    sf::CircleShape desnaRukaCvijeta(20.f);
    desnaRukaCvijeta.setFillColor(sf::Color::Green);
    desnaRukaCvijeta.setScale(1.5f, 0.7f);
    desnaRukaCvijeta.setPosition(400, 320);

    window->draw(desnaRukaCvijeta);
    window->draw(tanjiDioCvijeta);
    window->draw(lijevaRukaCvijeta);
    window->draw(vrhCvijeta);
    window->draw(sunce);
    window->draw(sunceAura);
    window->draw(sunceAura1);
}
