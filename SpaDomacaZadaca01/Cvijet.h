#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow &window;
	sf::Time dt;
	sf::Clock clock;
	float brzina;
	float brzina2;
	float elipsaX;
	float elipsa2X;
	float elipsa3X;
	float elipsa4X;
	float elipsa5X;
	float elipsa6X;
	float elipsa7X;
	float listR;
	float list2R;
	float r;
	float x;

public:
	Cvijet(sf::RenderWindow &window); 
	void draw_krug();
	void draw_stabljika();
	void draw_latice(); 
	void draw_list(); 
	void draw_list2(); 
	void draw_trava();
	void draw(); 
};

