#include "Cvijet.h"



Cvijet::Cvijet(RenderWindow* w)
{
	this->w = w;
}

void Cvijet::draw()
{
	CircleShape c1; c1.setFillColor(Color::Red); c1.setRadius(30); c1.setPosition(200, 200); c1.setOrigin(30,30);
	CircleShape c2; c2.setFillColor(Color::Yellow); c2.setRadius(10); c2.setPosition(200, 200); c2.setOrigin(10, 10);
	RectangleShape rec;

	rec.setSize(Vector2f(10, 200));
	rec.setFillColor(Color::Green);
	rec.setPosition(c1.getPosition().x - 5, c1.getPosition().y);

	float moveX = 3;

	for (int i = 0; i < 30; i++)
	{
		w->clear();
		c1.setPosition(c1.getPosition().x - moveX, 200);
		c2.setPosition(c2.getPosition().x - moveX, 200);
		rec.setPosition(rec.getPosition().x - moveX, 200);
		w->draw(rec);
		w->draw(c1);
		w->draw(c2);
		w->display();
	}
	for (int i = 0; i < 30; i++)
	{
		w->clear();
		c1.setPosition(c1.getPosition().x + moveX, 200);
		c2.setPosition(c2.getPosition().x + moveX, 200);
		rec.setPosition(rec.getPosition().x + moveX, 200);
		w->draw(rec);
		w->draw(c1);
		w->draw(c2);
		w->display();
	}
}