#pragma once
#include<SFML/Graphics.hpp>
#include"Tocka.h"

class Cvijet {
	sf::RenderWindow* RenWin;

	Tocka Pozicija;
	double RadiusCvijeta;
	double VisinaCvijeta;
	int BrojLatica;
	double VelicinaLista;

	void SetStandard();
	
public:
	Cvijet(sf::RenderWindow* WinToRender);

	void GenerirajNasumicniCvijet(int avRadius, int avVisina, int avBrojLatica, int avList);
	void GenerirajNasumicnuPoziciju(Tocka RasponGL, Tocka RasponDD);
	void GenerirajNasumicnuPoziciju(double x0, double y0, double x1, double y1);

	void ResetCvijet();
	void PovecajCvijet(double Skala);

	void PomakniCvijet(Tocka mov);
	void PomakniCvijet(double xmov, double ymov);

	void SetPozicija(Tocka Pozicija);
	void SetPozicija(double x, double y);
	void SetRadius(double NoviRadius);
	void SetVisina(double NovaVisina);
	void SetBrojLatica(int BrojLatica);
	void SetVelicinaLista(double VelicinaLista);

	Tocka GetPozicija();
	sf::Vector2f GetPozVektor();
	double GetRadius();
	double GetVisina();
	int GetBrojLatica();
	double GetVelicinaLista();

	void draw();
};