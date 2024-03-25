#include "Cvijet.h"
using namespace sf;

void Cvijet::cvijet()
{
	sf::ConvexShape cvijet;
	cvijet.setFillColor(sf::Color(201, 12, 14));
	cvijet.setPointCount(3);
	cvijet.setPoint(0, Vector2f(30.f, 14.f));
	cvijet.setPoint(1, Vector2f(119.f, 14.f));
	cvijet.setPoint(2, Vector2f(75.f, 25.f));
	window->draw(cvijet);

	sf::ConvexShape cvijet1;
	cvijet1.setFillColor(sf::Color(82, 6, 7));
	cvijet1.setPointCount(6);
	cvijet1.setPoint(0, Vector2f(10.f, 10.f));
	cvijet1.setPoint(1, Vector2f(70.f, 23.f));
	cvijet1.setPoint(2, Vector2f(120.f, 10.f));
	cvijet1.setPoint(3, Vector2f(110.f, 50.f));
	cvijet1.setPoint(4, Vector2f(60.f, 80.f));
	cvijet1.setPoint(5, Vector2f(20.f, 50.f));
	window->draw(cvijet1);

	sf::ConvexShape cvijet2;
	cvijet2.setFillColor(sf::Color(201, 12, 14));
	cvijet2.setPointCount(6);
	cvijet2.setPoint(0, Vector2f(5.f, 15.f));
	cvijet2.setPoint(1, Vector2f(70.f, 28.f));
	cvijet2.setPoint(2, Vector2f(125.f, 15.f));
	cvijet2.setPoint(3, Vector2f(115.f, 55.f));
	cvijet2.setPoint(4, Vector2f(65.f, 85.f));
	cvijet2.setPoint(5, Vector2f(15.f, 55.f));
	window->draw(cvijet2);

	sf::ConvexShape latica;
	latica.setFillColor(sf::Color(128, 6, 6));
	latica.setPointCount(5);
	latica.setPoint(0, Vector2f(5.f, 25.f));
	latica.setPoint(1, Vector2f(70.f, 38.f));
	latica.setPoint(2, Vector2f(75.f, 55.f));
	latica.setPoint(3, Vector2f(65.f, 90.f));
	latica.setPoint(4, Vector2f(15.f, 55.f));
	window->draw(latica);

}
void Cvijet::stabljika()
{
	sf::ConvexShape stabljika;
	stabljika.setFillColor(sf::Color(43, 89, 28));
	stabljika.setPointCount(6);
	stabljika.setPoint(0, Vector2f(50.f, 75.f));
	stabljika.setPoint(1, Vector2f(80.f, 75.f));
	stabljika.setPoint(2, Vector2f(75.f, 175.f));
	stabljika.setPoint(3, Vector2f(79.f, 230.f));
	stabljika.setPoint(4, Vector2f(65.f, 175.f));
	stabljika.setPoint(5, Vector2f(60.f, 85.f));
	window->draw(stabljika);
}
void Cvijet::trn()
{
	sf::ConvexShape trn;
	trn.setFillColor(sf::Color(27, 46, 21));
	trn.setPointCount(3);
	trn.setPoint(0, Vector2f(75.f, 100.f));
	trn.setPoint(1, Vector2f(90.f, 95.f));
	trn.setPoint(2, Vector2f(75.f, 110.f));
	window->draw(trn);

	sf::ConvexShape trn1;
	trn1.setFillColor(sf::Color(27, 46, 21));
	trn1.setPointCount(3);
	trn1.setPoint(0, Vector2f(75.f, 150.f));
	trn1.setPoint(1, Vector2f(90.f, 135.f));
	trn1.setPoint(2, Vector2f(75.f, 160.f));
	window->draw(trn1);

	sf::ConvexShape trn2;
	trn2.setFillColor(sf::Color(27, 46, 21));
	trn2.setPointCount(3);
	trn2.setPoint(0, Vector2f(55.f, 120.f));
	trn2.setPoint(1, Vector2f(40.f, 135.f));
	trn2.setPoint(2, Vector2f(65.f, 130.f));
	window->draw(trn2);
}
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}
void Cvijet::draw()
{
	trn();
	stabljika();
	cvijet();
}
