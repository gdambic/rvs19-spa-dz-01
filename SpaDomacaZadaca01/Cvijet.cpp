#include "Cvijet.h"

using namespace sf;

Cvijet::Cvijet(RenderWindow* windows)
{
	this->window = windows;
}

void Cvijet::draw()
{
	// BACKGROUND
	RectangleShape rectangle(Vector2f(800.f, 200.f));
	rectangle.setFillColor(Color::Color(0, 100, 0));
	rectangle.setPosition(0.f, 400.f);

	RectangleShape rectangle2(Vector2f(800.f, 400.f));
	rectangle2.setFillColor(Color::Color(173, 216, 230));
	rectangle2.setPosition(0.f, 0.f);

	// FLOWER HEAD
	CircleShape octagon(12.f, 8);
	octagon.setFillColor(Color::Color(255, 192, 203));
	octagon.setOutlineColor(Color::Color(160, 32, 240));
	octagon.setOutlineThickness(1);
	octagon.setPosition(401.f, 208.0f);
	octagon.setRotation(5);


	circle.setRadius(6);
	circle.setFillColor(Color::Color(160, 32, 240));
	circle.setOutlineColor(Color::Color(255, 100, 0));
	circle.setOutlineThickness(2);
	circle.setPosition(405.f, 215.0f);

	circle1.setRadius(20);
	circle1.setFillColor(Color::Color(255, 192, 203));
	circle1.setOutlineColor(Color::Color(160, 32, 240));
	circle1.setOutlineThickness(2);
	circle1.setPosition(385.0f, 215.0f);

	circle2.setRadius(20);
	circle2.setFillColor(Color::Color(255, 192, 203));
	circle2.setOutlineColor(Color::Color(160, 32, 240));
	circle2.setOutlineThickness(2);
	circle2.setPosition(385.0f, 185.0f);

	circle3.setRadius(20);
	circle3.setFillColor(Color::Color(255, 192, 203));
	circle3.setOutlineColor(Color::Color(160, 32, 240));
	circle3.setOutlineThickness(2);
	circle3.setPosition(415.0f, 185.0f);

	circle4.setRadius(20);
	circle4.setFillColor(Color::Color(255, 192, 203));
	circle4.setOutlineColor(Color::Color(160, 32, 240));
	circle4.setOutlineThickness(2);
	circle4.setPosition(415.0f, 215.0f);

	circle5.setRadius(20);
	circle5.setFillColor(Color::Color(255, 192, 203));
	circle5.setOutlineColor(Color::Color(160, 32, 240));
	circle5.setOutlineThickness(2);
	circle5.setPosition(420.0f, 200.0f);

	ConvexShape leaf(4);
	leaf.setPoint(0, Vector2f(420.f, 305.f));
	leaf.setPoint(1, Vector2f(460.f, 300.f));
	leaf.setPoint(2, Vector2f(430.f, 320.f));
	leaf.setPoint(3, Vector2f(420.f, 300.f));
	leaf.setFillColor(Color::Green);
	leaf.setOutlineThickness(2);
	leaf.setOutlineColor(Color::Black);

	ConvexShape leaf2(4);
	leaf2.setPoint(0, Vector2f(415.f, 305.f));
	leaf2.setPoint(1, Vector2f(380.f, 300.f));
	leaf2.setPoint(2, Vector2f(380.f, 320.f));
	leaf2.setPoint(3, Vector2f(415.f, 300.f));
	leaf2.setFillColor(Color::Green);
	leaf2.setOutlineThickness(2);
	leaf2.setOutlineColor(Color::Black);


	RectangleShape line(Vector2f(200.f, 5.f));
	line.setPosition(420.f, 205.f);
	line.rotate(90);
	line.setFillColor(Color::Green);
	line.setOutlineThickness(2);
	line.setOutlineColor(Color::Black);

	cloud.setRadius(20);
	cloud.setFillColor(Color::White);
	cloud.setOutlineColor(Color::Blue);
	cloud.setOutlineThickness(1);
	cloud.setOrigin(0,-60);

	cloud2.setRadius(20);
	cloud2.setFillColor(Color::White);
	cloud2.setOutlineColor(Color::Blue);
	cloud2.setOutlineThickness(1);
	cloud2.setOrigin(-35,-60);

	cloud3.setRadius(20);
	cloud3.setFillColor(Color::White);
	cloud3.setOutlineColor(Color::Blue);
	cloud3.setOutlineThickness(1);
	cloud3.setOrigin(-20,-35);

	cloud4.setRadius(20);
	cloud4.setFillColor(Color::White);
	cloud4.setOutlineColor(Color::Blue);
	cloud4.setOutlineThickness(1);
	cloud4.setOrigin(-150,-150);

	cloud5.setRadius(20);
	cloud5.setFillColor(Color::White);
	cloud5.setOutlineColor(Color::Blue);
	cloud5.setOutlineThickness(1);
	cloud5.setOrigin(-165,-125);

	cloud6.setRadius(20);
	cloud6.setFillColor(Color::White);
	cloud6.setOutlineColor(Color::Blue);
	cloud6.setOutlineThickness(1);
	cloud6.setOrigin(-185,-150);


	circleSun.setRadius(10);
	circleSun.setFillColor(Color::Yellow);
	circleSun.setOutlineThickness(3);
	circleSun.setOutlineColor(Color::Color(255, 80, 0));
	//ANIMATION

	if (cloud.getPosition().x < 800) {
		cloud.move(2,0);
		cloud2.move(2,0);
		cloud3.move(2,0);
		cloud4.move(2,0);
		cloud5.move(2,0);
		cloud6.move(2,0);

	}
	else {
		cloud.setPosition(0.f, 40.f);
		cloud2.setPosition(5.f, 40.f);
		cloud3.setPosition(0.f, 35.f);
		cloud4.setPosition(0.f, 50.f);
		cloud5.setPosition(5.f, 45.f);
		cloud6.setPosition(0.f, 50.f);
		
	}

	if (circleSun.getPosition().x < 800) {
		circleSun.move(1.f, 0.f);
		float x_pos = circleSun.getPosition().x / 10;
		float x_pos2 = (900.f - circleSun.getPosition().x) / 10;
		if (circleSun.getPosition().x <= 400)
			circleSun.setRadius(circleSun.getRadius() + x_pos);
		else if (circleSun.getPosition().x < 800) {
			if (x_pos2 > 10)
				circleSun.setRadius(x_pos2);
			else circleSun.setRadius(10);
		}
	}
	else {
		circleSun.setPosition(0.f, 0.f);
		circleSun.setRadius(10);
	}


	// DRAWING

	window->draw(rectangle);
	window->draw(rectangle2);
	window->draw(line);
	window->draw(leaf);
	window->draw(leaf2);
	window->draw(circleSun);
	window->draw(cloud);
	window->draw(cloud2);
	window->draw(cloud3);
	window->draw(cloud4);
	window->draw(cloud5);
	window->draw(cloud6);
	window->draw(circle1);
	window->draw(circle2);
	window->draw(circle3);
	window->draw(circle4);
	window->draw(circle5);
	window->draw(octagon);
	window->draw(circle);
}

