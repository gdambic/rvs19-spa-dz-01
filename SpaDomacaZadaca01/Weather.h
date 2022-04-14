#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Colors.h"
using namespace std;
using namespace sf;
class Weather
{
public:
	Weather(RenderWindow* window, struct colors* c);
	void initSun();
	void initStars();
	void initRain();
	bool getRain();
	bool getDay();
	void updateCloud();
	void updateStars();
	void updateRain();
	void updateSun();
	void drawBackGround();
	
private:
	bool day = true;
	bool rain = false;
	RenderWindow* window;
	CircleShape sun;
	int nbDrop = 200;
	int width = 5;
	int height = 10;
	vector<RectangleShape> rainDrop;
	void setRandPos(RectangleShape& rect);
	Clock clock;
	Clock clock2;
	struct colors* c;
	vector<CircleShape> clouds;
	vector<CircleShape> stars;
	Color starColor = Color(253, 245, 1);
};

