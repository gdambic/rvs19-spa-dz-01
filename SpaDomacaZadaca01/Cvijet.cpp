#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
    m_window = window;
    m_latice.setRadius(100.f);
    m_latice.setFillColor(sf::Color(128, 0, 128));
    m_latice.setPosition(150.f, 100.f);
    m_srediste.setRadius(60.f);
    m_srediste.setFillColor(sf::Color::Yellow);
    m_srediste.setPosition(190.f, 140.f);
    m_stabljika.setSize(sf::Vector2f(10.f, 180.f));
    m_stabljika.setFillColor(sf::Color::Green);
    m_stabljika.setPosition(245.f, 300.f);
    m_list.setPointCount(3);
    m_list.setPoint(0, sf::Vector2f(250.f, 370.f));
    m_list.setPoint(1, sf::Vector2f(370.f, 340.f));
    m_list.setPoint(2, sf::Vector2f(250.f, 420.f));
    m_list.setFillColor(sf::Color::Green);
    m_tockaRadius = 20.f;
    m_growing = false;
    m_tocka.setRadius(m_tockaRadius);
    m_tocka.setFillColor(sf::Color::Yellow);
    m_tocka.setPosition(230.f, 10.f);
}

void Cvijet::draw()
{
    float elapsed = m_frameClock.restart().asSeconds();

    if (m_growing)
    {
        m_tockaRadius += 20.f * elapsed;
        if (m_tockaRadius >= 20.f)
        {
            m_tockaRadius = 20.f;
            m_growing = false;
        }
    }
    else
    {
        m_tockaRadius -= 20.f * elapsed;
        if (m_tockaRadius <= 15.f)
        {
            m_tockaRadius = 15.f;
            m_growing = true;
        }
    }

    m_tocka.setRadius(m_tockaRadius);

    m_window->draw(m_stabljika);
    m_window->draw(m_list);
    m_window->draw(m_latice);
    m_window->draw(m_srediste);
    m_window->draw(m_tocka);
}