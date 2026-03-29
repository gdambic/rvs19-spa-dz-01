#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    this->window = window;

    // Vanjski krug (latice)
    petals = sf::VertexArray(sf::TriangleFan, 52);

    sf::Vector2f center(400.f, 250.f); // pozicija cvijeta
    float radiusOuter = 60.f;

    petals[0].position = center;
    petals[0].color = sf::Color(0, 50, 50); // tamnija sredina

    for (int i = 1; i < 52; i++)
    {
        float angle = (i - 1) * 2 * 3.14159f / 50;

        float x = center.x + std::cos(angle) * radiusOuter;
        float y = center.y + std::sin(angle) * radiusOuter;

        petals[i].position = sf::Vector2f(x, y);

        // svjetliji rub
        petals[i].color = sf::Color(0, 255, 255);
    }


    // Unutarnji krug (centar)
    innerCircle.setRadius(30);
    innerCircle.setFillColor(sf::Color::Yellow);

    // centriranje kruga
    innerCircle.setOrigin(30, 30);
    innerCircle.setPosition(center);

    // Stabljika
    stem.setSize(sf::Vector2f(10, 200));
    stem.setFillColor(sf::Color::Green);
    stem.setPosition(395, 300);

    // List
    leaf.setPointCount(4);
    leaf.setPoint(0, sf::Vector2f(0.f, 0.f));    
    leaf.setPoint(1, sf::Vector2f(80.f, -40.f));  
    leaf.setPoint(2, sf::Vector2f(90.f, 0.f));    
    leaf.setPoint(3, sf::Vector2f(30.f, 20.f));   
    leaf.setFillColor(sf::Color::Green);
    leaf.setPosition(400, 420);
    leaf.setRotation(-25.f);

    // Sunce
    sunce.setRadius(radius);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition(100, 100);
}

void Cvijet::draw()
{
    window->draw(petals);
    window->draw(innerCircle);
    window->draw(stem);
    window->draw(leaf);
    

    // koliko je vremena prošlo od zadnjeg framea
    float dt = frameClock.restart().asSeconds();

    // brzina animacije (možeš mijenjati)
    float speed = 20.f;

    // animacija pulsiranja
    if (shrinking)
    {
        radius -= speed * dt;
        if (radius <= 15.f)
            shrinking = false;
    }
    else
    {
        radius += speed * dt;
        if (radius >= 20.f)
            shrinking = true;
    }

    // primijeni novi radius
    sunce.setRadius(radius);

    // da centar ostane na istom mjestu
    sunce.setOrigin(radius, radius);

    window->draw(sunce);
}
