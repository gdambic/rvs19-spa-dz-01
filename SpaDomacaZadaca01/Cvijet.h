#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow * window);
	void draw();
private:
	void init_shapes();
	vector<Shape*> shapes;
	RenderWindow *window;
};