#include "Flower.hh"
#include "EllipseShape.hh"

Flower::Flower(sf::RenderWindow& window) : _window(window) {
   //
}

void Flower::draw() {
   int width = this->_window.getSize().x;
   int height = this->_window.getSize().y;
   sf::Vector2f pedalOrigin = sf::Vector2f(30, 100);
   sf::Vector2f pedalPosition = sf::Vector2f(((width / 2) - (30 + 90)), (height / 2) - 100);
   sf::Color white = sf::Color(232, 232, 232);
   sf::Color orange = sf::Color(253, 199, 69);
   sf::Color green = sf::Color(42, 166, 62);
   sf::Color darkGreen = sf::Color(23, 130, 62);
   
   EllipseShape pedal1 = EllipseShape({30, 100});
   pedal1.setFillColor(white);
   pedal1.setOrigin(pedalOrigin);
   pedal1.setRotation(sf::degrees(0));
   pedal1.setPosition(pedalPosition);

   EllipseShape pedal2 = EllipseShape({30, 100});
   pedal2.setFillColor(white);
   pedal2.setOrigin(pedalOrigin);
   pedal2.setRotation(sf::degrees(45));
   pedal2.setPosition(pedalPosition);

   EllipseShape pedal3 = EllipseShape({30, 100});
   pedal3.setFillColor(white);
   pedal3.setOrigin(pedalOrigin);
   pedal3.setRotation(sf::degrees(90));
   pedal3.setPosition(pedalPosition);

   EllipseShape pedal4 = EllipseShape({30, 100});
   pedal4.setFillColor(white);
   pedal4.setOrigin(pedalOrigin);
   pedal4.setRotation(sf::degrees(135));
   pedal4.setPosition(pedalPosition);
   
   sf::CircleShape centerCircle = sf::CircleShape(30);
   centerCircle.setFillColor(orange);
   centerCircle.setOrigin(pedalOrigin);
   centerCircle.setPosition(sf::Vector2f(((width / 2) - (30 + 90)), (height / 2) - 30));

   sf::RectangleShape stem = sf::RectangleShape({10, 180});
   stem.setFillColor(green);
   stem.setPosition(sf::Vector2f(((width / 2) - (35 + 90)), (height / 2) - 10));

   EllipseShape leaf1 = EllipseShape({20, 40});
   leaf1.setFillColor(darkGreen);
   leaf1.setRotation(sf::degrees(135));
   leaf1.setPosition(sf::Vector2f(((width / 2) - (20 + 90)), (height / 2) + 50));

   EllipseShape leaf2 = EllipseShape({20, 40});
   leaf2.setFillColor(darkGreen);
   leaf2.setRotation(sf::degrees(225));
   leaf2.setPosition(sf::Vector2f(((width / 2) - (15 + 90)), (height / 2) + 90));
   
   this->_window.draw(leaf1);
   this->_window.draw(leaf2);
   this->_window.draw(stem);
   this->_window.draw(pedal1);
   this->_window.draw(pedal2);
   this->_window.draw(pedal3);
   this->_window.draw(pedal4);
   this->_window.draw(centerCircle);
}