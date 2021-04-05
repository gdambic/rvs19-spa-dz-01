#pragma once
#include<SFML/Graphics.hpp>
#include<Windows.h>

class stabljike
{
private:
	sf::RectangleShape line;
	int a = 1;

public:
	void crtaj(int duljina, int x, int y , sf::RenderWindow& window);
	void inicializiraj(int duzina, int debljina, sf::RenderWindow& window,int x0,int y0,int a0, int b0);
	
	sf::RectangleShape dajLiniju();
	

};

