#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Cvijet");
    window.setFramerateLimit(60);
    Cvijet flower1(&window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        window.clear();
        flower1.draw();
        window.display();
    }

    return 0;
}
