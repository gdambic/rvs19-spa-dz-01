#include "Cvijet.h"
#include <SFML/Graphics.hpp>

// Ovi includeovi ispod mi ne tribaju jer san ih includea s ovin gori graphics.hpp
//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Graphics/CircleShape.hpp>
//#include <SFML/Graphics/RectangleShape.hpp>

Cvijet::Cvijet(sf::RenderWindow* window) {
    this->window = window;
}

void Cvijet::draw() {
    sf::CircleShape shape(90.f);
    shape.setFillColor(sf::Color::Magenta);
    shape.setPosition(310.f, 113.f);

    sf::Clock clock;    // Stvaran vrime za pracenje vrimena

    while (window->isOpen()) {  // Radin petlju dok je otvoren prozor
        sf::Event event;    // Pravin objekt event koji ce sadrzavat info o dogadajima (tip dogadaja je
                            // je otvaranje i zatvaranje dogadaja)

        while (window->pollEvent(event)) {  // Ova petlja provjerava ima li dogadaja u redu dogadaja
            if (event.type == sf::Event::Closed) {  // Ako je dogadaj zatvaranja prozora, zatvaran prozor
                window->close();    // Zatvaran prozor
            }
        }

        float elapsedTime = clock.getElapsedTime().asSeconds();

        // Ode moran koristit sin funkciju da bi ogranicija povecavanje i smanjivanje kruga

        float scaleFactor = 1.0f + 0.1f * std::sin(elapsedTime * 2);

        // Ode moran postavit novi radijus za ovaj Magenta krug da znan dokle ce se povecavat

        shape.setRadius(90.f * scaleFactor);
        shape.setPosition(shape.getPosition().x - shape.getRadius() + shape.getRadius(), 
        shape.getPosition().y - shape.getRadius() + shape.getRadius());

        window->clear();
        window->draw(shape);

        sf::RectangleShape line(sf::Vector2f(150, 5));
        line.setOutlineThickness(8);
        line.setOutlineColor(sf::Color::Green);
        line.setPosition(400.f, 300.f);
        line.setFillColor(sf::Color::Green);
        line.rotate(90);
        window->draw(line);

        sf::CircleShape cshape(65.f);
        cshape.setFillColor(sf::Color::Yellow);
        cshape.setPosition(335.f, 138.f);
        window->draw(cshape);

        sf::CircleShape c2shape(50.f);
        c2shape.setFillColor(sf::Color::Yellow);
        c2shape.setPosition(100.f, 40.f);
        window->draw(c2shape);

        sf::CircleShape triangle(50, 5);
        triangle.setFillColor(sf::Color::Green);
        triangle.setPosition(385.f, 330.f);
        window->draw(triangle);

        window->display();
    }
}