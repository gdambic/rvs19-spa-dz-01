#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow& window):window(window)
{

}

void Cvijet::draw()
{

	
	kruznica.setRadius(101.f);
	kruznica.setPosition(200.f, 80.f);
	kruznica.setFillColor(sf::Color(250, 200, 0));
	kruznica.setOutlineThickness(30.f);
	kruznica.setOutlineColor(sf::Color(0, 130, 0));


	
	stabljika.setSize(sf::Vector2f(20.f, 245.f));
	stabljika.setPosition(290.f, 280.f);
	stabljika.setFillColor(sf::Color(0, 130, 0));


	
	list1.setPointCount(4);
	list1.setPoint(0, sf::Vector2f(65.f, 65.f));
	list1.setPoint(1, sf::Vector2f(75.f, 75.f));
	list1.setPoint(2, sf::Vector2f(65.f, 110.f));
	list1.setPosition(230.f, 315.f);
	list1.setFillColor(sf::Color(0, 130, 0));

	

	oblik.setPosition(0.f, 0.f);
	oblik.setFillColor(sf::Color(150, 150, 0));
	oblik.setRadius(50.f);





	while (window.isOpen())
	{
		sf::Event event;
		
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


		}
		if (clock.getElapsedTime().asSeconds() > 1.0f) {
			if (oblik.getRadius() == 50.f)
				oblik.setRadius(10.f);
			else
				oblik.setRadius(50.f);

			
			clock.restart();
		}
		window.clear();
		window.draw(kruznica);
		window.draw(stabljika);
		window.draw(list1);
		window.draw(oblik);
		

		window.display();
	}
}
