#include "Cvijet.h"


Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

sf::RenderWindow* Cvijet::get_window()
{
	return window;
}


void Cvijet::draw()
{
	sf::RenderWindow* win = get_window();

	//Crtanje Latica
	sf::CircleShape krug(75);
	krug.setPosition(75, 75);
	krug.setFillColor(sf::Color(255, 255, 51));
	krug.setOutlineThickness(40);
	krug.setOutlineColor(sf::Color(255, 69, 0));

	win->draw(krug);

	//Crtanje Sunca
	sf::CircleShape sunce(20);
	sunce.setPosition(20, 20);
	sunce.setFillColor(krug.getFillColor());

	win->draw(sunce);

	//Crtanje Steljke(stabljike?)
	sf::RectangleShape steljka(sf::Vector2f(5, 300));
	steljka.setFillColor(sf::Color(50, 205, 50));
	steljka.setPosition(krug.getPosition().x + (krug.getRadius() / 2) + krug.getOutlineThickness(), 265);

	win->draw(steljka);

	//Crtanje Lista.
	sf::ConvexShape list;
	list.setPointCount(4);
	list.setPoint(0, sf::Vector2f(steljka.getPosition().x, 397.5));
	list.setPoint(1, sf::Vector2f(350, 375));
	list.setPoint(2, sf::Vector2f(500, 300));
	list.setPoint(3, sf::Vector2f(275, 325));
	list.setFillColor(steljka.getFillColor());

	win->draw(list);
}






