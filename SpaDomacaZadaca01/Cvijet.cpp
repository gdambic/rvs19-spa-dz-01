#include "Cvijet.h"
#include <iostream>
using namespace std;

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	//tucak
	CircleShape shape(50);
	shape.setPosition(350, 100);
	shape.setFillColor(Color(241, 39, 28));
	shape.setOutlineThickness(10);
	shape.setOutlineColor(Color(81, 247, 241));

	//stabljika
	RectangleShape line(Vector2f(150, 5));
	line.rotate(90);
	line.setPosition(400, 210);
	line.setFillColor(Color(5, 142, 35));

	//tekstura lista
	Texture texture;

	texture.setSmooth(true);
	texture.setRepeated(false);

	//list
	RectangleShape leaf(Vector2f(100, 100));
	leaf.setPosition(450, 150);
	leaf.rotate(55);

	//ucitavanje teksture
	if (!texture.loadFromFile("leaf.png")) {
		cout << "Nije ispravno ucitalo teksturu";
		leaf.setFillColor(Color(4, 124, 38));
	}
	else {
		leaf.setTexture(&texture);
	}

	//animacija
	int movement = frameClock.getElapsedTime().asMilliseconds() / 25;

	if (leaf.getPosition().y + movement < 260) {
		leaf.move(0, movement);
	}
	else {
		leaf.setPosition(450, 150);
		frameClock.restart();
	}

	window->draw(shape);
	window->draw(line);
	window->draw(leaf);

}
