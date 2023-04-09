#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& prozor) {
    this->prozor = &prozor;

    sredina.setRadius(85.f);
    sredina.setFillColor(sf::Color::Red);
    sredina.setPosition(150.f, 150.f);

    stabljika.setSize(sf::Vector2f(300.f, 25.f));
    stabljika.move(sredinaCvijeta() + sf::Vector2f(10, 75));
    stabljika.rotate(90);
    stabljika.setFillColor(sf::Color::Green);

    list.setPointCount(4);
    list.setPoint(0, sf::Vector2f(0, 170));
    list.setPoint(1, sf::Vector2f(100, 120));
    list.setPoint(2, sf::Vector2f(170, 130));
    list.setPoint(3, sf::Vector2f(120, 180));
    list.setFillColor(sf::Color::Green);
    list.move(sredinaStabljike());

    float fi = -35;

    for (auto& latica : latice) {
        latica.setRadius(80.f);
        latica.setFillColor(sf::Color::Yellow);
        latica.setPosition(sredinaCvijeta());
        latica.rotate(fi);
        fi += 72;
    }

}

void Cvijet::draw() {
    prozor->draw(stabljika);
    prozor->draw(list);
    for(auto& latica : latice)
    {
        prozor->draw(latica);
    }
    prozor->draw(sredina);
}

sf::Vector2f Cvijet::sredinaCvijeta()
{
    auto sr = sredina.getPosition();
    sr.x += sredina.getRadius();
    sr.y += sredina.getRadius();
    return sr;
}

sf::Vector2f Cvijet::sredinaStabljike()
{
    auto sr = stabljika.getPosition();
    sr.y -= 50;
    return sr;
}