#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Hello, SFML world!");
    Cvijet cvijet(&window);   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(135, 206, 235));
        cvijet.draw();        
        window.display();
    }

    return 0;
}