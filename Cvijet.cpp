#include <SFML/Graphics.hpp>
#include "Cvijet.h"
using namespace sf;


using namespace sf;

Cvijet::Cvijet(RenderWindow* w)
{
	this->window = w;
}

void Cvijet::make_frame()
{
	RectangleShape lineL(Vector2f(400.f, 5.f));
	lineL.setPosition(20, 5);
	lineL.rotate(90);
	window->draw(lineL);

	RectangleShape lineR(Vector2f(400.f, 5.f));
	lineR.setPosition(400, 5);
	lineR.rotate(90);
	window->draw(lineR);

	RectangleShape lineUp(Vector2f(380.f, 5.f));
	lineUp.setPosition(20, 5);
	lineUp.rotate(0);
	window->draw(lineUp);

	RectangleShape lineDo(Vector2f(380.f, 5.f));
	lineDo.setPosition(20, 400);
	lineDo.rotate(0);
	window->draw(lineDo);
}



void Cvijet::make_stem()
{
	RectangleShape stem(Vector2f(150.f, 5.f));
	stem.setPosition(152, 215);
	stem.rotate(90);
	stem.setFillColor(Color(0, 255, 0));
	window->draw(stem);

}

void Cvijet::make_leaf()
{
	ConvexShape leaf;
	leaf.setPointCount(4);
	leaf.setPoint(0, Vector2f(150.f, 300.f));
	leaf.setPoint(1, Vector2f(200.f, 260.f));
	leaf.setPoint(2, Vector2f(350.f, 230.f));
	leaf.setPoint(3, Vector2f(210.f, 305.f));
	leaf.setFillColor(Color(0, 255, 0));
	window->draw(leaf);
}


void Cvijet::make_flower()
{
	CircleShape flower(50.f);
	flower.setPosition(100, 130);
	flower.setOutlineThickness(20.f);
	flower.setOutlineColor(Color(100, 50, 0));
	flower.setFillColor(Color(155, 155, 0));
	window->draw(flower);


}


void Cvijet::draw()
{
	make_frame();
	make_stem();
	make_leaf();
	make_flower();

}