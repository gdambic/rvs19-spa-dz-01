#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(int x,int y,double e);
	Cvijet(sf::RenderWindow& window);
	Cvijet& operator=(const Cvijet& source);
	void drawKrug(sf::RenderWindow& window,const sf::Texture& lopta);
	void draw(sf::RenderWindow& window);
	void drawSunce(sf::Clock &cukica, sf::RenderWindow& window);
	void update();
	void setPos(int x,int y);
	void setElasticity(double e);
	bool trebaUnistiti();
private:
	double x = 50;
	double y = 50;
	double dy = 0;
	double gravity=0.5;
	double elasticity = 0.5;
	bool unistiti = false;
};

