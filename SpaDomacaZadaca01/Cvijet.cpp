#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cvijet.h"

using namespace std;


Cvijet::Cvijet(RenderWindow* adresa)
{
	this->adresa = adresa;
}

void Cvijet::drawNebo()
{
	RectangleShape nebo(sf::Vector2f(1200.f, 720.f));
	nebo.setFillColor(sf::Color(10, 143, 245));
	adresa->draw(nebo);
}

void Cvijet::drawSunce(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB)
{
	CircleShape sunce(radius);
	sunce.setPosition(position1, position2);
	sunce.setFillColor(Color(fillR, fillG, fillB));
	sunce.setOutlineThickness(outline);
	sunce.setOutlineColor(Color(outR, outG, outB));

	Time elapsed2 = clock.getElapsedTime();

	if (clock.getElapsedTime().asMilliseconds() > 2000)
	{
		sunce.setRadius(radius - 10.f * ((clock.getElapsedTime().asMilliseconds() - 2000) / 2000.f));
		if (clock.getElapsedTime().asMilliseconds() >= 4000)
		{
			clock.restart();
		}
	}
	else
	{
		sunce.setRadius(radius -10.f + 10.f * (clock.getElapsedTime().asMilliseconds() / 2000.f));
	}
	adresa->draw(sunce);


	
}


void Cvijet::drawCvijet(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB)
{
	CircleShape mainFlower (radius);
	mainFlower.setPosition(position1, position2);
	mainFlower.setFillColor(Color(fillR, fillG, fillB));
	mainFlower.setOutlineThickness(outline);
	mainFlower.setOutlineColor(Color(outR, outG, outB));
	
	Time elapsed2 = clock.getElapsedTime();

	if (clock.getElapsedTime().asMilliseconds() > 3000)
	{
		mainFlower.setRadius(radius - 5.f * ((clock.getElapsedTime().asMilliseconds() - 1500) / 1500.f));
		/*if (clock.getElapsedTime().asMilliseconds() >= 3000)
		{
			clock.restart();
		}*/
	}
	else
	{
		mainFlower.setRadius(radius + 5.f * (clock.getElapsedTime().asMilliseconds() / 1500.f));
	}
	adresa->draw(mainFlower);

}

void Cvijet::drawOblak()
{
	  
		CircleShape oblak(45.f);
	
		oblak.setPosition(140.f, 30.f);
		oblak.setFillColor(Color(255, 255, 255));

		CircleShape oblak1(50.f);
	
		oblak1.setPosition(160.f, 30.f);
		oblak1.setFillColor(Color(255, 255, 255));

		CircleShape oblak2(43.f);
	
		oblak2.setPosition(190.f, 30.f);
		oblak2.setFillColor(Color(255, 255, 255));

		Time elapsed2 = clock.getElapsedTime();

		if (clock.getElapsedTime().asMilliseconds() > 6000)
		{
			oblak.setPosition(140.f -250.f * ((clock.getElapsedTime().asMilliseconds() - 1000) / 1000.f), 30.f);
			oblak1.setPosition(180.f - 250.f * ((clock.getElapsedTime().asMilliseconds() - 1000) / 1000.f), 30.f);
			oblak2.setPosition(220.f - 250.f * ((clock.getElapsedTime().asMilliseconds() - 1000) / 1000.f), 30.f);
			if (clock.getElapsedTime().asMilliseconds() >= 50000000)
			{
				clock.restart();
			}
		}
		else
		{
			oblak.setPosition(140.f +250.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);
			oblak1.setPosition(180.f + 250.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);
			oblak2.setPosition(220.f + 250.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);

		}
		adresa->draw(oblak);
		adresa->draw(oblak1);
		adresa->draw(oblak2);
}



void Cvijet::drawLivada()
{
	ConvexShape livada(4);
	livada.setPoint(0, Vector2f(0.f, 400.f));
	livada.setPoint(1, Vector2f(1200.f, 400.f));
	livada.setPoint(2, Vector2f(1200.f, 720.f));
	livada.setPoint(3, Vector2f(0.f, 720.f));
	livada.setFillColor(Color(0, 153, 2));
	adresa->draw(livada);

	/*sf::RectangleShape line(sf::Vector2f(5.f, 400.f));
	line.setPosition(0.f, 420.f);

	
	line.setFillColor(sf::Color(0, 153, 76));
	adresa->draw(line);*/


}

void Cvijet::draw()
{
	
	drawNebo();
	drawSunce(80.f, 1050.f, -20.f, 255, 255, 0,  10.f, 255, 255, 153);
	drawLivada();
	drawOblak();


	sf::ConvexShape stabljika(8);
	stabljika.setPoint(0, sf::Vector2f(420.f, 360.f));
	stabljika.setPoint(1, sf::Vector2f(440.f, 360.f));
	stabljika.setPoint(2, sf::Vector2f(440.f, 370.f));
	stabljika.setPoint(3, sf::Vector2f(435.f, 420.f));
	stabljika.setPoint(4, sf::Vector2f(440.f, 470.f));
	stabljika.setPoint(5, sf::Vector2f(420.f, 470.f));
	stabljika.setPoint(6, sf::Vector2f(415.f, 420.f));
	stabljika.setPoint(7, sf::Vector2f(420.f, 370.f));
	stabljika.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(stabljika);

	//LISTOVI
	sf::ConvexShape d_list(4);
	d_list.setPoint(0, sf::Vector2f(430.f, 390.f));
	d_list.setPoint(1, sf::Vector2f(455.f, 410.f));
	d_list.setPoint(2, sf::Vector2f(495.f, 360.f));
	d_list.setPoint(3, sf::Vector2f(465.f, 425.f));
	d_list.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(d_list);

	sf::ConvexShape l_list(4);
	l_list.setPoint(0, sf::Vector2f(360.f, 360.f));
	l_list.setPoint(1, sf::Vector2f(400.f, 410.f));
	l_list.setPoint(2, sf::Vector2f(425.f, 390.f));
	l_list.setPoint(3, sf::Vector2f(390.f, 425.f));
	l_list.setFillColor(sf::Color(0, 209, 3));
	adresa->draw(l_list);


	//Cvijet1
	drawCvijet(20.f, 85.f, 358.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 127.f, 362.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 165.f, 340.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 170.f, 295.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 145.f, 260.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 100.f, 255.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 65.f, 280.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 60.f, 325.f, 255, 0, 127, 5.f, 204, 0, 204);

	drawCvijet(45.f, 90.f, 285.f, 51, 0, 102, 5.f, 153, 153, 255);

	//Cvijet2
	drawCvijet(20.f, 385.f, 358.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 427.f, 362.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 465.f, 340.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 470.f, 295.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 445.f, 260.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 400.f, 255.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 365.f, 280.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawCvijet(20.f, 360.f, 325.f, 51,0,102, 5.f, 153, 153, 255);

	drawCvijet(35.f, 400.f, 295.f, 255, 0, 127, 20.f, 204, 0, 204);





	//Cvijet3
	drawCvijet(20.f, 685.f, 358.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 727.f, 362.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 765.f, 340.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 770.f, 295.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 745.f, 260.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 700.f, 255.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 665.f, 280.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(20.f, 660.f, 325.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawCvijet(45.f, 690.f, 285.f, 51, 0, 102, 5.f, 153, 153, 255);






	


	







}


