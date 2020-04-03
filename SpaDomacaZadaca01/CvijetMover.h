#pragma once
#include"Cvijet.h"
#include<vector>
using namespace std;
class CvijetMover {
	vector<Cvijet> PoljeCvijeca;
	Tocka Pomak;

	sf::RenderWindow* RenWin;
public:
	CvijetMover(sf::RenderWindow* Window, Tocka Pomak);
	CvijetMover(sf::RenderWindow* Window, double x, double y);

	void SetPomak(Tocka Pomak);
	void SetPomak(double x, double y);
	
	Cvijet GetCvijet(int index);

	void UkloniCvijet(int index);

	void PushCvijet(Cvijet& Dodatak);

	void UpdateCvijece();
	void draw();
};