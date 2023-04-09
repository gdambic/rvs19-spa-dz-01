#include "Cvijet.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Cvijet::Cvijet(RenderWindow* window) {
	this->window = window;
}

void Cvijet::draw() {

	RectangleShape oblaci(Vector2f(800, 600));
	oblaci.setFillColor(Color::White);
	window->draw(oblaci);

	ConvexShape nebo;
	nebo.setPointCount(7);
	nebo.setPoint(0, Vector2f(0, 50));
	nebo.setPoint(1, Vector2f(200, 0));
	nebo.setPoint(2, Vector2f(400, 50));
	nebo.setPoint(3, Vector2f(600, 0));
	nebo.setPoint(4, Vector2f(800, 50));
	nebo.setPoint(5, Vector2f(800, 600));
	nebo.setPoint(6, Vector2f(0, 600));
	nebo.setFillColor(Color(205, 240, 255));
	window->draw(nebo);

	CircleShape sunce(50);
	sunce.setFillColor(Color(253, 184, 19));
	sunce.setPosition(Vector2f(
		window->getSize().x / 2 - sunce.getRadius() + 330,
		window->getSize().y / 2 - sunce.getRadius() - 200
	));
	window->draw(sunce);


	CircleShape tucak(40);
	tucak.setFillColor(Color::Yellow);
	tucak.setPosition(Vector2f(
		window->getSize().x / 2 - tucak.getRadius(),
		window->getSize().y / 2 - tucak.getRadius())
	);
	tucak.setOutlineThickness(30);
	tucak.setOutlineColor(Color(255, 165, 0));
	window->draw(tucak);

	RectangleShape stapka;
	stapka.setPosition(Vector2f(
		window->getSize().x / 2 - 10,
		window->getSize().y / 2 + 66)
	);
	stapka.setSize(Vector2f(20, 200));
	stapka.setFillColor(Color(0, 100, 0));
	window->draw(stapka);

	//crvene
	CircleShape latica1(30);
	latica1.setFillColor(Color(128, 8, 8));
	latica1.setPosition(Vector2f(
		window->getSize().x / 2 - latica1.getRadius(),
		window->getSize().y / 2 - latica1.getRadius() - 90)
	);
	window->draw(latica1);
	CircleShape latica2(30);
	latica2.setFillColor(Color(153, 0, 0));
	latica2.setPosition(Vector2f(
		window->getSize().x / 2 - latica2.getRadius() + 50,
		window->getSize().y / 2 - latica2.getRadius() - 75)
	);
	window->draw(latica2);
	CircleShape latica3(30);
	latica3.setFillColor(Color(177, 18, 38));
	latica3.setPosition(Vector2f(
		window->getSize().x / 2 - latica3.getRadius() + 85,
		window->getSize().y / 2 - latica3.getRadius() - 45)
	);
	window->draw(latica3);
	CircleShape latica4(30);
	latica4.setFillColor(Color(208, 33, 42));
	latica4.setPosition(Vector2f(
		window->getSize().x / 2 - latica4.getRadius() + 93,
		window->getSize().y / 2 - latica4.getRadius() - 3)
	);
	window->draw(latica4);
	CircleShape latica5(30);
	latica5.setFillColor(Color(208, 93, 93));
	latica5.setPosition(Vector2f(
		window->getSize().x / 2 - latica5.getRadius() + 82,
		window->getSize().y / 2 - latica5.getRadius() + 43)
	);
	window->draw(latica5);
	CircleShape latica6(30);
	latica6.setFillColor(Color(250, 160, 160));
	latica6.setPosition(Vector2f(
		window->getSize().x / 2 - latica6.getRadius() + 50,
		window->getSize().y / 2 - latica6.getRadius() + 75)
	);
	window->draw(latica6);

	//plave
	CircleShape latica7(30);
	latica7.setFillColor(Color(0, 0, 139));
	latica7.setPosition(Vector2f(
		window->getSize().x / 2 - latica7.getRadius(),
		window->getSize().y / 2 - latica7.getRadius() + 90)
	);
	window->draw(latica7);
	CircleShape latica8(30);
	latica8.setFillColor(Color(63, 0, 255));
	latica8.setPosition(Vector2f(
		window->getSize().x / 2 - latica8.getRadius() - 50,
		window->getSize().y / 2 - latica8.getRadius() + 75)
	);
	window->draw(latica8);
	CircleShape latica9(30);
	latica9.setFillColor(Color(0, 50, 255));
	latica9.setPosition(Vector2f(
		window->getSize().x / 2 - latica9.getRadius() - 85,
		window->getSize().y / 2 - latica9.getRadius() + 45)
	);
	window->draw(latica9);
	CircleShape latica10(30);
	latica10.setFillColor(Color(64, 224, 208));
	latica10.setPosition(Vector2f(
		window->getSize().x / 2 - latica10.getRadius() - 93,
		window->getSize().y / 2 - latica10.getRadius() + 3)
	);
	window->draw(latica10);
	CircleShape latica11(30);
	latica11.setFillColor(Color(125, 249, 255));
	latica11.setPosition(Vector2f(
		window->getSize().x / 2 - latica11.getRadius() - 82,
		window->getSize().y / 2 - latica11.getRadius() - 43)
	);
	window->draw(latica11);
	CircleShape latica12(30);
	latica12.setFillColor(Color(173, 239, 255));
	latica12.setPosition(Vector2f(
		window->getSize().x / 2 - latica12.getRadius() - 50,
		window->getSize().y / 2 - latica12.getRadius() - 75)
	);
	window->draw(latica12);



	ConvexShape trava;
	trava.setPointCount(8);
	trava.setFillColor(Color(0, 100, 0));
	trava.setPoint(0, Vector2f(0, 500));
	trava.setPoint(1, Vector2f(200, 600));
	trava.setPoint(2, Vector2f(400, 500));
	trava.setPoint(3, Vector2f(600, 600));
	trava.setPoint(4, Vector2f(800, 500));
	trava.setPoint(5, Vector2f(800, 600));
	trava.setPoint(6, Vector2f(0, 600));
	trava.setPoint(7, Vector2f(0, 500));
	window->draw(trava);
}
