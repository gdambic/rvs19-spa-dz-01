#include "Cvijet.h"
static const float pi = 3.141592654f;

Cvijet::Cvijet(RenderWindow& window) //crtanje cvijeta
{
	glava.setRadius(90);
	glava.setFillColor(Color(255, 255, 50));  
	glava.setPosition(250, 140);

	okoL.setRadius(30);
	okoL.setFillColor(Color(255, 255, 255));
	okoL.setPosition(280,180);
	okoL.setOutlineColor(Color(0, 0, 0));
	okoLU.setRadius(15);
	okoLU.setFillColor(Color(139, 69, 19));
	okoLU.setPosition(300, 210);

	okoR.setRadius(30);
	okoR.setFillColor(Color(255, 255, 255));
	okoR.setPosition(350, 180);
	okoR.setOutlineColor(Color(0, 0, 0));
	okoRU.setRadius(15);
	okoRU.setFillColor(Color(139, 69, 19));
	okoRU.setPosition(370, 210);

	usta.setSize(Vector2f(80, 7));
	usta.setFillColor(Color(0,0,0));
	usta.setPosition(300, 270);
	
	stabiljka.setSize(Vector2f(180, 13));
	stabiljka.setFillColor(Color(0, 255, 0));
	stabiljka.setPosition(340, 270);
	stabiljka.rotate(90);

	list.setPointCount(11);
	list.setPoint(0, Vector2f(330, 420));
	list.setPoint(1, Vector2f(340, 410));
	list.setPoint(2, Vector2f(350, 400));
	list.setPoint(3, Vector2f(360, 390));
	list.setPoint(4, Vector2f(370, 380));
	list.setPoint(5, Vector2f(380, 370));
	list.setPoint(6, Vector2f(390, 350));
	list.setPoint(7, Vector2f(400, 340));
	list.setPoint(8, Vector2f(380, 340));
	list.setPoint(9, Vector2f(370, 350));
	list.setPoint(10, Vector2f(360, 360));
	list.setFillColor(Color(0, 255, 0));

	okoLA.setRadius(30);
	okoLA.setFillColor(Color(0, 0, 0));
	okoLA.setPosition(280, 180);
}

void Cvijet::draw(RenderWindow& window)
{
	window.draw(stabiljka);
	window.draw(glava);
	window.draw(okoL);
	window.draw(okoLU);
	window.draw(okoR);
	window.draw(okoRU);
	window.draw(usta);
	window.draw(list);
	

	
}

void Cvijet::anim(Clock& clock, RenderWindow& window)
{
	auto vrijeme_sekunde = clock.getElapsedTime().asSeconds();
	if (clock.getElapsedTime().asSeconds() >= 1) {
		window.draw(okoLA);
	}
	if (clock.getElapsedTime().asSeconds() >= 5) {
		window.draw(okoL);
		window.draw(okoLU);
	}
	clock.restart();
}
