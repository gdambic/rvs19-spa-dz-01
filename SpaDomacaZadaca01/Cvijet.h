#pragma once
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Cvijet
{
private:
	RenderWindow* window;
	int x = 500;
	int y = 20;
	int doljna_granica=50;
	int gornja_granica=700;
	double brzina = 2;
	Clock clock;
	Time dt;
public:
	Cvijet(RenderWindow* window);
	void draw();
};

