#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window(window)
{
    initializeFlower();
}

void Cvijet::initializeFlower()
{
    centar.setRadius(trenutniRadius);
    centar.setFillColor(sf::Color(255, 215, 0));
    centar.setPosition(250.f - trenutniRadius, 150.f - trenutniRadius);
    centar.setOutlineThickness(2.f);
    centar.setOutlineColor(sf::Color(139, 69, 19));

    centarCvijeta.setRadius(30.f);
    centarCvijeta.setFillColor(sf::Color(255, 215, 0));
    centarCvijeta.setPosition(400.f - 30.f, 300.f - 30.f);
    centarCvijeta.setOutlineThickness(2.f);
    centarCvijeta.setOutlineColor(sf::Color(139, 69, 19));

    const int laticaBrojac = 8;
    const float radius = 40.f;
    const float udaljenost = 60.f;

    for (int i = 0; i < laticaBrojac; i++)
    {
        sf::CircleShape laticaItem;
        laticaItem.setRadius(radius);
        laticaItem.setFillColor(sf::Color::Red);

        float angle = (i * 2 * 3.14159f) / laticaBrojac;
        float x = 400.f - radius + cos(angle) * udaljenost;
        float y = 300.f - radius + sin(angle) * udaljenost;

        laticaItem.setPosition(x, y);
        latica.push_back(laticaItem);
    }

    stem.setSize(sf::Vector2f(10.f, 200.f));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(395.f, 300.f);

    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(0, 0));
    list.setPoint(1, sf::Vector2f(-50, -25));
    list.setPoint(2, sf::Vector2f(-70, 0));
    list.setPoint(3, sf::Vector2f(-40, 20));
    list.setFillColor(sf::Color(0, 150, 0));
    list.setOutlineThickness(1.f);
    list.setOutlineColor(sf::Color::Black);
    list.setPosition(395.f, 450.f);
}

void Cvijet::draw()
{

    float deltaTime = animationClock.restart().asSeconds();

    if (rast) {
        trenutniRadius += 5.0f * deltaTime;
        if (trenutniRadius >= maxRadius) {
            trenutniRadius = maxRadius;
            rast = false;
        }
    }
    else {
        trenutniRadius -= 5.0f * deltaTime;
        if (trenutniRadius <= minRadius) {
            trenutniRadius = minRadius;
            rast = true;
        }
    }

    centar.setRadius(trenutniRadius);
    centar.setPosition(250.f - trenutniRadius, 150.f - trenutniRadius);

    window->draw(stem);
    window->draw(list);

    for (auto& laticaItem : latica)
    {
        window->draw(laticaItem);
    }

    window->draw(centarCvijeta);

    window->draw(centar);
}
