#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window;

    for (int i = 0; i < 8; i++) {
        sf::CircleShape latica(30);
        latica.setFillColor(sf::Color(255, 100, 150)); 

        float angle = i * 45.0f; 
        float x = 230 + 50 * cos(angle * 3.14 / 180);
        float y = 130 + 50 * sin(angle * 3.14 / 180);

        latica.setPosition(x, y);

        latice.push_back(latica);
    }

    sredina.setRadius(25);
    sredina.setPosition(230,130);
    sredina.setFillColor(sf::Color(255, 200, 0)); 
    sredina.setOutlineThickness(3);
    sredina.setOutlineColor(sf::Color::Black);

    stabljika.setSize(sf::Vector2f(6, 140));
    stabljika.setFillColor(sf::Color(0, 180, 0));
    stabljika.setPosition(252, 180);

    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(0, 0));
    list.setPoint(1, sf::Vector2f(60, 20));
    list.setPoint(2, sf::Vector2f(40, 40));
    list.setPoint(3, sf::Vector2f(0, 30));
    list.setFillColor(sf::Color(0, 200, 0));
    list.setPosition(255, 260);

    sunce.setRadius(20);
    sunce.setFillColor(sf::Color::Yellow);
    sunce.setPosition(50, 50);
}

void Cvijet::draw() {

    float time = clock.restart().asSeconds();

    if (desno)
        offset += 50 * time;
    else
        offset -= 50 * time;

    if (offset > 50) desno = false;
    if (offset < -50) desno = true;

    int i = 0;
    for (auto& latica : latice) {

        float angle = i * 45.0f;

        float x = 230 + offset + 50 * cos(angle * 3.14f / 180);
        float y = 130 + 50 * sin(angle * 3.14f / 180);

        latica.setPosition(x, y);

        window->draw(latica);

        i++;
    }
    sredina.setPosition(230 + offset, 130);
    stabljika.setPosition(245 + offset, 200);
    list.setPosition(255 + offset, 250);

    if (sunGrowing)
        sunScale += time;
    else
        sunScale -= time;

    if (sunScale > 1.3f) sunGrowing = false;
    if (sunScale < 0.7f) sunGrowing = true;

    sunce.setScale(sunScale, sunScale);

    window->draw(sunce);
    window->draw(stabljika);
    window->draw(list);
    for (auto& latica : latice) 
    {
        window->draw(latica);
    }
    window->draw(sredina);
}