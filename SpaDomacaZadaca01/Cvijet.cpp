#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
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

	

	if (clock.getElapsedTime().asMilliseconds() > 6000)
	{
		sunce.setRadius(radius - 5.f * ((clock.getElapsedTime().asMilliseconds() - 3000) / 3000.f));

	}
	else
	{
		sunce.setRadius(radius  + 5.f * (clock.getElapsedTime().asMilliseconds() / 3000.f));
	}
	adresa->draw(sunce);


	
}


void Cvijet::drawKrug(float radius, float position1, float position2, int fillR, int fillG, int fillB, float outline, int outR, int outG, int outB)
{
	CircleShape krug (radius);
	krug.setPosition(position1, position2);
	krug.setFillColor(Color(fillR, fillG, fillB));
	krug.setOutlineThickness(outline);
	krug.setOutlineColor(Color(outR, outG, outB));

	adresa->draw(krug);

}

void Cvijet::drawOblak()
{
	  
		CircleShape oblak(45.f);

		oblak.setFillColor(Color(255, 255, 255));

		CircleShape oblak1(50.f);
	
	
		oblak1.setFillColor(Color(255, 255, 255));

		CircleShape oblak2(43.f);
	
	
		oblak2.setFillColor(Color(255, 255, 255));

		Time elapsed = clock.getElapsedTime();

		if (clock.getElapsedTime().asMilliseconds() > 7000)
		{
			oblak.setPosition(2140.f -150.f * (clock.getElapsedTime().asMilliseconds()  /1000.f), 30.f);
			oblak1.setPosition(2180.f - 150.f * (clock.getElapsedTime().asMilliseconds()  / 1000.f), 30.f);
			oblak2.setPosition(2220.f - 150.f * (clock.getElapsedTime().asMilliseconds()  / 1000.f), 30.f);
			if (clock.getElapsedTime().asMilliseconds() >= 20000)
			{
				clock.restart();
			}
		}
		else
		{
			oblak.setPosition(140.f +150.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);
			oblak1.setPosition(180.f + 150.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);
			oblak2.setPosition(220.f + 150.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 30.f);

		}
	
		adresa->draw(oblak);
		adresa->draw(oblak1);
		adresa->draw(oblak2);
}



void Cvijet::drawLivada()
{
	double t1 = 0.f;
	double t2 = 720.f;
	double t3 = 2.f;
	double t4 = 400.f;
	double t5 = 5.f;
	double t6 = 720.f;
	int count = 0;
	srand(time(nullptr));

	for (int i = 0; i < 300; i++) {
		ConvexShape livada(4);
		livada.setPoint(0, Vector2f(t1, t2));
		livada.setPoint(1, Vector2f(t3, t4));
		livada.setPoint(2, Vector2f(t5, t6));
		livada.setPoint(3, Vector2f(t1, t2));
		livada.setFillColor(Color(25, rand() % 250 + 1 , 11));
		adresa->draw(livada);
		t1 += 4;
		t3 += 4;
		t5 += 4;
		if (count < 5) {
		
			t4 += 15;
			
			count++;
		}
		else if (count == 5)  {
			
			t4 = 400.f;
			
			count= 0;
		}

	}


}

void Cvijet::dugaHide()
{
	
	CircleShape krug(600.f);
	//krug.setPosition(0.f, 0.f);
	krug.setFillColor(Color(10, 143, 245));
	// ako želimo da se pojavi i nestane ukljuèiti
	//if (clock.getElapsedTime().asMilliseconds() > 7000)
	//{
	//	krug.setPosition(2140.f - 150.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 100.f);
	//
	//	
	//}
	//else
	//{
		krug.setPosition(140.f + 150.f * (clock.getElapsedTime().asMilliseconds() / 1000.f), 100.f);


	//}

	adresa->draw(krug);
}

void Cvijet::draw()
{
	
	drawNebo();
	

	//Duga
	drawKrug(400.f, 100.f, 200.f, 255, 87, 51, 30.f, 208,20,20);
	drawKrug(350.f, 150.f, 250.f, 20, 233, 228, 30.f, 231, 241, 13);
	drawKrug(300.f, 200.f, 300.f, 10, 143, 245, 30.f, 9, 53, 118);
	dugaHide();
	//oblak i livada
	drawSunce(80.f, 1050.f, -20.f, 255, 255, 0, 10.f, 255, 255, 153);
	drawLivada();
	drawOblak();

		

	//Cvijet1
	drawKrug(20.f, 85.f, 658.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 127.f, 662.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 165.f, 640.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 170.f, 595.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 145.f, 560.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 100.f, 555.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 65.f, 580.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 60.f, 625.f, 255, 0, 127, 5.f, 204, 0, 204);

	drawKrug(45.f, 90.f, 585.f, 51, 0, 102, 5.f, 153, 153, 255);



	//Cvijet2
	drawKrug(20.f, 385.f, 558.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 427.f, 562.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 465.f, 540.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 470.f, 495.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 445.f, 460.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 400.f, 455.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 365.f, 480.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 360.f, 525.f, 51,0,102, 5.f, 153, 153, 255);

	drawKrug(35.f, 400.f, 495.f, 255, 0, 127, 10.f, 204, 0, 204);


	//Cvijet3
	drawKrug(20.f, 685.f, 658.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 727.f, 662.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 765.f, 640.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 770.f, 595.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 745.f, 560.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 700.f, 555.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 665.f, 580.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(20.f, 660.f, 625.f, 255, 0, 127, 5.f, 204, 0, 204);
	drawKrug(45.f, 690.f, 585.f, 51, 0, 102, 5.f, 153, 153, 255);

	//Cvijet4
	drawKrug(20.f, 985.f, 558.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 1027.f, 562.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f,1065.f, 540.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 1070.f, 495.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 1045.f, 460.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 1000.f, 455.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 965.f, 480.f, 51, 0, 102, 5.f, 153, 153, 255);
	drawKrug(20.f, 960.f, 525.f, 51, 0, 102, 5.f, 153, 153, 255);

	drawKrug(35.f, 1000.f, 495.f, 255, 0, 127, 10.f, 204, 0, 204);



	



}


