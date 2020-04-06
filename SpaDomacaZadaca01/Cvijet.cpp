#include "Cvijet.h"
#include <SFML/Graphics.hpp>
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->moj_window = window;
}

void Cvijet::draw()
{

	sf::CircleShape shape(20.f);
	
	sf::RectangleShape tlo(sf::Vector2f(800.f, 100.f));
	tlo.setFillColor(sf::Color::Green);
	tlo.setPosition(0, 500);

	sf::RectangleShape stabljika(sf::Vector2f(10.f,400.f));
	stabljika.setPosition(sf::Vector2f(390, 280));
	stabljika.setFillColor(sf::Color::Green);
	moj_window->draw(stabljika);

	sf::CircleShape square(98.f, 4);
	square.setPosition(300,100);
	moj_window->draw(square);

	sf::VertexArray latica(sf::Triangles, 3);

	
	latica[0].position = sf::Vector2f(300.f, 100.f);
	latica[1].position = sf::Vector2f(390.f, 100.f);
	latica[2].position = sf::Vector2f(390.f, 190.f);

	latica[0].color = sf::Color::Red;
	latica[1].color = sf::Color::Yellow;
	latica[2].color = sf::Color::White;
	
	moj_window->draw(latica);
	sf::VertexArray latica2(sf::Triangles, 3);

	latica2[0].position = sf::Vector2f(400.f, 200.f);
	latica2[1].position = sf::Vector2f(490.f, 200.f);
	latica2[2].position = sf::Vector2f(490.f, 290.f);

	latica2[0].color = sf::Color::Red;
	latica2[1].color = sf::Color::Yellow;
	latica2[2].color = sf::Color::White;
	
	moj_window->draw(latica2);
	moj_window->draw(latica);
	sf::VertexArray latica3(sf::Triangles, 3);

	latica3[0].position = sf::Vector2f(390.f, 210.f);
	latica3[1].position = sf::Vector2f(300.f, 210.f);
	latica3[2].position = sf::Vector2f(300.f, 300.f);
	
	latica3[0].color = sf::Color::Red;
	latica3[1].color = sf::Color::Yellow;
	latica3[2].color = sf::Color::White;

	moj_window->draw(latica3);
	
	shape.setPosition(sf::Vector2f(370, 185));
	shape.setFillColor(sf::Color::Yellow);
	shape.setOutlineThickness(6.f);
	shape.setOutlineColor(sf::Color::Red);
	sf::CircleShape sun(frameClock.getElapsedTime().asSeconds() * 25, 10);
	sun.setFillColor(sf::Color::Yellow);
	


	if (frameClock.getElapsedTime().asSeconds() > 4)
	{
		frameClock.restart();
	}

	sun.setPosition(sf::Vector2f(frameClock.getElapsedTime().asSeconds()*10,10));

	moj_window->draw(tlo);
	
	moj_window->draw(shape);
	
	moj_window->draw(sun);
	
	
	

}
