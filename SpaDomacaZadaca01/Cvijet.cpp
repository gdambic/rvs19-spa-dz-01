#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow* window) : window(window)
{
	for (size_t i = 0; i < 6; ++i)
	{
		sf::ConvexShape petal;
		petal.setPointCount(4); // Set positions and sizes for each petal
		petal.setFillColor(sf::Color::Green);
		petals.push_back(petal);
	}


	circle.setRadius(50);
	circle.setFillColor(sf::Color::Yellow);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(500, 400);


	concentricCircle.setRadius(100);
	concentricCircle.setFillColor(sf::Color::Red);
	concentricCircle.setOrigin(concentricCircle.getRadius(), concentricCircle.getRadius());
	concentricCircle.setPosition(circle.getPosition());


	double stemWidth = 10.f;
	double stemHeight = 250.f;
	stem.setSize(sf::Vector2f(stemWidth, stemHeight));
	stem.setFillColor(sf::Color::Green); 
	stem.setPosition(circle.getPosition().x - stemWidth / 2.f, circle.getPosition().y + concentricCircle.getRadius());

	sun.setRadius(15);
	sun.setFillColor(sf::Color::Yellow);
	sun.setPosition(50, 50);

	frameClock.restart();
}

void Cvijet::draw_flower()
{
	double scaleFactor = 1.f;
	double scaleFactorChange = 0.1f;

	if (frameClock.getElapsedTime().asSeconds() < 1.5) { 
		sun.setRadius(sun.getRadius() + scaleFactorChange);
		if (sun.getRadius() >= 30) { 
			sun.setRadius(30);
		}
	}
	else if (frameClock.getElapsedTime().asSeconds() < 3) { 
		sun.setRadius(sun.getRadius() - scaleFactorChange);
		if (sun.getRadius() <= 15) { 
			sun.setRadius(15);
		}
	}
	else { 
		frameClock.restart();
		
	}


	for (size_t i = 0; i < petals.size(); ++i)
	{
		window->draw(petals.at(i));
	}
		window->draw(concentricCircle);
		window->draw(circle);
		window->draw(stem);

		window->draw(sun);

}
