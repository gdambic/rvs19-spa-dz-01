#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;
class Cvijet
{
private:
	RenderWindow* window;
	vector<CircleShape> circle;
	double n, c;
	int count;
	double sunX;
	double sunY;
	double sunRadius;
	double sunMovementY;
public:
	Cvijet(RenderWindow* window);
	void draw();
};

