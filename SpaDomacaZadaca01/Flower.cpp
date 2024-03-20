#include "Flower.h"

Flower::Flower(sf::RenderWindow* window) : m_window(window) {
    // Define properties of the flower
    // Center
    m_center.setRadius(20);
    m_center.setFillColor(sf::Color::Yellow);
    m_center.setPosition(400.f, 300.f);
    m_center.setOrigin(m_center.getRadius(), m_center.getRadius());

    // Petals (outline)
    m_petals.setRadius(50);
    m_petals.setFillColor(sf::Color::Transparent);
    m_petals.setOutlineThickness(10);
    m_petals.setOutlineColor(sf::Color::Red);
    m_petals.setPosition(400.f, 300.f);
    m_petals.setOrigin(m_petals.getRadius(), m_petals.getRadius());

    // Stem
    m_stem.setSize(sf::Vector2f(10, 150));
    m_stem.setFillColor(sf::Color::Green);
    m_stem.setPosition(395.f, 320.f);

    // Leaf
    m_leaf.setPointCount(4);
    m_leaf.setPoint(0, sf::Vector2f(0, 0));
    m_leaf.setPoint(1, sf::Vector2f(50, -50));
    m_leaf.setPoint(2, sf::Vector2f(100, 0));
    m_leaf.setPoint(3, sf::Vector2f(50, 50));
    m_leaf.setFillColor(sf::Color::Green);
    m_leaf.setPosition(370.f, 380.f);
}

void Flower::draw() {
    m_window->draw(m_center);
    m_window->draw(m_petals);
    m_window->draw(m_stem);
    m_window->draw(m_leaf);
}
