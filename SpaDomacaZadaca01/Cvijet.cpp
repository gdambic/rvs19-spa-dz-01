#include "Cvijet.h"
#include<SFML/Graphics.hpp>
#include "Latica.h"
#include"sareniCvijet.h"
#include<cmath>
#include"EllipseShape.h"
#include<vector>
#include<ctime>



void Cvijet::padajKiso()
{
	for (int i = 0; i < 30; i++) {

		window->draw(kapljice[i].crtaj(xKapljice[i], clock.getElapsedTime().asMilliseconds()% (800 + i * 50)));
	}
}

void Cvijet::paduckajKiso()
{
	for (int i = 0; i < 8; i++) {

		window->draw(kapljice[i].crtaj(i*100, clock.getElapsedTime().asMilliseconds() % (800 + i * 50)));
	}
}

void Cvijet::randomBrojevi()
{
	srand(time(NULL));
	
	for (int i = 0; i < 30; i++) {
		xKapljice[i] = rand() % 800;
	}
	

}

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
	crtajMaslaèak();
	//inSareniCvijet();
	brojac = 0;
	brojLatica = 28;
	sarenko[0].konstruktor(1, 400, 400,window);
	sarenko[1].konstruktor(0.3, 500, 500,window);
	sarenko[2].konstruktor(0.4, 225, 470, window);
	sarenko[3].konstruktor(3.5, 600, 300,window);
	sarenko[4].konstruktor(2, 300, 370,window);
	
	randomBrojevi();
	
}

void Cvijet::draw()
{
	
	int sat = clock.getElapsedTime().asMilliseconds();
	int sat2 = clock2.getElapsedTime().asMilliseconds();
	crtajTravnjak();
	if (sat > 6000) {
		crtajStabljikuMaslackovu();
	}

		for (int i = 0; i < 5; i++) {
			sarenko[i].zapocni(0,-abc);
		}
	
	if ( sat > 7300 )
	{


		


		{
			for (int i = 0; i < brojac; i++) {
				window->draw(sareniCvijet[i], pretvorbe[i]);
				window->draw(sarenko[0].na(i), sarenko[0].at(i));
				window->draw(sarenko[1].na(i), sarenko[1].at(i));
				window->draw(sarenko[2].na(i), sarenko[2].at(i));
				window->draw(sarenko[4].na(i), sarenko[4].at(i));
				window->draw(sarenko[3].na(i), sarenko[3].at(i));


			}
		}
		for (int i = 0; i < brojac2; i++) {
			window->draw(ciri2[brojLatica2 - 1 - i], pretvorbeMaslacka[brojLatica2 - 1 - i]);

		}

		if (brojac2 < brojLatica2 - 1) {
			brojac2 += 6;


		}
		if (brojac < brojLatica - 1)
			brojac++;
	}
	
	
	if (brojac2 > 700)
		padajKiso();
	else
		paduckajKiso();
	



	}
	
	
	
	


sf::CircleShape Cvijet::svet()
{
	return shape;
}

int Cvijet::a()
{
	return 0;
}

void Cvijet::crtajMaslaèak()
{
	
	int k = 0;
	int udaljenost = 50;
	for (int j = 80; j > 0; j -= 5) {
		udaljenost = j;
		int s = j;
		if (j < 10)
			s = 80;
		for (double i = 0; i <= 2 * atan(1) * 4; i += atan(1) / (s / 8)) {
			double x = 140;
			double y = 150;
			double xT = x + cos(i) * udaljenost;
			double yT = y - sin(i) * udaljenost;
			if (j > 9)
				ciri2[k].setRadius(5);
			else ciri2[k].setRadius(2);
			ciri2[k].setPosition(xT, yT);
			if (j > 50)
				ciri2[k].setFillColor(Color::White);
			else if (j > 30)
				ciri2[k].setFillColor(Color::White);
			else if (j < 10)
				ciri2[k].setFillColor(Color::White);

			else
				ciri2[k].setFillColor(Color::White);
			ciri2[k].setScale(3.f, 0.2f);
			Transform t;
			t.rotate(-(i * 180) / ((atan(1) * 4)), Vector2f(xT, yT));
			pretvorbeMaslacka[k] = t;
			k++;
			brojLatica2 = k - 1;
		}
		
		brojac2 = 0;
	}
	
}

void Cvijet::crtajTravnjak()
{

	for (int j = -400; j < 450; j+=5) {
		for (float i = 0; i < 1; i += 0.01) {
			int p = 60;
			float iksic = i * i - 1;
			float iksic2 = (i - 0.01) * (i - 0.01) - 1;
			sf::Vertex linez[] =
			{
				  sf::Vertex(sf::Vector2f(j+400 -(i * p)  , 550 - iksic * p)),
				  sf::Vertex(sf::Vector2f(j+400 -((i + 0.01) * p ) , 550 - iksic2 * p))
			};
			
			linez->color = (Color::Green);
			window->draw(linez, 2, sf::Lines);


		}
	}
}

void Cvijet::inSareniCvijet()
{
	int k = 0;
	int udaljenost = 50;
	//inicijaliziranje sarenog cvijeta
	

	for (int j = 4; j > 0; j -= 1) {
		udaljenost = j;
		int s = j;
		if (j < 10)
			s = 80;
		for (double i = 0; i <= 2 * atan(1) * 4; i += atan(1) * 4 / 3) {
			if (i == 0 && j == 1) { i = -0.25; }
			else if (i == 0 && j == 2) { i = -0.5; }
			else if (i == 0 && j == 3) { i = -0.75; }
			if (i == 5) { i == atan(1) * 4; }
			double x = 600;
			double y = 300;
			double xT = x;
			double yT = y;
			if (j == 2)
				sareniCvijet[k].setRadius(10);
			else if (j == 5) { sareniCvijet[k].setRadius(30); }
			else {
				sareniCvijet[k].setRadius(15);

			}
			sareniCvijet[k].setPosition(xT, yT);
			if (j == 2)
				sareniCvijet[k].setFillColor(Color::White);
			else if (j == 5) {
				sareniCvijet[k].setFillColor(Color::White);

			}
			else if (k % 3 == 1) {
				sareniCvijet[k].setFillColor(Color::Blue);

			}
			else if (k % 3 == 2)
				sareniCvijet[k].setFillColor(Color::Red);

			else
				sareniCvijet[k].setFillColor(Color::Magenta);
			if (j == 5)
				sareniCvijet[k].setScale(3.f, 0.2f);
			else
				sareniCvijet[k].setScale(3.f, 0.6f);
			pretvorbe[k].rotate(-(i * 180) / ((atan(1) * 4)), Vector2f(xT, yT));

			k++;
		}
	}
	brojLatica = k;
	brojac = 0;
}

void Cvijet::crtajStabljikuMaslackovu()
{
	sf::RectangleShape line(sf::Vector2f(450, 9));
	line.rotate(90);
	line.setFillColor(Color::Green);
	
	if (abc > -300)
	{
		Transform transform;
		line.setPosition(Vector2f(145, 445 + abc));
		window->draw(line, transform);
		abc -= 15;
	}
	else if (abc > -320) {
		Transform transform;
		line.setPosition(Vector2f(145, 145));
		window->draw(line, transform);
		abc -= 15;

	}
	else {
		line.setPosition(Vector2f(145, 145));
		window->draw(line);

	}
}
