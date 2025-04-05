#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include "Sun.h" 

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
    window.setFramerateLimit(60);

    Cvijet cvijet(&window);
    Sun sun(30.f, sf::Color::Yellow); 

    sf::Clock clock; 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds(); 

        sun.update(deltaTime); 

        window.clear();
        cvijet.draw();
        sun.draw(window); 
        window.display();
    }

    return 0;
}