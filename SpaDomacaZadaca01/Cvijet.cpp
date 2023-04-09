#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
m_window = window;
	m_water.setSize(sf::Vector2f(800.f, 100.f));
	m_water.setFillColor(sf::Color(38, 119, 255));
	m_water.setPosition(0.f, 350.f);
}

void Cvijet::draw(sf::Time frameTime)
{
	/*~~~~~_voda_~~~~~*/
	float waterSpeed = 100.f;
	m_water.move(0.f, waterSpeed * frameTime.asSeconds());

	if (m_water.getPosition().y >= 550.f) {
		m_water.setPosition(0.f, 0.f);
	}

	sf::RectangleShape stem(sf::Vector2f(10.f, 180.f));
	stem.setFillColor(sf::Color::Green);
	stem.setPosition(400.f, 270.f);
	stem.setRotation(0.f);

	sf::CircleShape petal(80.f, 5.f);
	petal.setFillColor(sf::Color::Red);
	petal.setPosition(325.f, 130.f);

	sf::CircleShape center(21.f, 15.f);
	center.setFillColor(sf::Color::Yellow);
	center.setPosition(385.f, 190.f);

	m_window->draw(stem);
	m_window->draw(petal);
	m_window->draw(center);
	m_window->draw(m_water);
	m_window->display();

}