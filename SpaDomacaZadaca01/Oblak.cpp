#include "Oblak.h"

Oblak::Oblak(sf::RenderWindow& prozor) {
    this->prozor = &prozor;

    int i = 0;
    for (auto& latica : latice) {
        /*
        [&i]() -> float {
        if (i % 2 == 0) return 75.f;
        else return 90.f;
        }
        */
        if (i%2==0) latice.at(i).setPosition(650.f + i * 30.f, 90.f);
        else latice.at(i).setPosition(650.f + i * 30.f, 75.f);
        latica.setRadius(40.f);
        latica.setFillColor(sf::Color::White);
        i++;
    }
}

void Oblak::draw()
{
    for (auto& latica : latice)
    {
        prozor->draw(latica);
    }
}
