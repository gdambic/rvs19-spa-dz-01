#include "Pravokutnik.h"

Pravokutnik::Pravokutnik(sf::RenderWindow* Ren) {
	this->RenWin = Ren;
	this->PostaviOutline = false;
	this->PravokutnikGeneriran = false;
}

void Pravokutnik::SetPosGL(Tocka GL) {
	this->GL = GL;
}

void Pravokutnik::SetPosGL(double x, double y) {
	this->SetPosGL(Tocka(x, y));
}

void Pravokutnik::SetPosDD(Tocka DD) {
	this->DD = DD;
}

void Pravokutnik::SetPosDD(double x, double y) {
	this->SetPosDD(Tocka(x, y));
}

void Pravokutnik::SetOutline(bool tf, int debljina) {
	this->PostaviOutline = tf;
	this->Debljina = debljina;
}

void Pravokutnik::SetBoja(sf::Color C) {
	this->Boja = C;
}

void Pravokutnik::GenPravokutnik() {
	sf::Vector2f Size;
	Size.x = this->DD.GetX() - this->GL.GetX();
	Size.y = this->DD.GetY() - this->GL.GetY();

	this->prav.setSize(Size);
	this->prav.setPosition(this->GL.GetVector2f());
	this->prav.setFillColor(this->Boja);

	if (this->PostaviOutline) {
		this->prav.setOutlineThickness(this->Debljina);
		this->prav.setOutlineColor(sf::Color::Color(30, 135, 31, 255));
	}
	this->PravokutnikGeneriran = true;
}

void Pravokutnik::draw() {
	if (!this->PravokutnikGeneriran) this->GenPravokutnik();
	this->RenWin->draw(this->prav);
}