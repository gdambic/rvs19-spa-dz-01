#include "Cvijet.h"



Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->windows = window;
}


void Cvijet::draw()
{

	//float i = -200;

	sf::RectangleShape land(sf::Vector2f(800.f, 100.f));
	land.setFillColor(sf::Color(65, 232, 22));
	land.setPosition(0, 500);

	sf::RectangleShape nebo(sf::Vector2f(800.f, 500.f));
	nebo.setFillColor(sf::Color(40, 174, 255));
	nebo.setPosition(0, 0);

	sf::RectangleShape stabljika(sf::Vector2f(200.f, 10.f));
	stabljika.setFillColor(sf::Color(0, 255, 12));
	stabljika.rotate(80.f);
	stabljika.setPosition(400, 310);

	sf::CircleShape l1(25.f);
	l1.setFillColor(sf::Color(177, 60, 255));
	l1.setPosition(400, 310);

	sf::CircleShape l2(25.f);
	l2.setFillColor(sf::Color(177, 60, 255));
	l2.setPosition(360, 310);

	sf::CircleShape l3(25.f);
	l3.setFillColor(sf::Color(177, 60, 255));
	l3.setPosition(400, 270);

	sf::CircleShape l4(25.f);
	l4.setFillColor(sf::Color(177, 60, 255));
	l4.setPosition(350, 275);

	sf::CircleShape l5(25.f);
	l5.setFillColor(sf::Color(177, 60, 255));
	l5.setPosition(375, 255);

	sf::ConvexShape list(6);
	list.setFillColor(sf::Color(0, 255, 12));

	sf::CircleShape sredina(30.f);
	sredina.setPosition(370, 280);
	sredina.setFillColor(sf::Color(255, 251, 66));

	sf::ConvexShape latica1;
	latica1.setPointCount(5);
	latica1.setPoint(0, sf::Vector2f(0.f, 0.f));
	latica1.setPoint(1, sf::Vector2f(150.f, 10.f));
	latica1.setPoint(2, sf::Vector2f(120.f, 90.f));
	latica1.setPoint(3, sf::Vector2f(30.f, 100.f));
	latica1.setPoint(4, sf::Vector2f(0.f, 50.f));
	latica1.scale(0.5, 0.5);
	latica1.setPosition(380, 370);
	latica1.setFillColor(sf::Color(0, 255, 12));



	windows->draw(land);
	windows->draw(nebo);
	windows->draw(stabljika);
	windows->draw(l1);
	windows->draw(l2);
	windows->draw(l3);
	windows->draw(l4);
	windows->draw(l5);
	windows->draw(sredina);
	windows->draw(latica1);


	sf::CircleShape oblak(50.f);
	oblak.setFillColor(sf::Color(114, 115, 117));
	oblak.setPosition(100, 100);
	sf::CircleShape oblak1(50.f);
	oblak1.setFillColor(sf::Color(114, 115, 117));
	oblak1.setPosition(150, 100);
	sf::CircleShape oblak2(50.f);
	oblak2.setFillColor(sf::Color(114, 115, 117));
	oblak2.setPosition(200, 100);

	

	sf::Time elapsed = clock.restart();
	vrijeme = vrijeme + elapsed;
	if (vrijeme < vrijeme2) {
		oblak.setScale(1.2, 1.2);
		oblak1.setScale(1.2, 1.2);
		oblak2.setScale(1.2, 1.2);
	}
	if (vrijeme > vrijeme2) {
		oblak.setScale(1, 1);
		oblak1.setScale(1, 1);
		oblak2.setScale(1, 1);

	}
	if (vrijeme > vrijeme3) {

		vrijeme = vrijemekraja;
	}
	windows->draw(oblak);
	windows->draw(oblak1);
	windows->draw(oblak2);


	
}



