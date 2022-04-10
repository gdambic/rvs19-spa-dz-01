#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(sf::RenderWindow &window,int x,int y,double e);
	Cvijet& operator=(const Cvijet& source);
	void draw();
	void update();
	void setPos(int x,int y);
	void setElasticity(double e);
	bool trebaUnistiti();
private:
	sf::RenderWindow &prozor;
	double x = 50;
	double y = 0;
	double dy = 0;
	double gravity=0.1;
	double elasticity = 0.5;
	bool unistiti = false;
};

