#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(int x,int y,double e,sf::Texture &lopta);
	Cvijet(sf::RenderWindow& window,sf::Texture& lopta);
	Cvijet& operator=(const Cvijet& source);
	void drawKrug(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void drawSunce(sf::Clock &cukica, sf::RenderWindow& window);
	void update();
	void setPos(int x,int y);
	void setElasticity(double e);
	bool trebaUnistiti();
private:
	sf::Texture& texture;
	double x = 50;
	double y = 50;
	double dy = 0;
	double gravity=0.5;
	double elasticity = 0.5;
	bool unistiti = false;
};

