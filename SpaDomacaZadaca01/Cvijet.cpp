#include "Cvijet.h"
using namespace sf;

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;

	//window->draw(line);
	sf::CircleShape krug(55.f);
	krug.setFillColor(sf::Color(245, 241, 10));
	krug.setPosition(300.f, 210.f);

	sf::CircleShape octagon_mali(70.f, 8);
	octagon_mali.setFillColor(sf::Color(237, 2, 167));
	octagon_mali.setPosition(185.f, 50.f);

	sf::CircleShape krug_mali(40.f);
	krug_mali.setFillColor(sf::Color(245, 241, 10));
	krug_mali.setPosition(215.f, 78.f);

	sf::CircleShape sunce(20.f);
	sunce.setFillColor(sf::Color(245, 241, 10));
	sunce.setPosition(700.f, 20.f);

	sf::CircleShape octagon_veliki(100.f, 8);
	octagon_veliki.setFillColor(sf::Color(237, 2, 175));
	octagon_veliki.setPosition(260.f, 165.f);

	sf::RectangleShape line(sf::Vector2f(400.f, 10.f));
	line.setFillColor(sf::Color(39, 158, 35));
	line.setPosition(257.f, 160.f);
	line.rotate(90.f);

	sf::RectangleShape line_mala(sf::Vector2f(125.f, 10.f));
	line_mala.setFillColor(sf::Color(39, 158, 35));
	line_mala.setPosition(320.f, 350.f);
	line_mala.rotate(120.f);

	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setFillColor(sf::Color(39, 158, 35));
	convex.setPosition(155.f, 275.f);
	convex.rotate(340.f);

	convex.setPoint(0, sf::Vector2f(90.f,50.f));
	convex.setPoint(1, sf::Vector2f(71.f, 73.f));//60 70
	convex.setPoint(2, sf::Vector2f(35.f, 46.f));//50 60;30 50
	convex.setPoint(3, sf::Vector2f(-40.f, -60.f));

	sf::RectangleShape pozadina(sf::Vector2f(12.f, 50.f));
	pozadina.setSize(sf::Vector2f(900.f, 500.f));
	pozadina.setFillColor(sf::Color(86, 172, 204));

	sf::RectangleShape pod(sf::Vector2f(12.f, 50.f));
	pod.setSize(sf::Vector2f(900.f, 500.f));
	pod.setPosition(-30.f, 415.f);
	pod.setFillColor(sf::Color(86, 204, 102));

	window->draw(pozadina);
	window->draw(pod);
	window->draw(line);
	window->draw(convex);
	window->draw(line_mala);
	window->draw(octagon_mali);
	window->draw(octagon_veliki);
	window->draw(krug);
	window->draw(krug_mali);
	window->draw(sunce);

	

	
}
