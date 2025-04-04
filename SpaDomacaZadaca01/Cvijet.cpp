#include "Cvijet.h"
Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

void Cvijet::draw(int x,int y)
{
	sf::CircleShape blb(50.f);
	blb.setFillColor(sf::Color(255,255,0));
	blb.setOutlineThickness(20.f);
	blb.setOutlineColor(sf::Color(255, 0, 0));
	blb.setPosition(x, y);

	sf::RectangleShape line(sf::Vector2f(200.f, 10.f));
	line.setFillColor(sf::Color(0,255,0));
	line.setPosition(x+55.f, y+50.f);
	line.rotate(90.f);

	sf::ConvexShape con;
	con.setPointCount(4);
	con.setFillColor(sf::Color(0, 255, 0));
	con.setPoint(0, sf::Vector2f(x+50.f, y+200.f));
	con.setPoint(1, sf::Vector2f(x+100.f, y+160.f));
	con.setPoint(2, sf::Vector2f(x+200.f, y+140.f));
	con.setPoint(3, sf::Vector2f(x+100.f, y+205.f));

	window->draw(line);
	window->draw(blb);
	window->draw(con);
	
}

void Cvijet::anidraw(sf::Clock frameClock)
{
	sf::CircleShape s(40.f);
	s.setFillColor(sf::Color(255, 255, 0));
	s.setOutlineThickness(10.f);
	s.setOutlineColor(sf::Color(255, 155, 0));
	if ((frameClock.getElapsedTime().asMilliseconds() / 1000) % 2 == 0) {
		s.setPosition(frameClock.getElapsedTime().asMilliseconds() % 1000, 50.f);
	}
	else
		s.setPosition(1000.f, 1000.f);
	

	sf::CircleShape m(50.f);
	m.setFillColor(sf::Color(255, 255, 255));
	if ((frameClock.getElapsedTime().asMilliseconds() / 1000) % 2 != 0) {
		m.setPosition(frameClock.getElapsedTime().asMilliseconds() % 1000, 50.f);
	}
	else
		m.setPosition(1000.f, 1000.f);
	sf::CircleShape h(40.f);
	h.setFillColor(sf::Color(0, 0, 0));
	h.setPosition(m.getPosition().x + 5.f, m.getPosition().y);
	
	sf::RectangleShape gras(sf::Vector2f(1000.f, 200.f));
	gras.setFillColor(sf::Color(0, 100, 100));
	gras.setPosition(0.f, 450.f);

	window->draw(m);
	window->draw(h);
	window->draw(s);
	window->draw(gras);
}

