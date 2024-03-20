#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>

class Cvijet
{
private:
	float c2_r = 50.0;
public:
	Cvijet(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window, Cvijet* cvijet);
	void update(Cvijet* cvijet, float* dt);
};

