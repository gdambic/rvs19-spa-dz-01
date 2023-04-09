#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
    : m_window(window)
{
    m_center.setRadius(50);
    m_center.setFillColor(sf::Color::Yellow);
    m_center.setOrigin(m_center.getRadius(), m_center.getRadius());
    m_center.setPosition(m_window->getSize().x / 2.f, m_window->getSize().y / 2.f);

    float radius = 60.f;
    for (int i = 0; i < 15; i++) {
        m_petals[i].setRadius(20.f);
        m_petals[i].setFillColor(sf::Color::White);
        m_petals[i].setOrigin(m_petals[i].getRadius(), m_petals[i].getRadius());

        float angle = 360.f / 15;
        sf::Vector2f position(radius, 0.f);
        position = sf::Transform().rotate(angle * i) * position;
        m_petals[i].setPosition(m_center.getPosition() + position);
    }

    m_stem.setSize(sf::Vector2f(20.f, 200.f));
    m_stem.setFillColor(sf::Color::Green);
    m_stem.setOrigin(m_stem.getSize().x / 2.f, m_stem.getSize().y / 2.f);
    m_stem.setPosition(m_center.getPosition().x, m_center.getPosition().y + 100.f);

    m_sun.setRadius(50.f);
    m_sun.setFillColor(sf::Color::Yellow);
    m_sun.setOrigin(m_sun.getRadius(), m_sun.getRadius());
    m_sun.setPosition(m_window->getSize().x - m_sun.getRadius(), m_sun.getRadius());

    m_sky.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
    m_sky.setFillColor(sf::Color::Blue);
    m_sky.setPosition(0.f, 0.f);

    m_ground.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y / 2.f));
    m_ground.setFillColor(sf::Color(0, 100, 0));
    m_ground.setPosition(0.f, m_window->getSize().y * 0.75f);
}

void Cvijet::draw()
{
    m_window->draw(m_sky);
    m_window->draw(m_ground);
    m_window->draw(m_stem);
    m_window->draw(m_center);

    for (int i = 0; i < 15; i++) {
        m_window->draw(m_petals[i]);
    }

    m_window->draw(m_sun);
}