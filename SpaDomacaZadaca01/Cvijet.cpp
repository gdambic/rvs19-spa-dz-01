#include "Cvijet.h"
#include "ctime"
#include "cmath"

Cvijet::Cvijet(sf::RenderWindow* window) : MyWindow(window) {
	this->MyWindow = window;
}

void Cvijet::draw(){

	srand(time(nullptr));
	Clock clock;
	double dt;
	dt = clock.restart().asMicroseconds()+(rand()%18);

	Texture background;
	background.loadFromFile("Background.jpg");
	Sprite s(background);
	Sprite sprite;
	Vector2u size = background.getSize();
	sprite.setTexture(background);
	sprite.setOrigin(0, 0);

	RectangleShape ground(Vector2f(800, 120));
	ground.setFillColor(Color::Green);
	ground.setPosition(0, 480);

	CircleShape shadow(22.f);
	shadow.setScale(3, 1.5);
	shadow.setPosition(168, 505);
	shadow.setOutlineThickness(5);
	shadow.setOutlineColor(Color(75, 150, 75,190));
	shadow.setFillColor(Color(75,150,75,255));

	CircleShape wind_leaf(18.f);
	wind_leaf.setScale(3.8, 1);
	wind_leaf.setRotation(dt-40);
	wind_leaf.setPosition(255, 300);
	wind_leaf.setFillColor(Color(45, 172, 62));
	wind_leaf.setOutlineThickness(5);
	wind_leaf.setOutlineColor(Color(45, 190, 0));

	CircleShape shadow_leaf (18.f);
	shadow_leaf.setScale(3+(dt / 15), 0.8+ (dt / 25));
	shadow_leaf.setPosition(276,500);
	shadow.setOutlineThickness(5);
	shadow_leaf.setOutlineColor(Color(75, 150, 75, 50 + dt * 6));
	shadow_leaf.setFillColor(Color(75, 150, 75, 50 + dt * 6));

	RectangleShape stalk_front(Vector2f(10, 400));
	stalk_front.setFillColor(Color(45, 172, 62));
	stalk_front.setPosition(245, 150);

	RectangleShape stalk_behind(Vector2f(22, 400));
	stalk_behind.setFillColor(Color(90, 186, 41));
	stalk_behind.setPosition(240, 150);

	CircleShape pistil_behind(65.f);
	pistil_behind.setPosition(185, 110);
	pistil_behind.setFillColor(Color(195, 32, 83, 255));

	CircleShape pistil_outside(50.f);
	pistil_outside.setPosition(200, 125);
	pistil_outside.setFillColor(Color(255,171,0,255));

	CircleShape pistil_inside(42.f);
	pistil_inside.setPosition(208, 133);
	pistil_inside.setFillColor(Color(255, 255, 0, 255));

	CircleShape petal_n1(90, 3);
	petal_n1.setPosition(160, 86);
	petal_n1.setFillColor(Color(255, 0, 77, 255));

	CircleShape petal_n2(90, 3);
	petal_n2.setRotation(180.f);
	petal_n2.setPosition(340, 264);
	petal_n2.setFillColor(Color(255, 0, 77, 255));

	MyWindow->draw(sprite);
	MyWindow->draw(ground);
	MyWindow->draw(shadow);
	MyWindow->draw(shadow_leaf);
	MyWindow->draw(wind_leaf);
	MyWindow->draw(stalk_behind);
	MyWindow->draw(stalk_front);
	MyWindow->draw(pistil_behind);
	MyWindow->draw(petal_n1);
	MyWindow->draw(petal_n2);
	MyWindow->draw(pistil_outside);
	MyWindow->draw(pistil_inside);

}