#pragma once
#include<SFML/Graphics.hpp>
#include"Tocka.h"
class Pravokutnik {
	sf::RenderWindow* RenWin;
	
	Tocka GL;	//Gore lijevo
	Tocka DD;	//Dolje desno

	bool PostaviOutline;
	int Debljina;

	sf::RectangleShape prav;
	sf::Color Boja;
	bool PravokutnikGeneriran;

public:
	Pravokutnik(sf::RenderWindow* Ren);
	void SetPosGL(Tocka GL);
	void SetPosGL(double x, double y);

	void SetPosDD(Tocka DD);
	void SetPosDD(double x, double y);

	void SetOutline(bool tf, int debljina);
	void SetBoja(sf::Color C);

	void GenPravokutnik();

	void draw();
};