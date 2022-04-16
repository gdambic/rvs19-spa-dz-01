#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window){
	this->window = window;
}


void Cvijet::crtajSunce(){

	
	sf::CircleShape sunce(30.f);

	sunce.move(10.f, 10.f);
	sunce.setFillColor(sf::Color::Yellow);
	sf::Time elapsed = clock.getElapsedTime();

	if (clock.getElapsedTime().asMilliseconds() > 8000){
		sunce.setRadius(30.f - 5.f * ((clock.getElapsedTime().asMilliseconds() - 3000) / 3000.f));


	}
	else
	{
		sunce.setRadius(30.f + 5.f * (clock.getElapsedTime().asMilliseconds() / 3000.f));
	}



	window->draw(sunce);


}


void Cvijet::crtajCvijet() {
	
	float sirinaUnutarnjegDijela = 60.f;
	float sirinaVanjskogDijela = 30.f;
	sf::CircleShape cvijet(sirinaUnutarnjegDijela);
	cvijet.move(300.f, 150.f);
	cvijet.setFillColor(sf::Color::Yellow);

	cvijet.setOutlineThickness(sirinaVanjskogDijela);
	cvijet.setOutlineColor(sf::Color(250,0,0));

	window->draw(cvijet);

}


void Cvijet::crtajPeteljku(){

	sf::RectangleShape peteljka(sf::Vector2f(150.f, 10.f));
	peteljka.setFillColor(sf::Color::Green);
	peteljka.move(365.f, 295.f);
	peteljka.rotate(90.f);
	window->draw(peteljka);
}

void Cvijet::crtajListu(){

	sf::ConvexShape list;
	list.setPointCount(4);//broj kuteva lista
	list.setPoint(0, sf::Vector2f(100.f, 0.f));
	list.setPoint(1, sf::Vector2f(150.f, 50.f));
	list.setPoint(2, sf::Vector2f(70.f, 50.f));
	list.setPoint(3, sf::Vector2f(0.f, 0.f));
	list.setFillColor(sf::Color::Green);
	list.move(205.f, 305.f);
	window->draw(list);
}

void Cvijet::crtaj(){

	crtajSunce();
	crtajCvijet();
	crtajPeteljku();
	crtajListu();
}

