#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window):window(window)
{
	
	glava.setRadius(60.f);
	glava.setPosition(260.f, 220.f);
	glava.setFillColor(sf::Color::Red);
	
	glava1.setRadius(50.f);
	glava1.setPosition(250.f, 220.f);
	glava1.setFillColor(sf::Color(130, 0, 0));

	stabljika.setSize(sf::Vector2f(20.f, 245.f));
	stabljika.setPosition(290.f, 280.f);
	stabljika.setFillColor(sf::Color::Green);
	
	list1.setPointCount(4);
	list1.setPoint(0, sf::Vector2f(65.f, 65.f));
	list1.setPoint(1, sf::Vector2f(75.f, 75.f));
	list1.setPoint(2, sf::Vector2f(65.f, 110.f));
	list1.setPosition(230.f, 315.f);
	list1.setFillColor(sf::Color::Green);
	
	sunce.setPosition(0.f, 0.f);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setRadius(50.f);
	 
	pod.setSize(sf::Vector2f(1200.f, 1800.f));
	pod.setPosition(1.f, 500.f);
	pod.setFillColor(sf::Color::Green);
	
	while (window.isOpen())
	{
		sf::Event event;


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


		}
		if (clock.getElapsedTime().asSeconds() > 1.0f) {
			if (sunce.getRadius() == 15.f)
				sunce.setRadius(5.f);
			else
				sunce.setRadius(15.f);


			clock.restart();
			
		}
		window.clear();
		window.draw(stabljika);
		window.draw(list1);
		window.draw(sunce);
		window.draw(pod);
		window.draw(glava);
		window.draw(glava1);
		window.display();	
	

	}
}

void Cvijet::draw()
{
}
