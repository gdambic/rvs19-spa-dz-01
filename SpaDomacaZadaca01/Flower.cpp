#include "Flower.h"
using namespace sf;

Flower::Flower(RenderWindow* window) {
	this->window = window;
}

void Flower::draw() {
	drawSky();
	drawSun();
	drawGrass();
	drawFlower();
	drawCloud();
}

void Flower::drawSun() {
	CircleShape sun(30.f);
	Vector2f position(30.f, 30.f);
	sun.setPosition(position);
	sun.setFillColor(Color::Yellow);

	// up
	RectangleShape ray1;
	ray1.setSize(Vector2f(2.f, 20.f));
	ray1.setPosition(59.f, 5.f);
	ray1.setFillColor(Color::Yellow);
	window->draw(ray1);

	// down
	RectangleShape ray2;
	ray2.setSize(Vector2f(2.f, 20.f));
	ray2.setPosition(59.f, 95.f);
	ray2.setFillColor(Color::Yellow);
	window->draw(ray2);

	// left
	RectangleShape ray3;
	ray3.setSize(Vector2f(20.f, 2.f));
	ray3.setPosition(5.f, 59.f);
	ray3.setFillColor(Color::Yellow);
	window->draw(ray3);

	// right
	RectangleShape ray4;
	ray4.setSize(Vector2f(20.f, 2.f));
	ray4.setPosition(95.f, 59.f);
	ray4.setFillColor(Color::Yellow);
	window->draw(ray4);

	// up_left
	RectangleShape ray5;
	ray5.setSize(Vector2f(2.f, 30.f));
	ray5.setPosition(13.f, 13.f);
	ray5.setFillColor(Color::Yellow);
	ray5.setRotation(-45.f);
	window->draw(ray5);

	// down_right
	RectangleShape ray6;
	ray6.setSize(Vector2f(2.f, 30.f));
	ray6.setPosition(86.f, 86.f);
	ray6.setFillColor(Color::Yellow);
	ray6.setRotation(-45.f);
	window->draw(ray6);

	// down_left
	RectangleShape ray7;
	ray7.setSize(Vector2f(2.f, 30.f));
	ray7.setPosition(35.f, 86.f);
	ray7.setFillColor(Color::Yellow);
	ray7.setRotation(45.f);
	window->draw(ray7);

	// up_right
	RectangleShape ray8;
	ray8.setSize(Vector2f(2.f, 30.f));
	ray8.setPosition(105.f, 13.f);
	ray8.setFillColor(Color::Yellow);
	ray8.setRotation(45.f);
	window->draw(ray8);

	window->draw(sun);
}

void Flower::drawSky() {
	Vector2f skySize(800.f, 400.f);
	RectangleShape sky(skySize);
	sky.setFillColor(Color(0, 0, 255));
	window->draw(sky);

	Vector2f size(800.f, 100.f);
	Vector2f position(0.f, 300.f);
	RectangleShape background;
	background.setSize(size);
	background.setPosition(position);
	background.setFillColor(Color(1, 50, 32, 150));
	window->draw(background);
}

void Flower::drawGrass() {
	const int SIZE = 800;
	RectangleShape* grass = new RectangleShape[SIZE];
	float width = 1.f;
	float x = 0.f;

	for (int i = 0; i < SIZE; i++)
		grass[i].setFillColor(Color(0, 255, 0));

	for (int i = 0; i < SIZE; i++) {
		int remainder = i % 6;

		switch (remainder) {
		case 0:
			if (x <= SIZE) {
				grass[i].setPosition(x, 300.f);
				grass[i].setSize(Vector2f(width, 300.f));
			}
			break;
		case 1:
			if (x <= SIZE) {
				grass[i].setPosition(x, 320.f);
				grass[i].setSize(Vector2f(width, 280.f));
			}
			break;
		case 2:
			if (x <= SIZE) {
				grass[i].setPosition(x, 360.f);
				grass[i].setSize(Vector2f(width, 240.f));
			}
			break;
		case 3:
			if (x <= SIZE) {
				grass[i].setPosition(x, 400.f);
				grass[i].setSize(Vector2f(width, 200.f));
			}
			break;
		case 4:
			if (x <= SIZE) {
				grass[i].setPosition(x, 360.f);
				grass[i].setSize(Vector2f(width, 240.f));
			}
			break;
		case 5:
			if (x <= SIZE) {
				grass[i].setPosition(x, 320.f);
				grass[i].setSize(Vector2f(width, 280.f));
			}
			break;
		}
		x += 2.f;
		window->draw(grass[i]);
	}

	delete[] grass;
}

float positionX = 200.f;
bool ignoreIf = false;
void Flower::drawCloud() {
	CircleShape cloud(30.f);
	Vector2f position(positionX, 30.f);
	cloud.setPosition(position);
	cloud.setFillColor(Color::White);
	cloud.setScale(2, 1);
	window->draw(cloud);

	if (positionX <= 680.f && !ignoreIf)
		positionX += 0.5;

	if (ignoreIf) {
		positionX -= 0.5;
	}

	if (positionX > 680.f) {
		ignoreIf = true;
	}

	if (positionX < 200.f) {
		ignoreIf = false;
	}
}

void Flower::drawFlower() {
	RectangleShape line;

	Vector2f size(3.f, 200.f);
	Vector2f position(400.f, 250.f);
	line.setSize(size);
	line.setPosition(position);
	line.setFillColor(Color::Green);

	window->draw(line);

	CircleShape flower(30.f);
	Vector2f positionfl(372.f, 200.f);
	flower.setFillColor(Color::Magenta);
	flower.setPosition(positionfl);
	window->draw(flower);

	CircleShape petal01(10.f);
	Vector2f positionpet01(391.f, 150.f);
	petal01.setFillColor(Color::Magenta);
	petal01.setPosition(positionpet01);
	petal01.setScale(1, 2);
	window->draw(petal01);

	CircleShape petal02(10.f);
	Vector2f positionpet02(328.f, 206.f);
	petal02.setFillColor(Color::Magenta);
	petal02.setPosition(positionpet02);
	petal02.setScale(1, 2);
	petal02.setRotation(-72);
	window->draw(petal02);

	CircleShape petal03(10.f);
	Vector2f positionpet03(472.f, 188.f);
	petal03.setFillColor(Color::Magenta);
	petal03.setPosition(positionpet03);
	petal03.setScale(1, 2);
	petal03.setRotation(72);
	window->draw(petal03);

	CircleShape petal04(10.f);
	Vector2f positionpet04(359.f, 296.f);
	petal04.setFillColor(Color::Magenta);
	petal04.setPosition(positionpet04);
	petal04.setScale(1, 2);
	petal04.setRotation(-144);
	window->draw(petal04);

	CircleShape petal05(10.f);
	Vector2f positionpet05(460.f, 285.f);
	petal05.setFillColor(Color::Magenta);
	petal05.setPosition(positionpet05);
	petal05.setScale(1, 2);
	petal05.setRotation(144);
	window->draw(petal05);
}