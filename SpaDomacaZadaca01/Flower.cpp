#include "Flower.h"

Flower::Flower(RenderWindow* rw) {
	m_rw = rw;

	circle = CircleShape(100);
	circle.setOutlineThickness(30);
	circle.setFillColor(Color(0, 255, 0));
	circle.setOutlineColor(Color(250, 150, 100));
	circle.setPosition(100, 30);

	tube = RectangleShape(Vector2f(30, 300));
	tube.setPosition(185, 200);
	tube.setFillColor(Color(80, 200, 100));

	sun = CircleShape(20);
	sun.setFillColor(Color(255, 255, 0));
}

void Flower::draw() {
	sun.setPosition(sun_x, 0);
	sun_x += 4;
	sun_x %= m_rw->getSize().x;
	m_rw->draw(sun);

	m_rw->draw(tube);
	m_rw->draw(circle);

}