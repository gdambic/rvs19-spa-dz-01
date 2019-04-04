#include "Cvijet.h"
#include <SFML/Graphics.hpp>




using namespace sf;

Cvijet::Cvijet(sf::RenderWindow * window)
{
this->window = window;
}



void Cvijet::draw() 
{	float a = 80, b = 280, c = 0;

	CircleShape cvijet(30.f);
	cvijet.setFillColor(Color(255,255,0));
	cvijet.setOutlineThickness(30.f);
	
	

	/*stapka*/
	RectangleShape stapka(Vector2f(2.f, 100.f));
	stapka.setFillColor(Color(0, 255, 9));
	
	/*nebo*/
	RectangleShape nebo(Vector2f(800, 100));
	nebo.setFillColor(Color(0 , 128, 255));
		window->draw(nebo);
	
	

	/*sunce*/
	CircleShape sunce(50);
	
	sunce.setPosition(20.f, 20.f);

	sunce.setFillColor(Color(255, 255, 0));
	
	window->draw(sunce);

	
	RectangleShape zraka(Vector2f(5.f, 90.f));
	zraka.setFillColor(Color(255, 255, 0));
	zraka.setPosition(70,70);
	
	for (int i = 0; i < 15; i++)
	{
		window->draw(zraka);
		zraka.rotate(30);
	}
	
	



	/*latice*/
	
	ConvexShape latica;
	latica.setPointCount(4);
	latica.setFillColor(Color(0, 255, 9));
	

	/*trava*/

	RectangleShape trava(Vector2f(2.f, 170.f));
	trava.setPosition(0, 460);
	for (int i = 0; i < 400; i++)
	{
	
		if (i%2==0)
		{
			trava.setFillColor(Color(0, 255, 9));	
			
		}
		else 
		{
			trava.setFillColor(Color(26, 127, 29));
			

		}
		int t = frameClock.getElapsedTime().asMilliseconds() / 200;

		if (t < 20) {
			trava.setPosition(c, 450- t);
		}
		else {
			sunce.setPosition(c, 430);
			frameClock.restart();
		}
	
		
		window->draw(trava);
		c += 2;
		
		
	}



	for (int i = 0; i < 4; i++)
	{
		cvijet.setPosition(a, b);

		stapka.setPosition(a+30, b+90);
		if (i % 2 == 0)
		{
			srand(time(0));
			cvijet.setOutlineColor(sf::Color(rand()+15 % 255, rand()+10 % 255, rand()+10 % 255));

		}

		else
		{
			srand(time(0));
			cvijet.setOutlineColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			
		}
		

		latica.setPoint(0, sf::Vector2f(a + 30, 410.f));
		latica.setPoint(1, sf::Vector2f(a + 50, 385.f));
		latica.setPoint(2, sf::Vector2f(a + 100, 380.f));
		latica.setPoint(3, sf::Vector2f(a + 60, 415.f));

		window->draw(cvijet);
		window->draw(stapka);
		window->draw(latica);
		
		
		a += 200;
		
	}

	
		
}

