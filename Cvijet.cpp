#include "Cvijet.h"
using namespace sf;




Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	sf::RectangleShape pozadina(sf::Vector2f(800, 600));
	pozadina.setFillColor(sf::Color(173,216, 230));
	pozadina.setPosition(0, 0);

	sf::RectangleShape trava(sf::Vector2f(800, 25));
	trava.setFillColor(sf::Color(0, 255, 0));
	trava.setPosition(0, 550);

	sf::RectangleShape zemlja(sf::Vector2f(800, 25));
	zemlja.setFillColor(sf::Color(97, 51, 24));
	zemlja.setPosition(0, 575);

	sf::RectangleShape stabljika(sf::Vector2f(150.f, 12.f));
	stabljika.setFillColor(sf::Color(1, 110, 20));
	stabljika.setPosition(400, 400);
	stabljika.rotate(90.f);
	
	sf::CircleShape tucak(40.f, 9);
	tucak.setFillColor(sf::Color(255,194,0));
	tucak.setPosition(355, 350);

	sf::CircleShape latica1(30.f);
	latica1.setPosition(365, 320);
	latica1.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica2(30.f);
	latica2.setPosition(390, 330);
	latica2.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica3(30.f);
	latica3.setPosition(405, 350);
	latica3.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica4(30.f);
	latica4.setPosition(400, 380);
	latica4.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica5(30.f);
	latica5.setPosition(385, 395);
	latica5.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica6(30.f);
	latica6.setPosition(350, 395);
	latica6.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica7(30.f);
	latica7.setPosition(335, 380);
	latica7.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica8(30.f);
	latica8.setPosition(330, 355);
	latica8.setFillColor(sf::Color(75, 0, 130));

	sf::CircleShape latica9(30.f);
	latica9.setPosition(335, 335);
	latica9.setFillColor(sf::Color(75, 0, 130));

	sf::ConvexShape list;
	list.setPointCount(13);

	list.setPoint(0, sf::Vector2f(0.f, 0.f));
	list.setPoint(1, sf::Vector2f(-15.f, 15.f));
	list.setPoint(2, sf::Vector2f(-6.f, 15.f));
	list.setPoint(3, sf::Vector2f(-25.f, 30.f));
	list.setPoint(4, sf::Vector2f(-14.f, 30.f));
	list.setPoint(5, sf::Vector2f(-28.f, 45.f));
	list.setPoint(6, sf::Vector2f(0.f, 60.f));
	list.setPoint(7, sf::Vector2f(28.f, 45.f));
	list.setPoint(8, sf::Vector2f(14.f, 30.f));
	list.setPoint(9, sf::Vector2f(25.f, 30.f));
	list.setPoint(10, sf::Vector2f(6.f, 15.f));
	list.setPoint(11, sf::Vector2f(15.f, 15.f));
	list.setPoint(12, sf::Vector2f(0.f, 0.f));
	list.setPosition(400, 520);
	list.setFillColor(sf::Color(0, 128, 0));
	list.rotate(127.f);

	sf::ConvexShape list2;
	list2.setPointCount(13);

	list2.setPoint(0, sf::Vector2f(0.f, 0.f));
	list2.setPoint(1, sf::Vector2f(-15.f, 15.f));
	list2.setPoint(2, sf::Vector2f(-6.f, 15.f));
	list2.setPoint(3, sf::Vector2f(-25.f, 30.f));
	list2.setPoint(4, sf::Vector2f(-14.f, 30.f));
	list2.setPoint(5, sf::Vector2f(-28.f, 45.f));
	list2.setPoint(6, sf::Vector2f(0.f, 60.f));
	list2.setPoint(7, sf::Vector2f(28.f, 45.f));
	list2.setPoint(8, sf::Vector2f(14.f, 30.f));
	list2.setPoint(9, sf::Vector2f(25.f, 30.f));
	list2.setPoint(10, sf::Vector2f(6.f, 15.f));
	list2.setPoint(11, sf::Vector2f(15.f, 15.f));
	list2.setPoint(12, sf::Vector2f(0.f, 0.f));
	list2.setPosition(390, 510);
	list2.setFillColor(sf::Color(0, 128, 0));
	list2.rotate(250.f);

	sf::ConvexShape sunce;
	sunce.setPointCount(40);
	sunce.setFillColor(sf::Color(255,255,0));

	float vanjskiR = 100.0f;
	float unutarnjiR = 50.0f;
	float yPos = 100.0f;

	float rast_kut = 360.0f / 20;
	float trenutni_kut = 0.0f;

		static float xPos = -100.0f; 
		xPos += 3.0f;

		for (int i = 0; i < 20; ++i) {
		
			float kut = trenutni_kut + i * rast_kut;
			float vanjskiX = xPos + vanjskiR * cos(kut * 3.14159f / 180);
			float vanjskiY = yPos + vanjskiR * sin(kut * 3.14159f / 180);
			float unutarnjiX = xPos + unutarnjiR * cos((kut + rast_kut) * 3.14159f / 180);
			float unutarnjiY = yPos + unutarnjiR * sin((kut + rast_kut) * 3.14159f / 180);

			sunce.setPoint(i * 2, sf::Vector2f(vanjskiX, vanjskiY));
			sunce.setPoint(i * 2 + 1, sf::Vector2f(unutarnjiX, unutarnjiY));
		}
	
	

	

	window->draw(pozadina);
	window->draw(zemlja);
	window->draw(trava);
	window->draw(stabljika);
	window->draw(latica1);
	window->draw(latica2);
	window->draw(latica3);
	window->draw(latica4);
	window->draw(latica5);
	window->draw(latica6);
	window->draw(latica7);
	window->draw(latica8);
	window->draw(latica9);
	window->draw(list);
	window->draw(list2);
	window->draw(tucak);
	window->draw(sunce);
}


