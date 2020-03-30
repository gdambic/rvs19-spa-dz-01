#include "Cvijet.h"
#include<cmath>
#include<iostream>

void Cvijet::SetStandard() {
	this->Pozicija.init(0.0, 0.0);
	this->RadiusCvijeta = 18.0;
	this->VisinaCvijeta = 50.0;
	this->BrojLatica = 7;
	this->VelicinaLista = 1.0;
}

Cvijet::Cvijet(sf::RenderWindow* WinToRender) {
	this->RenWin = WinToRender;
	this->SetStandard();
}

void Cvijet::GenerirajNasumicniCvijet(int avRadius, int avVisina, int avBrojLatica, int avList) {
	this->SetRadius((double)(rand() % (avRadius * 2 - avRadius / 2) + avRadius / 2));
	this->SetVisina((double)(rand() % (avVisina * 2 - avVisina / 2) + avVisina / 2));
	this->SetBrojLatica(rand() % (avBrojLatica * 2 - avBrojLatica / 2) + avBrojLatica / 2);
	this->SetVelicinaLista((double)((rand() % (avList * 2 - avList / 2) + avList / 2)/10));
}

void Cvijet::GenerirajNasumicnuPoziciju(Tocka RasponGL, Tocka RasponDD) {
	Tocka Poz;
	Poz.SetX(rand()%((int)(RasponDD.GetX() - RasponGL.GetX() + 1)) + RasponGL.GetX());
	Poz.SetY(rand()%((int)(RasponDD.GetY() - RasponGL.GetY() + 1)) + RasponGL.GetY());
	this->SetPozicija(Poz);
}

void Cvijet::GenerirajNasumicnuPoziciju(double x0, double y0, double x1, double y1) {
	this->GenerirajNasumicnuPoziciju(Tocka(x0, y0), Tocka(x1, y1));
}

void Cvijet::ResetCvijet() {
	this->SetStandard();
}

void Cvijet::PovecajCvijet(double Skala) {
	this->SetRadius(this->GetRadius() * Skala);
	this->SetVisina(this->GetVisina() * Skala);
	this->SetVelicinaLista(this->GetVelicinaLista() * Skala);
}

void Cvijet::PomakniCvijet(Tocka mov) {
	this->SetPozicija(this->GetPozicija() + mov);
}

void Cvijet::PomakniCvijet(double xmov, double ymov) {
	this->PomakniCvijet(Tocka(xmov, ymov));
}

void Cvijet::SetPozicija(Tocka Pozicija) {
	this->Pozicija = Pozicija;
}

void Cvijet::SetPozicija(double x, double y) {
	this->SetPozicija(Tocka(x, y));
}

void Cvijet::SetRadius(double NoviRadius) {
	if (NoviRadius < 1) NoviRadius = 1;
	this->RadiusCvijeta = NoviRadius;
}

void Cvijet::SetVisina(double NovaVisina) {
	if (NovaVisina < 1) NovaVisina = 1;
	this->VisinaCvijeta = NovaVisina;
}

void Cvijet::SetBrojLatica(int BrojLatica) {
	if (BrojLatica < 0) BrojLatica = 0;
	this->BrojLatica = BrojLatica;
}

void Cvijet::SetVelicinaLista(double VelicinaLista) {
	if (VelicinaLista < 0.5) VelicinaLista = 0.5;
	this->VelicinaLista = VelicinaLista;
}

Tocka Cvijet::GetPozicija() {
	return this->Pozicija;
}

sf::Vector2f Cvijet::GetPozVektor() {
	return this->GetPozicija().GetVector2f();
}

double Cvijet::GetRadius() {
	return this->RadiusCvijeta;
}

double Cvijet::GetVisina() {
	return this->VisinaCvijeta;
}

int Cvijet::GetBrojLatica() {
	return this->BrojLatica;
}

double Cvijet::GetVelicinaLista() {
	return this->VelicinaLista;
}

void Cvijet::draw() {
	sf::Vector2f Vect;

	sf::CircleShape CvijetGL;
	CvijetGL.setRadius(this->GetRadius());
	CvijetGL.setFillColor(sf::Color::Green);
	CvijetGL.setPosition(this->GetPozVektor());

	sf::CircleShape SredinaCvijeta;
	SredinaCvijeta.setRadius(CvijetGL.getRadius() / 1.25);
	SredinaCvijeta.setOrigin(SredinaCvijeta.getRadius(), SredinaCvijeta.getRadius());
	SredinaCvijeta.setFillColor(sf::Color::Yellow);
	Vect.x = CvijetGL.getPosition().x + CvijetGL.getRadius();
	Vect.y = CvijetGL.getPosition().y + CvijetGL.getRadius();
	SredinaCvijeta.setPosition(Vect);

	sf::RectangleShape StabiljkaCvijeta;
	double StemShrink = 6.0;
	Vect.x = CvijetGL.getRadius() / StemShrink;
	Vect.y = this->GetVisina();
	StabiljkaCvijeta.setSize(Vect);
	StabiljkaCvijeta.setFillColor(sf::Color::Green);

	Vect = CvijetGL.getPosition();
	Vect.x += CvijetGL.getRadius() - (CvijetGL.getRadius() / StemShrink / 2);
	Vect.y += CvijetGL.getRadius() * 2 - 10;
	StabiljkaCvijeta.setPosition(Vect);

	this->RenWin->draw(StabiljkaCvijeta);

	sf::CircleShape LaticaCvijeta;
	LaticaCvijeta.setRadius(CvijetGL.getRadius() / 2);
	LaticaCvijeta.setFillColor(sf::Color::Red);

	double PomakLatica = 2 * 3.14159 / this->GetBrojLatica();
	for (int i = 0; i < this->GetBrojLatica(); i++) {
		Vect.x = (std::sin(PomakLatica * i) * CvijetGL.getRadius()) + CvijetGL.getPosition().x + CvijetGL.getRadius() / 2.0;
		Vect.y = (std::cos(PomakLatica * i) * CvijetGL.getRadius()) + CvijetGL.getPosition().y + CvijetGL.getRadius() / 2.0;

		LaticaCvijeta.setPosition(Vect);
		this->RenWin->draw(LaticaCvijeta);
	}

	sf::ConvexShape Leaf;
	Leaf.setPointCount(4);

	Vect.x = 0;
	Vect.y = 10 * this->GetVelicinaLista();
	Leaf.setPoint(0, Vect);

	Vect.x = 30 * this->GetVelicinaLista();
	Vect.y = 0;
	Leaf.setPoint(1, Vect);

	Vect.x = 15 * this->GetVelicinaLista();
	Vect.y = 15 * this->GetVelicinaLista();
	Leaf.setPoint(2, Vect);

	Vect.x = 0 * this->GetVelicinaLista();
	Vect.y = 14 * this->GetVelicinaLista();
	Leaf.setPoint(3,Vect);
	
	Leaf.setFillColor(sf::Color::Green);
	Leaf.setOrigin(0, 10 * this->GetVelicinaLista());
	Vect = StabiljkaCvijeta.getPosition();
	Vect.x += StabiljkaCvijeta.getSize().x;
	Vect.y += StabiljkaCvijeta.getSize().y / 2;
	Leaf.setPosition(Vect);

	this->RenWin->draw(CvijetGL);
	this->RenWin->draw(SredinaCvijeta);
	this->RenWin->draw(Leaf);
}