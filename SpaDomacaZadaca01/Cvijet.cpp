#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}



void Cvijet::draw_cvijet()
{
	circle.setFillColor(sf::Color::Cyan);
	circle.setPosition(50, 50);
	circle.setRadius(50.f);
	circle.setOutlineThickness(10.f);
	circle.setOutlineColor(sf::Color::Magenta);
	window->draw(circle);
}

void Cvijet::draw_stabiljka()
{
	sf::Vector2f rectanglePosition(90, 160);
	rect.setPosition(rectanglePosition);
	rect.setFillColor(sf::Color::Green);
	rect.setSize(sf::Vector2f(20, 150));
	
}

void Cvijet::draw_list()
{
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(110, 210));
	list.setPoint(1, sf::Vector2f(120, 180));
	list.setPoint(2, sf::Vector2f(190, 190));
	list.setPoint(3, sf::Vector2f(130, 230));
	list.setFillColor(sf::Color::Green);
	window->draw(list);
}

void Cvijet::draw_bee()
{
	
	sf::Time elapsed = clock.getElapsedTime();
	float num = elapsed.asSeconds() * 70;
	//postavke tijelo
	bee.setRadius(30.f);
	bee.setFillColor(sf::Color::Yellow);
	bee.setScale(1.f, 1.f);
	bee.scale(2.f, 1.f);
	oko.setRadius(5.f);
	oko.setFillColor(sf::Color::Black);	
	stripe.setFillColor(sf::Color::Black);
	stripe.setSize(sf::Vector2f(10, 60));

	//pozicije
	beeposition.x = x_bee - p*num;
	beeposition.y = 50;
	bee.setPosition(beeposition);
	oko.setPosition(x_oko - p*num, 70);
	stripe.setPosition(x_stripe - p * num, 50);

	
	if (beeposition.x < 100) {
		 p = -1;
		 x_bee = 100;
		 x_oko = 200;
		 x_stripe = 155;
		 clock.restart();
	}
	else if (beeposition.x > 600) {
		clock.restart();
		p = 1;
		x_bee = 600;
		x_oko = 610;
		x_stripe = 655;
	}

	
	window->draw(bee);
	window->draw(oko);
	window->draw(stripe);
}




void Cvijet::move_stabiljka()
{
	draw_stabiljka();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (rectanglePosition.x < 0 || rectanglePosition.x > 800 -20) xVelocity *= -1;
		if (rectanglePosition.y < 0 || rectanglePosition.y > 600 - 150) yVelocity *= -1;
		rectanglePosition.x += xVelocity;
		rectanglePosition.y += yVelocity;
		rect.setPosition(rectanglePosition);
	}
	window->draw(rect);
}



void Cvijet::draw()
{
	draw_cvijet();
	draw_list();
	draw_bee();
	move_stabiljka();

}




