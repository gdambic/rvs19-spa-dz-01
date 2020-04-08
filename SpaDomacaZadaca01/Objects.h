#pragma once
#include "Animation.h"

using namespace std;
using namespace sf;

class Objects
{
private:

	vector <RectangleShape> tulips;
	vector <RectangleShape>	scene;
	int x = 512;
	int y =	320;

public:

	vector<RectangleShape> Tulip(vector<Texture*> texture, float x, float y, int numberOfTulips,int textureNumber);
	RectangleShape Ground(vector<Texture*> texture, int textureNumber);
	RectangleShape Sky(vector<Texture*> texture, int textureNumber);
	vector <RectangleShape> Windmill_body(vector<Texture*> texture, float offset, int numberOfMills, int textureNumber);

};

