#include "Cvijet.h"
#include <cmath>
Cvijet::Cvijet(sf::RenderWindow* window) : prozor(window) {
  
    
    krug.setRadius(40.f);
    krug.setPointCount(8);
    krug.setFillColor(sf::Color{255, 236, 161});
    krug.setPosition(225.f, 120.f);
    krug.setOutlineThickness(60.f);
    krug.setOutlineColor(sf::Color{ 232, 133, 197 });

    stabljika.setSize(sf::Vector2f(10.f, 180.f));
    stabljika.setFillColor(sf::Color{ 110, 164, 71 });
    stabljika.setPosition(260.f, 260.f);
       
    list.setPointCount(9);
    list.setPoint(0, sf::Vector2f(260.f, 360.f));
    list.setPoint(1, sf::Vector2f(280.f, 340.f));
    list.setPoint(2, sf::Vector2f(310.f, 330.f));
    list.setPoint(3, sf::Vector2f(330.f, 340.f));
    list.setPoint(4, sf::Vector2f(340.f, 370.f));
    list.setPoint(5, sf::Vector2f(330.f, 390.f));
    list.setPoint(6, sf::Vector2f(310.f, 410.f));
    list.setPoint(7, sf::Vector2f(290.f, 380.f));
    list.setPoint(8, sf::Vector2f(260.f, 360.f));
    list.setFillColor(sf::Color{ 110, 164, 71 });

    list2.setPointCount(9);
    list2.setPoint(0, sf::Vector2f(265.f, 325.f));
    list2.setPoint(1, sf::Vector2f(240.f, 305.f));
    list2.setPoint(2, sf::Vector2f(210.f, 295.f));
    list2.setPoint(3, sf::Vector2f(190.f, 305.f));
    list2.setPoint(4, sf::Vector2f(180.f, 335.f));
    list2.setPoint(5, sf::Vector2f(190.f, 355.f));
    list2.setPoint(6, sf::Vector2f(210.f, 375.f));
    list2.setPoint(7, sf::Vector2f(230.f, 345.f));
    list2.setPoint(8, sf::Vector2f(265.f, 325.f));
    list2.setFillColor(sf::Color{ 110, 164, 71 });

    trava.setSize(sf::Vector2f(800.f, 180.f));
    trava.setFillColor(sf::Color{ 91, 130, 63 });
    trava.setPosition(0.f, 440.f);

    
}

void Cvijet::draw() {
    prozor->draw(stabljika);
    prozor->draw(krug);
    prozor->draw(list);
    prozor->draw(list2);
    prozor->draw(trava);
}

void Cvijet::animate() {
    float lista_y_pomak = std::sin(frameClock.getElapsedTime().asSeconds()) * 10.f;

    list.setPoint(1, sf::Vector2f(280.f, 340.f + lista_y_pomak));
    list.setPoint(2, sf::Vector2f(310.f, 330.f + lista_y_pomak));
    list.setPoint(3, sf::Vector2f(330.f, 340.f + lista_y_pomak));
    list.setPoint(4, sf::Vector2f(340.f, 370.f + lista_y_pomak));
    list.setPoint(5, sf::Vector2f(330.f, 390.f + lista_y_pomak));
    list.setPoint(6, sf::Vector2f(310.f, 410.f + lista_y_pomak));
    list.setPoint(7, sf::Vector2f(290.f, 380.f + lista_y_pomak));

    float list2_y_pomak = std::sin(frameClock.getElapsedTime().asSeconds()) * 10.f;

    list2.setPoint(1, sf::Vector2f(240.f, 305.f + list2_y_pomak));
    list2.setPoint(2, sf::Vector2f(210.f, 295.f + list2_y_pomak));
    list2.setPoint(3, sf::Vector2f(190.f, 305.f + list2_y_pomak));
    list2.setPoint(4, sf::Vector2f(180.f, 335.f + list2_y_pomak));
    list2.setPoint(5, sf::Vector2f(190.f, 355.f + list2_y_pomak));
    list2.setPoint(6, sf::Vector2f(210.f, 375.f + list2_y_pomak));
    list2.setPoint(7, sf::Vector2f(230.f, 345.f + list2_y_pomak));
}