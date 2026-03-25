#include <SFML/Graphics.hpp>
#include "Cvijet.h"  // LINIJA 7 - otkomentirati

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 500), "Hello, SFML world!");

    Cvijet cvijet(&window);  // LINIJA 19 - otkomentirati

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        cvijet.draw();

        window.display();
    }

    return 0;
}
