#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Cvijet{
    private:
        sf::RenderWindow* window;
        sf::Clock clock;

    public:
        Cvijet(sf::RenderWindow* window);
        void draw();
};
