#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}


void Cvijet::drawSunce() {

	float radius = 30.f;
	sf::CircleShape sunce(radius); 
	
	sunce.move(10.f, 10.f);
	sunce.setFillColor(sf::Color::Yellow);
	sf::Time elapsed = clock.getElapsedTime();


	if (clock.getElapsedTime().asSeconds() > 2)//gledamo koiko je vremena proteklo
	{
		sunce.setFillColor(sf::Color{ 0x373737FF });
		if (clock.getElapsedTime().asSeconds() >= 3)
		{
			clock.restart();
		}
	}
	else
	{
		sunce.setFillColor(sf::Color::Yellow);
	}
	
	window->draw(sunce);


}


void Cvijet::drawCvijet() {


	float sirinaUnutarnjegDijela = 60.f;
	float sirinaVanjskogDijela = 30.f;
	sf::CircleShape cvijet(sirinaUnutarnjegDijela);
	cvijet.move(300.f, 150.f);
	cvijet.setFillColor(sf::Color::Yellow);

	if (clock.getElapsedTime().asSeconds() > 2)
	{
		cvijet.setFillColor(sf::Color::Red);
		if (clock.getElapsedTime().asSeconds() >= 3)
		{
			clock.restart();
		}
	}
	else
	{
		cvijet.setFillColor(sf::Color::Yellow);
	}


	cvijet.setOutlineThickness(sirinaVanjskogDijela);
	cvijet.setOutlineColor(sf::Color::Red);
	if (clock.getElapsedTime().asSeconds() > 2)
	{
		cvijet.setOutlineColor(sf::Color::Yellow);
		if (clock.getElapsedTime().asSeconds() >= 3)
		{
			clock.restart();
		}
	}
	else
	{
		cvijet.setOutlineColor(sf::Color::Red);
	}

	window->draw(cvijet);


}


void Cvijet::drawPeteljka()
{	
	
	sf::RectangleShape peteljka(sf::Vector2f(150.f,10.f));
	peteljka.setFillColor(sf::Color::Green);
	peteljka.move(365.f, 295.f);
	peteljka.rotate(90.f);
	window->draw(peteljka);

}

void Cvijet::drawList() {

	sf::ConvexShape list;
	list.setPointCount(4);//broj kuteva lista
	list.setPoint(0, sf::Vector2f(100.f, 0.f));
	list.setPoint(1, sf::Vector2f(150.f, 50.f));
	list.setPoint(2, sf::Vector2f(70.f, 50.f));
	list.setPoint(3, sf::Vector2f(0.f, 0.f));
	list.setFillColor(sf::Color::Green);
	list.move(205.f, 305.f);

	window->draw(list);
}

void Cvijet::draw() {

	drawSunce();
	drawCvijet();
	drawPeteljka();
	drawList();

}