#include "CvijetMover.h"

CvijetMover::CvijetMover(sf::RenderWindow* Window, Tocka Pomak) {
	this->RenWin = Window;
	this->Pomak = Pomak;
}

CvijetMover::CvijetMover(sf::RenderWindow* Window, double x, double y) {
	this->RenWin = Window;
	this->Pomak = Tocka(x, y);
}

void CvijetMover::SetPomak(Tocka Pomak) {
	this->Pomak = Pomak;
}

void CvijetMover::SetPomak(double x, double y) {
	this->SetPomak(Tocka(x, y));
}

Cvijet CvijetMover::GetCvijet(int index) {
	if (index < 0 || index >= this->PoljeCvijeca.size()) return Cvijet(this->RenWin);
	return this->PoljeCvijeca[index];
}

void CvijetMover::UkloniCvijet(int index) {
	if (index < 0 || index >= this->PoljeCvijeca.size()) return;
	auto VecIT = this->PoljeCvijeca.begin();
	this->PoljeCvijeca.erase(VecIT + index);
}

void CvijetMover::PushCvijet(Cvijet& Dodatak) {
	this->PoljeCvijeca.push_back(Dodatak);
}

void CvijetMover::UpdateCvijece() {
	for (int i = 0; i < this->PoljeCvijeca.size(); i++) {
		this->PoljeCvijeca[i].PomakniCvijet(this->Pomak);
		if (this->PoljeCvijeca[i].GetPozicija().GetX() > this->RenWin->getSize().x + 20.0) this->UkloniCvijet(i);
	}
}

void CvijetMover::draw() {
	for (int i = 0; i < this->PoljeCvijeca.size(); i++) {
		this->PoljeCvijeca[i].draw();
	}
}