#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* Window)
{
	this->Window = Window;

}

sf::CircleShape Cvijet::set_Sunce()
{
	Sunce.setRadius(50);
	Sunce.setFillColor(sf::Color(250, 250, 0));
	Sunce.setPosition(50, 50);
	return Sunce;
}

sf::CircleShape Cvijet::set_UnutarnjiCvijet()
{
	UnutarnjiCvijet.setRadius(50);
	UnutarnjiCvijet.setPosition(160, 230);
	UnutarnjiCvijet.setFillColor(sf::Color(255, 255, 225));
	return UnutarnjiCvijet;
}

sf::CircleShape Cvijet::set_VanjskiCvijet()
{
	VanjskiCvijet.setRadius(80);
	VanjskiCvijet.setPosition(130, 200);
	VanjskiCvijet.setFillColor(sf::Color(0, 0, 255));
	return VanjskiCvijet;
}

sf::RectangleShape Cvijet::set_Stabljika()
{
	sf::Vector2f velicina(30, 180);
	Stabljika.setSize(velicina);
	Stabljika.setPosition(195, 355);
	Stabljika.setFillColor(sf::Color(100, 250, 10));
	return Stabljika;
}

sf::ConvexShape Cvijet::set_List()
{
	List.setPointCount(3);
	List.setPosition(200, 400);
	List.setFillColor(sf::Color(0, 250, 0));
	List.setPoint(0, sf::Vector2f(100, 50));
	List.setPoint(1, sf::Vector2f(20, -30));
	return List;
}

void Cvijet::animateSunce()
{
	protekloVrijeme = vrijeme.getElapsedTime();
	Sunce.move(0, 100 * protekloVrijeme.asSeconds());
	vrijeme.restart();
}

void Cvijet::draw()
{
	Window->draw(set_List());
	Window->draw(set_Stabljika());
	Window->draw(set_VanjskiCvijet());
	Window->draw(set_UnutarnjiCvijet());
	Window->draw(Sunce);
	animateSunce(); 
	 
}
