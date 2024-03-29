#include "Flower.h"
#include <cmath>

Flower::Flower(sf::RenderWindow* window) : window(window) {
	sun.setFillColor(sf::Color(252, 215, 3));
	sun.setRadius(30.f);
	sun.setPosition(sf::Vector2f(50.f, 100.f));

	ground.setFillColor(sf::Color(22, 161, 3));
	ground.setSize(sf::Vector2f(800.f, 50.f));
	ground.setPosition(sf::Vector2f(0.f, 550.f));

	stem.setFillColor(sf::Color(4, 199, 7));
	stem.setSize(sf::Vector2f(20.f, 200.f));
	stem.setPosition(sf::Vector2f(350.f, 350.f));
	
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(25.f, 75.f));
	leaf.setPoint(1, sf::Vector2f(100.f, 100.f));
	leaf.setPoint(2, sf::Vector2f(75.f, 25.f));
	leaf.setPoint(3, sf::Vector2f(0.f, 0.f));
	leaf.setFillColor(sf::Color(58, 199, 60));
	leaf.setPosition(sf::Vector2f(250.f, 400.f));

	center.setFillColor(sf::Color(245, 212, 2));
	center.setRadius(80.f);
	center.setPosition(sf::Vector2f(280.f, 190.f));


	for (size_t i = 0; i < 2; i++){
		eyes[i].setFillColor(sf::Color::Black);
		eyes[i].setRadius(5.f);
	}
	eyes[0].setPosition(sf::Vector2f(320.f, 225.f));
	eyes[1].setPosition(sf::Vector2f(380.f, 225.f));

	mouth.setFillColor(sf::Color::Black);
	mouth.setSize(sf::Vector2f(20.f, 2.f));
	mouth.setPosition(sf::Vector2f(350.f, 250.f));

	sf::Vector2f position;
	const int n = 8;
	for (size_t i = 0; i < n; i++) {
		sf::CircleShape temp;
		temp.setRadius(60);
		temp.setFillColor(sf::Color(245, 80, 25));

		float angleRad = (360.f / n) * i * (3.14159f / 180.f);
		float circleX = position.x + temp.getRadius() * cos(angleRad);
		float circleY = position.y + temp.getRadius() * sin(angleRad);
		temp.setPosition(circleX + 300.f, circleY + 210.f);

		petal.push_back(temp);
	}

}

void Flower::draw() {
	window->draw(ground);

	window->draw(stem);

	window->draw(leaf);

	for (size_t i = 0; i < petal.size(); i++){
		window->draw(petal[i]);
	}

	window->draw(center);

	for (size_t i = 0; i < 2; i++){
		if (clock[0].getElapsedTime().asSeconds() < 0.25) {
			eyes[i].setFillColor(sf::Color(245, 212, 2));
		}
		else if (clock[0].getElapsedTime().asSeconds() < 3) {
			eyes[i].setFillColor(sf::Color::Black);
		}
		else {
			clock[0].restart();
		}
		window->draw(eyes[i]);
	}

	window->draw(mouth);
		
	if (clock[1].getElapsedTime().asSeconds() < 4) {
		sun.move(0.f, -0.2f);
	}
	else if(clock[1].getElapsedTime().asSeconds() < 8) {
		sun.move(0.f, 0.2f);
	}
	else {
		clock[1].restart();
	}
	window->draw(sun);
}
