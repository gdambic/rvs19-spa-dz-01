#include "Cvijet.h"
#include <ctime>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	const int POZICIJA_X = 200;
	const int POZICIJA_Y = 150; //definiram pozicije na ekranu gdje æe se iscrtavati krug

	srand(time(nullptr)); //postavljam seed jer æu generirati sluèajne brojeve

	float radijus_kruga = gen_rnd(50.f, 150.f); //generiram sluèajni radijus kruga koji predstavlja cvijet
	sf::CircleShape krug(radijus_kruga,500);  //stvaram objekt klase CircleShape 
	krug.setFillColor(boja()); //postavljam svojstva za krug
	krug.setOutlineThickness(10.f);
	krug.setOutlineColor(boja());
	krug.setPosition(POZICIJA_X, POZICIJA_Y);

	sf::RectangleShape pravokutnik(sf::Vector2f(800.f,600.f)); //postavljam pravokutnik preko cijelog prozora
	pravokutnik.setFillColor(sf::Color(0,255,0));  //hardkodiram zelenu jer je trava zelena, a cvijet raste negdje u travi :D

	sf::RectangleShape stabljika(sf::Vector2f(gen_rnd(5,15),gen_rnd(200,250))); 
	stabljika.setPosition(POZICIJA_X+radijus_kruga, POZICIJA_Y+ (2 * radijus_kruga)); 
	stabljika.setFillColor(boja());


	window->draw(pravokutnik);
	window->draw(krug);
	window->draw(stabljika);
	
	
}

int Cvijet::gen_rnd(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

sf::Color Cvijet::boja()
{
	int r = gen_rnd(0, 255);
	int g = gen_rnd(0, 255);
	int b = gen_rnd(0, 255);
	return sf::Color(r,g,b);
}






