#include "Cvijet.h"
#include <iostream>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
    window.setFramerateLimit(60);

    Cvijet cvijet(&window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        cvijet.draw_screen();
        cvijet.animate_the_sun();
        window.display();
    }

    return 0;
}