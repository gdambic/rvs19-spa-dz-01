#include "Cvijet.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{	
	RectangleShape zemlja(Vector2f(800, 600));  // pozadina (oblik pravokutnika)
	zemlja.setFillColor(Color(43, 15, 53));	// odabir boje
	window->draw(zemlja);					// izrada pozadine

	RectangleShape nebo(Vector2f(800, 550));  
	nebo.setFillColor(Color(56, 18, 70));	
	window->draw(nebo);	

	
	CircleShape cvijet(50.f, 8);		// izrada oktogona (cvijeta) promjera 50.f, sa 8 toèaka
	cvijet.setPosition(350.f, 320.f);	// pozicioniranje na kooridante
	cvijet.setFillColor(Color(4, 15, 115));		// odabir boje
	window->draw(cvijet);					// iscrtavanje cvijeta

	CircleShape cvijet2(30.f, 8);		// izrada ispune cvijeta promjera 
	cvijet2.setPosition(370.f, 340.f);	// pozicioniranje na kooridante
	cvijet2.setFillColor(Color(5, 14, 73));		
	window->draw(cvijet2);					

	RectangleShape linija(Vector2f(4.f, 200.f));	// postavljanje prve toèke
	linija.setPosition(398.f, 420.f);				
	linija.setFillColor(Color(1, 15, 105));		// odabir boje
	window->draw(linija);

	CircleShape mjesec(80.f);				// izrada kruga (mjeseca)
	//mjesec.setPosition(125.f, 100.f);
	mjesec.setFillColor(Color(200, 200, 200));
	

	CircleShape mladi_mjesec(80.f);			// drugi krug
	//mladi_mjesec.setPosition(130.f, 100.f);
	mladi_mjesec.setFillColor(Color(56, 18, 70));
	

	Time vrijeme = clock.getElapsedTime();

	mjesec.setPosition(125.f + clock.getElapsedTime().asMilliseconds() / 100.f, 100.f); //kretanje prvog kruga po (x, y)
	window->draw(mjesec);

	mladi_mjesec.setPosition(130.f + clock.getElapsedTime().asMilliseconds() / 70.f, 100.f); //kretanje kruga po (x, y)
	window->draw(mladi_mjesec);

}
