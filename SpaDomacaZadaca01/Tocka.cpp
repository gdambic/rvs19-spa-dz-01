#include "Tocka.h"

Tocka::Tocka() : x(0), y(0) {}

Tocka::Tocka(double x, double y) {
	this->init(x, y);
}

void Tocka::SetX(double x) {
	this->x = x;
}

void Tocka::SetY(double y) {
	this->y = y;
}

void Tocka::init(double x, double y) {
	this->SetX(x);
	this->SetY(y);
}

void Tocka::init(Tocka toc) {
	this->SetX(toc.GetX());
	this->SetY(toc.GetY());
}

double Tocka::GetX() {
	return this->x;
}

double Tocka::GetY() {
	return this->y;
}

Tocka Tocka::GetTocka() {
	Tocka temp;
	temp.x = this->GetX();
	temp.y = this->GetY();

	return temp;
}

sf::Vector2f Tocka::GetVector2f() {
	sf::Vector2f temp_V2;
	temp_V2.x = this->GetX();
	temp_V2.y = this->GetY();
	return temp_V2;
}

Tocka Tocka::operator+(Tocka t) {
	Tocka temp;
	temp.SetX(this->GetX() + t.GetX());
	temp.SetY(this->GetY() + t.GetY());
	return temp;
}

Tocka Tocka::operator-(Tocka t) {
	Tocka temp;
	temp.SetX(this->GetX() - t.GetX());
	temp.SetY(this->GetY() - t.GetY());
	return temp;
}

void Tocka::operator=(Tocka t) {
	this->init(t);
}

void Tocka::operator+=(Tocka t) {
	this->SetX(this->GetX() + t.GetX());
	this->SetY(this->GetY() + t.GetY());
}

void Tocka::operator-=(Tocka t) {
	this->SetX(this->GetX() - t.GetX());
	this->SetY(this->GetY() - t.GetY());
}