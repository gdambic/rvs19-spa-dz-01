// Created by Ivan Marković  || 1rp3
// Compile command: clang++ -std=c++17 Source.cpp Cvijet.cpp -o MojProgram -I/opt/homebrew/opt/sfml@2/include -L/opt/homebrew/opt/sfml@2/lib -lsfml-graphics -lsfml-window -lsfml-system
#include <SFML/Graphics.hpp>
#include "Cvijet.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moj Cvijet");

    Cvijet cvijet(&window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        cvijet.draw();
        window.display();
    }

    return 0;
}