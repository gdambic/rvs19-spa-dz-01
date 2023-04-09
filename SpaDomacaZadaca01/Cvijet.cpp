#include "Cvijet.h"
#include <SFML/Graphics.hpp>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	// moon and moon dots

	sf::CircleShape moon(70.f);
	moon.setFillColor(sf::Color(246, 241, 213));
	moon.setPosition(50.f, 100.f);

	sf::CircleShape moon_dot(20.f);
	moon_dot.setFillColor(sf::Color(210, 213, 201));
	moon_dot.setPosition(80.f, 170.f);

	sf::CircleShape moon_dot2(20.f);
	moon_dot2.setFillColor(sf::Color(220, 213, 210));
	moon_dot2.setPosition(130.f, 120.f);

	window->draw(moon);
	window->draw(moon_dot);
	window->draw(moon_dot2);

	//flower 1 

	sf::CircleShape flower1(50.f);
	flower1.setPointCount(200);
	flower1.setPosition(150.f, 400.f);
	flower1.setFillColor(sf::Color(54, 34, 4));
	flower1.setOutlineThickness(10.f);
	flower1.setOutlineColor(sf::Color(255, 255, 0));

	sf::RectangleShape stable1(sf::Vector2f(150, 7));
	stable1.setFillColor(sf::Color(0, 255, 0));
	stable1.setPosition(203.f, 510.f);
	stable1.rotate(100);

	sf::RectangleShape leaf_stable1(sf::Vector2f(50, 7));
	leaf_stable1.setFillColor(sf::Color(0, 255, 0));
	leaf_stable1.setPosition(153.f, 570.f);
	leaf_stable1.rotate(50);

	sf::CircleShape leaf1(30, 3);
	leaf1.setFillColor(sf::Color(0, 255, 0));
	leaf1.setPosition(180.f, 560.f);
	leaf1.rotate(130);

	window->draw(flower1);
	window->draw(stable1);
	window->draw(leaf_stable1);
	window->draw(leaf1);

	//flower 2

	sf::CircleShape flower2(35.f);
	flower2.setPointCount(200);
	flower2.setPosition(407.f, 441.f);
	flower2.setFillColor(sf::Color(255, 255, 255));

	sf::RectangleShape stable2(sf::Vector2f(150, 7));
	stable2.setFillColor(sf::Color(0, 100, 0));
	stable2.setPosition(453.f, 510.f);
	stable2.rotate(80);

	window->draw(flower2);
	window->draw(stable2);

	// flower 3 (3 tulip leafs etc.)

	sf::CircleShape flower3(10.f);
	flower3.setPointCount(200);
	flower3.setPosition(835.f, 455.f);
	flower3.setFillColor(sf::Color(240, 0, 0));
	flower3.scale(5.f, 3.f);
	flower3.rotate(110);

	sf::CircleShape flower4(10.f);
	flower4.setPointCount(200);
	flower4.setPosition(800.f, 441.f);
	flower4.setFillColor(sf::Color(210, 0, 0));
	flower4.scale(5.f, 3.f);
	flower4.rotate(90);

	sf::CircleShape flower5(10.f);
	flower5.setPointCount(200);
	flower5.setPosition(765.f, 435.f);
	flower5.setFillColor(sf::Color(190, 0, 0));
	flower5.scale(5.f, 3.f);
	flower5.rotate(70);

	sf::RectangleShape stable3(sf::Vector2f(180, 7));
	stable3.setFillColor(sf::Color(0, 150, 0));
	stable3.setPosition(780.f, 540.f);
	stable3.rotate(90);

	sf::RectangleShape leaf_stable2(sf::Vector2f(50, 7));
	leaf_stable2.setFillColor(sf::Color(0, 150, 0));
	leaf_stable2.setPosition(748.f, 585.f);
	leaf_stable2.rotate(50);

	sf::CircleShape leaf2(7.f);
	leaf2.setPointCount(200);
	leaf2.setPosition(710.f, 510.f);
	leaf2.setFillColor(sf::Color(0, 150, 0));
	leaf2.scale(7.f, 3.f);
	leaf2.rotate(50);

	sf::RectangleShape leaf_stable3(sf::Vector2f(50, 7));
	leaf_stable3.setFillColor(sf::Color(0, 150, 0));
	leaf_stable3.setPosition(810.f, 565.f);
	leaf_stable3.rotate(130);

	sf::CircleShape leaf3(7.f);
	leaf3.setPointCount(200);
	leaf3.setPosition(880.f, 510.f);
	leaf3.setFillColor(sf::Color(0, 150, 0));
	leaf3.scale(7.f, 3.f);
	leaf3.rotate(130);

	window->draw(flower3);
	window->draw(flower4);
	window->draw(flower5);
	window->draw(stable3); 
	window->draw(leaf_stable2);
	window->draw(leaf2);
	window->draw(leaf_stable3);
	window->draw(leaf3);

	//ground

	sf::RectangleShape ground(sf::Vector2f(1000, 800));
	ground.setPosition(0, 655);
	ground.setFillColor(sf::Color(150, 75, 0));

	window->draw(ground);
	
}
