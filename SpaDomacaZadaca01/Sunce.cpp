#include "Sunce.h"

Sunce::Sunce(sf::RenderWindow* Ren) {
	this->RenWin = Ren;
}

void Sunce::SetPoz(Tocka Poz) {
	this->Pozicija = Poz;
}

void Sunce::SetPoz(double x, double y) {
	this->SetPoz(Tocka(x, y));
}

void Sunce::draw() {
	sf::CircleShape Sunce;
	const double RadiusSunca = 125.0;
	
	sf::Time ProtekloVrijeme = this->PocetakPostojanja.getElapsedTime();
	Sunce.setRadius(RadiusSunca);
	if (ProtekloVrijeme.asSeconds() < 5) Sunce.setRadius(RadiusSunca / 1.25);
	else if (ProtekloVrijeme.asSeconds() < 10) Sunce.setRadius(RadiusSunca / 1.5);
	else if (ProtekloVrijeme.asSeconds() < 15) Sunce.setRadius(RadiusSunca / 1.75);
	else this->PocetakPostojanja.restart();

	Sunce.setOrigin(Sunce.getRadius(), Sunce.getRadius());
	Sunce.setPosition(this->Pozicija.GetVector2f());
	Sunce.setFillColor(sf::Color::Yellow);

	this->RenWin->draw(Sunce);
}
