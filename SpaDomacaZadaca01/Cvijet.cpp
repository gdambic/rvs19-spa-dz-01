#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* prozor)
{
	this->prozor = prozor;
	njihanje = 0.f;
}

void Cvijet::draw() {
    // Izracun kuta njihanja
    float vrijeme = sat.getElapsedTime().asSeconds();
    njihanje = std::sin(vrijeme * 2.f) * 10.f;

    float kutRad = njihanje * 3.14159f / 180.f;
    sf::Vector2f bazaStabljike(400.f, 450.f);
    sf::Vector2f vrhStabljike(
        bazaStabljike.x + std::sin(kutRad) * 150.f,
        bazaStabljike.y - std::cos(kutRad) * 150.f
    );

    // Nebo
    sf::RectangleShape nebo(sf::Vector2f(800.f, 600.f));
    nebo.setFillColor(sf::Color(135, 206, 235));
    prozor->draw(nebo);

    // Oblak
    sf::CircleShape oblak(50.f);
    oblak.setFillColor(sf::Color(240, 240, 240));
    oblak.setOrigin(50.f, 50.f);
    oblak.setPosition(700.f, 100.f);
    prozor->draw(oblak);
    oblak.setPosition(655.f, 80.f);
    prozor->draw(oblak);
    oblak.setPosition(660.f, 100.f);
    prozor->draw(oblak);
    oblak.setPosition(600.f, 100.f);
    prozor->draw(oblak);

    // Sunce
    sf::CircleShape sunce(75.f);
    sunce.setFillColor(sf::Color(254, 211, 0));
    sunce.setOrigin(75.f, 75.f);
    sunce.setPosition(100.f, 100.f);
    prozor->draw(sunce);

    // Brdo
    sf::CircleShape brdo(500.f);
    brdo.setFillColor(sf::Color(80, 160, 60));
    brdo.setOrigin(500.f, 500.f);
    brdo.setPosition(400.f, 900.f);
    prozor->draw(brdo);

    // Stabljika
    sf::RectangleShape stabljika(sf::Vector2f(10.f, 150.f));
    stabljika.setFillColor(sf::Color(34, 120, 34));
    stabljika.setOrigin(5.f, 150.f);
    stabljika.setPosition(bazaStabljike);
    stabljika.setRotation(njihanje);
    prozor->draw(stabljika);

    // Lijevi list
    sf::Vector2f pozLijevogLista(
        bazaStabljike.x + std::sin(kutRad) * 30.f,
        bazaStabljike.y - std::cos(kutRad) * 30.f
    );
    sf::ConvexShape lijeviList;
    lijeviList.setPointCount(3);
    lijeviList.setPoint(0, sf::Vector2f(0.f, 0.f));
    lijeviList.setPoint(1, sf::Vector2f(-50.f, -15.f));
    lijeviList.setPoint(2, sf::Vector2f(-5.f, -35.f));
    lijeviList.setFillColor(sf::Color(34, 120, 34));
    lijeviList.setPosition(pozLijevogLista);
    lijeviList.setRotation(njihanje);
    prozor->draw(lijeviList);

    // Desni list
    sf::Vector2f pozDesnogLista(
        bazaStabljike.x + std::sin(kutRad) * 50.f,
        bazaStabljike.y - std::cos(kutRad) * 50.f
    );
    sf::ConvexShape desniList;
    desniList.setPointCount(3);
    desniList.setPoint(0, sf::Vector2f(0.f, 0.f));
    desniList.setPoint(1, sf::Vector2f(50.f, 0.1f));
    desniList.setPoint(2, sf::Vector2f(5.f, -35.f));
    desniList.setFillColor(sf::Color(34, 120, 34));
    desniList.setPosition(pozDesnogLista);
    desniList.setRotation(njihanje);
    prozor->draw(desniList);

    // Latice
    sf::CircleShape latica(25.f, 35);
    latica.setFillColor(sf::Color(220, 30, 30));
    latica.setOrigin(25.f, 55.f);
    for (int i = 0; i < 8; i++) {
        latica.setPosition(vrhStabljike);
        latica.setRotation(njihanje + i * 45.f);
        prozor->draw(latica);
    }

    // Sredina
    sf::CircleShape sredina(20.f);
    sredina.setFillColor(sf::Color::Yellow);
    sredina.setOrigin(20.f, 20.f);
    sredina.setPosition(vrhStabljike);
    prozor->draw(sredina);
}