#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{

	sf::CircleShape SredinaCvijeta(30.f, 20);
	SredinaCvijeta.setFillColor(sf::Color::Yellow);
	SredinaCvijeta.setPosition(340.f, 168.f);


	sf::CircleShape LaticaCvijeta(90.f, 10);
	LaticaCvijeta.setFillColor(sf::Color(255, 0, 0));
	LaticaCvijeta.setPosition(280.f, 110.f);


	sf::CircleShape LaticaCvijeta2(100.f, 10);
	LaticaCvijeta2.setFillColor(sf::Color(255, 0, 0, 200));
	LaticaCvijeta2.setPosition(360.f, 190.f);
	LaticaCvijeta2.rotate(90.f + clock.getElapsedTime().asMicroseconds() / 3);


	sf::CircleShape LaticaCvijeta3(100.f, 10);
	LaticaCvijeta3.setFillColor(sf::Color(255, 0, 0, 200));
	LaticaCvijeta3.setPosition(360.f, 190.f);
	LaticaCvijeta3.rotate(180.f + clock.getElapsedTime().asMicroseconds() / 3);


	sf::CircleShape LaticaCvijeta4(100.f, 10);
	LaticaCvijeta4.setFillColor(sf::Color(255, 0, 0, 200));
	LaticaCvijeta4.setPosition(360.f, 190.f);
	LaticaCvijeta4.rotate(270.f + clock.getElapsedTime().asMicroseconds() / 3);


	sf::CircleShape LaticaCvijeta5(100.f, 10);
	LaticaCvijeta5.setFillColor(sf::Color(255, 0, 0, 200));
	LaticaCvijeta5.setPosition(360.f, 190.f);
	LaticaCvijeta5.rotate(360.f + clock.getElapsedTime().asMicroseconds() / 3);


	sf::RectangleShape Trava(sf::Vector2f(800.f, 50.f));
	Trava.setFillColor(sf::Color::Green);
	Trava.setPosition(0.f, 560.f);


	sf::RectangleShape Pozadina(sf::Vector2f(1500.f, 50.f));
	Pozadina.setFillColor(sf::Color(20, 20, 20));
	Pozadina.setPosition(0.f, 0.f);
	Pozadina.setScale(3000.f, 300.f);


	sf::RectangleShape Grana(sf::Vector2f(400.f, 5.f));
	Grana.setFillColor(sf::Color::Green);
	Grana.rotate(90.f);
	Grana.setPosition(370.f, 200.f);


	sf::CircleShape	Sunce(90.f, 35);
	Sunce.setFillColor(sf::Color::Yellow);
	Sunce.setPosition(-70.f, -70.f);

	window->draw(Pozadina);
	window->draw(Grana);
	window->draw(Trava);
	window->draw(Sunce);
	window->draw(LaticaCvijeta);
	window->draw(LaticaCvijeta2);
	window->draw(LaticaCvijeta3);
	window->draw(LaticaCvijeta4);
	window->draw(LaticaCvijeta5);
	window->draw(SredinaCvijeta);
}

	
	
	

	
	

