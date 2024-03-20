#include "Flower.h"
using namespace sf;


CircleShape Flower::drawSun(int radius, int x, int y) {
	
	CircleShape sun(radius);
	sun.setFillColor(Color::Yellow);
	sun.setPosition(x, y); 
	return sun;
}

CircleShape Flower::flowerCenter() {

	CircleShape center(40);
	center.setFillColor(Color(17, 165, 57));
	center.setOrigin(50, 50);
	center.setPosition(250, 180);
	
	return center;
}


CircleShape Flower::drawPetals (int a, int b) {


	CircleShape petals(50);
	petals.setFillColor(Color(158, 72, 98));
	petals.setOrigin(50,50);

	petals.setPosition(a,b);
	
	return petals;
}

RectangleShape Flower::drawStem() {

	RectangleShape stem(Vector2f(12,330)); //width,height
	stem.setFillColor(Color(149, 240, 103));
	stem.setPosition(240, 270);
	
	return stem;
}

ConvexShape Flower::drawLeafs() {

	ConvexShape leaf;
	leaf.setPointCount(4);

	leaf.setPoint(0, sf::Vector2f(252.f, 440.f));
	leaf.setPoint(1, sf::Vector2f(350.f, 350.f));
	leaf.setPoint(2, sf::Vector2f(500.f, 360.f));
	leaf.setPoint(3, sf::Vector2f(350.f, 460.f));
	leaf.setFillColor(Color(149, 240, 103));
	return leaf;
}

Flower::Flower(RenderWindow  *window) {
	window_local = window;

}



void Flower::draw(int x ) {

	window_local->draw(drawSun(30, x, 30));
	
	window_local->draw(drawPetals(250 , 120));
	window_local->draw(drawPetals(290, 170));
	window_local->draw(drawPetals(250, 220));
	window_local->draw(drawPetals(200, 170));

	window_local->draw(flowerCenter());
	window_local->draw(drawStem());
	window_local->draw(drawLeafs());

}