#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window) : window_(window),
sunce_(65.f) {
    sunce_.setFillColor(sf::Color(255, 255, 0));
    sunce_.setPosition(-100.f, 200.f);
}

void Cvijet::draw() {

    float vrijeme = frameClock_.getElapsedTime().asSeconds();
    float sunce_x = 800.f * (std::sin(vrijeme / 20.f) + 1.f) / 2.f - 100.f;
    float sunce_y = 200.f - 200.f * (std::cos(vrijeme / 20.f) + 1.f) / 2.f;
    sunce_.setPosition(sunce_x, sunce_y);
    window_->draw(sunce_);


    sf::RectangleShape stabljika(sf::Vector2f(13.f, 150.f));
    stabljika.setPosition(360.f, 330.f);
    stabljika.setFillColor(sf::Color(0, 255, 0));
    window_->draw(stabljika);

    sf::ConvexShape latica;
    latica.setPointCount(4);
    latica.setFillColor(sf::Color(255, 0, 0));

    for (int i = 0; i < 8; i++) {
        latica.setPosition(365.f, 240.f);
        latica.setRotation(i * 45.f);
        latica.setPoint(0, sf::Vector2f(0.f, 0.f));
        latica.setPoint(1, sf::Vector2f(70.f, 10.f));
        latica.setPoint(2, sf::Vector2f(100.f, 70.f));
        latica.setPoint(3, sf::Vector2f(20.f, 70.f));
        latica.setFillColor(sf::Color(250, 0, 0));
        window_->draw(latica);
        latica.setOutlineThickness(5.f);
        latica.setOutlineColor(sf::Color(0, 0, 0));
    }

    sf::CircleShape tucak(30.f);
    tucak.setPosition(345.f, 215.f);
    tucak.setFillColor(sf::Color(255, 255, 0));
    window_->draw(tucak);


}
