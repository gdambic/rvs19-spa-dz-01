#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window)
{
	krug.setFillColor(sf::Color(255, 255, 51));
	krug.setRadius(50.0f);
	krug.setOutlineThickness(25.0f);
	krug.setOutlineColor(sf::Color(220, 20, 60));
	krug.setPosition(350.0f, 250.0f);

	list.setPointCount(4);
	list.setFillColor(sf::Color(0, 100, 0));
	list.setPosition(400.0f, 470.0f);
	list.setPoint(0, sf::Vector2f(0.0f, 10.0f));
	list.setPoint(1, sf::Vector2f(50.0f, -50.0f));
	list.setPoint(2, sf::Vector2f(200.0f, -70.0f));
	list.setPoint(3, sf::Vector2f(75.0f, 30.0f));

	stabljika.setSize(sf::Vector2f(150.0f, 5.0f));
	stabljika.setPosition(400.0f, 375.0f);
	stabljika.setFillColor(sf::Color(0, 100, 0));
	stabljika.rotate(90.0f);

	tlo.setSize(sf::Vector2f(1000.0f, 500.0f));
	tlo.setPosition(0.0f, 525.0f);
	tlo.setFillColor(sf::Color(0, 128, 0));
	
	

}

void Cvijet::Draw(sf::RenderWindow& window)
{

		window.draw(krug);
		window.draw(list);
		window.draw(stabljika);
		window.draw(tlo);
		sf::CircleShape sunce(clock.getElapsedTime().asSeconds() * 8);
		sunce.setFillColor(sf::Color(255, 255, 0));
		if (clock.getElapsedTime().asSeconds()>5)
		{
			clock.restart();

		}
		sunce.setPosition(15, 15);
		window.draw(sunce);
		
	
}
