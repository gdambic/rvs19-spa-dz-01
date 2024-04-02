#include <ctime>
#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
	seed = time(nullptr);
}

void Cvijet::draw()
{
	window->clear(sf::Color::Color(0, 208, 255));
	drawGround();
	drawSun();
	drawStem();
	drawFlower();
	drawLeaf();
}

void Cvijet::setSeed(int seed) {
	this->seed = seed;
}

void Cvijet::drawGround()
{
	ground.setPointCount(11);

	srand(seed);
	flower_position = rand() % (5) + 1;

	for (size_t i = 0; i < 9; i++)
	{
		float offset = (rand() % (500+1)) /10;
		ground.setPoint(i, sf::Vector2f(0.f+(i*100), 500.f+offset));

	}
	ground.setPoint(9, sf::Vector2f(800.f, 600.f));
	ground.setPoint(10, sf::Vector2f(0.f, 600.f));

	ground.setFillColor(sf::Color::Color(6, 143, 28));

	window->draw(ground);
}

void Cvijet::drawStem()
{
	stem.setFillColor(sf::Color::Green);

	stem.setSize(sf::Vector2f(10, 300));
	stem.setOrigin(sf::Vector2f(0, stem.getSize().y));
	stem.setPosition(ground.getPoint(flower_position).x - (stem.getSize().x / 2), ground.getPoint(flower_position).y+1);

	window->draw(stem);

}

void Cvijet::drawFlower()
{
	float radius = 50;
	auto flower_color = sf::Color::Color(rand() % 256, rand() % 256, rand() % 256);

	float x = ground.getPoint(flower_position).x;
	float y = ground.getPoint(flower_position).y - stem.getSize().y;

	flower_center.setRadius(radius);
	flower_center.setFillColor(sf::Color::Yellow);
	flower_center.setOrigin(radius, radius);
	flower_center.setPosition(x, y);

	flower1.setRadius(radius);
	flower1.setFillColor(flower_color);	
	flower1.setOrigin(2* radius, 2* radius);
	flower1.setPosition(x, y);
	
	flower2.setRadius(radius);
	flower2.setFillColor(flower_color);
	flower2.setOrigin(2* radius, 0);
	flower2.setPosition(x, y);
	
	flower3.setRadius(radius);
	flower3.setFillColor(flower_color);
	flower3.setOrigin(0, 2* radius);
	flower3.setPosition(x, y);
	
	flower4.setRadius(radius);
	flower4.setFillColor(flower_color);
	flower4.setOrigin(0, 0);
	flower4.setPosition(x, y);

	window->draw(flower1);
	window->draw(flower2);
	window->draw(flower3);
	window->draw(flower4);
	window->draw(flower_center);
}

void Cvijet::drawLeaf()
{
	float offset = (rand() % (75)) -50;

	leaf1.setPointCount(4);
	leaf1.setFillColor(sf::Color::Green);
	leaf1.setPoint(0, sf::Vector2f(stem.getPosition().x, stem.getPosition().y-(stem.getSize().y/3)+offset));

	leaf1.setPoint(1, sf::Vector2f(leaf1.getPoint(0).x - 50, leaf1.getPoint(0).y - 50));
	leaf1.setPoint(2, sf::Vector2f(leaf1.getPoint(0).x - 100, leaf1.getPoint(0).y - 75));
	leaf1.setPoint(3, sf::Vector2f(leaf1.getPoint(0).x - 75, leaf1.getPoint(0).y - 25));
	
	offset = (rand() % (51)) - 25;

	leaf2.setPointCount(4);
	leaf2.setFillColor(sf::Color::Green);
	leaf2.setPoint(0, sf::Vector2f(stem.getPosition().x + stem.getSize().x, stem.getPosition().y-(stem.getSize().y/3)+offset));

	leaf2.setPoint(1, sf::Vector2f(leaf2.getPoint(0).x + 50, leaf2.getPoint(0).y - 50));
	leaf2.setPoint(2, sf::Vector2f(leaf2.getPoint(0).x + 100, leaf2.getPoint(0).y - 75));
	leaf2.setPoint(3, sf::Vector2f(leaf2.getPoint(0).x + 75, leaf2.getPoint(0).y - 25));

	window->draw(leaf1);
	window->draw(leaf2);
}

void Cvijet::drawSun()
{
	sun.setRadius(50.f);

	sun.setOrigin(sun.getRadius(), sun.getRadius());
	sun.setPosition(rand()% (700-100+1)+100, 100);

	sun.setFillColor(sf::Color::Yellow);

	window->draw(sun);

	sunAnimation();
}

void Cvijet::sunAnimation()
{
	sun_effect.setFillColor(sf::Color::Transparent);

	sun_effect.setOutlineColor(sf::Color::Yellow);
	sun_effect.setOutlineThickness(10);

	float elapsed_time = clock.restart().asSeconds();
	sun_effect.setRadius(sun_effect.getRadius() + elapsed_time *50);

	if(sun_effect.getRadius()>100)
		sun_effect.setRadius(40);

	sun_effect.setOrigin(sun_effect.getRadius(), sun_effect.getRadius());
	sun_effect.setPosition(sun.getPosition());

	window->draw(sun_effect);
}
