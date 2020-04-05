#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color(0,0,0));
	circle.setOutlineThickness(30.f);
	circle.setOutlineColor(sf::Color(255, 165, 0));
	circle.setPosition(300.f, 200.f);

	sf::Vertex vertex(sf::Vector2f(10.f, 50.f), sf::Color(255, 165, 0), sf::Vector2f(100.f, 100.f));
	sf::VertexArray triangle(sf::Triangles, 3);

	triangle[0].position = sf::Vector2f(270.f, 170.f);
	triangle[1].position = sf::Vector2f(390.f, 170.f);
	triangle[2].position = sf::Vector2f(270.f, 290.f);
	triangle[0].color = sf::Color(255, 165, 0);
	triangle[1].color = sf::Color(255, 165, 0);
	triangle[2].color = sf::Color(255, 165, 0);
	
	sf::CircleShape circle2(20.f);
	circle2.setPosition(380, 280);
	circle2.setFillColor(sf::Color(255, 165, 0));

	if (clock.getElapsedTime().asSeconds() > 0.0f) {
		float x = 380 + (70 * cos(fi));
		float y = 280 + (70 * sin(fi));
		circle2.setPosition(x, y);
		fi+=0.05f;
		if (fi > 360)
			fi = 0;
	}

	(*window).draw(circle);
	(*window).draw(circle2);
	(*window).draw(triangle);
}
