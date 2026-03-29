#ifndef CVIJET_HPP
#define CVIJET_HPP
#pragma once //nije obavezno, ali je preporučljivo
#include <SFML/Graphics.hpp>

class Cvijet {
public:
    explicit Cvijet(sf::RenderWindow* window);
    void draw();

private:
    sf::RenderWindow* m_window;
    sf::CircleShape center;
    sf::CircleShape petals[6];
    sf::CircleShape sun; 
    sf::RectangleShape stem;
    sf::CircleShape leaf;
    sf::Clock frameClock;
    float sunRadius;
	bool sunGrowing;
};

#endif // CVIJET_HPP
