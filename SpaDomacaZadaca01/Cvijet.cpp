
#include "Cvijet.h"
#include <array>

void Cvijet::draw()
{
    const std::array<sf::Color, 4> colors = {
        sf::Color(255, 255, 0),
        sf::Color(255, 128, 0),
        sf::Color(255, 0, 0),
        sf::Color(255, 128, 0)
    };

    const float time = frameClock_.getElapsedTime().asSeconds();
    const int colorIndex = static_cast<int>(time * 2) % colors.size();
    if (colorIndex != currentColorIndex_) {
        currentColorIndex_ = colorIndex;
    }

    sf::CircleShape petal(40, 5);
    petal.setPosition(410, 300);
    petal.setFillColor(colors[currentColorIndex_]);
    window_->draw(petal);

    sf::CircleShape petal2(40, 5);
    petal2.setPosition(370, 270);
    petal2.setFillColor(colors[currentColorIndex_]);
    petal2.setRotation(72);
    window_->draw(petal2);

    sf::CircleShape petal3(40, 5);
    petal3.setPosition(380, 280);
    petal3.setFillColor(colors[currentColorIndex_]);
    petal3.setRotation(-72);
    window_->draw(petal3);

    sf::CircleShape petal4(40, 5);
    petal4.setPosition(310, 285);
    petal4.setFillColor(colors[currentColorIndex_]);
    petal4.setRotation(-72);
    window_->draw(petal4);

    sf::CircleShape petal5(40, 5);
    petal5.setPosition(480, 240);
    petal5.setFillColor(colors[currentColorIndex_]);
    petal5.setRotation(72);
    window_->draw(petal5);

    sf::CircleShape petal6(40, 5);
    petal6.setPosition(410, 300);
    petal6.setFillColor(colors[currentColorIndex_]);
    petal6.setRotation(72);
    window_->draw(petal6);

    sf::CircleShape center(30);
    center.setPosition(375, 275);
    center.setFillColor(sf::Color(255, 0, 0));
    window_->draw(center);

    sf::RectangleShape stem(sf::Vector2f(10, 100));
    stem.setPosition(400, 325);
    stem.setFillColor(sf::Color(0, 255, 0));
    window_->draw(stem);


}

