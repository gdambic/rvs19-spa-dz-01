#include "Cvijet.h"

#include <ctime>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

Cvijet::Cvijet(sf::RenderWindow* window){
    this->window = window;
    srand(time(nullptr));
}

void Cvijet::draw(){

    sf::CircleShape srediste(12.0f);
    srediste.setOrigin(12.0f, 12.0f);
    srediste.setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f);
    srediste.setFillColor(sf::Color(255, 255, 102));

    sf::Vertex stabiljka[] {
        sf::Vertex(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y), sf::Color::Green),
        sf::Vertex(sf::Vector2f(window->getSize().x / 2.0f, srediste.getPosition().y)),
    };

    sf::RectangleShape latica(sf::Vector2f(140.0f, 1.0f));
    latica.setOrigin(70.0f, 0.5f);
    latica.setPosition(window->getSize().x / 2.0f, window->getSize().y / 2.0f);

    std::array<sf::RectangleShape, 40> latice;
    latice[0] = latica;

    const int ROTATION_OFFSET = 5;

    for(int i = 1; i < latice.size(); i++){
        latica.setRotation(latice[i - 1].getRotation() + ROTATION_OFFSET);
        latice[i] = latica;
    }

    sf::ConvexShape list(4);
    list.setFillColor(sf::Color(0, 204, 0));
    list.setPoint(0, sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y));
    list.setPoint(1, sf::Vector2f(400.0f, 500.0f));
    list.setPoint(2, sf::Vector2f(460.0f, 400.0f));
    list.setPoint(3, sf::Vector2f(440.0f, 540.0f));

    int offset = rand() % 30 + 1;
    for(int i = 1; i < latice.size(); i++){
        latice[i].setRotation(latice[i - 1].getRotation() + offset);
    }

    window->draw(stabiljka, 2, sf::Lines);
    std::for_each(latice.begin(), latice.end(), [this] (auto &lat){ window->draw(lat);});
    window->draw(srediste);
    window->draw(list);
}

