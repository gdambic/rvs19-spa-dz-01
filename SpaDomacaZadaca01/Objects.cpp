#include "Objects.h"

vector<RectangleShape> Objects::Tulip(vector<Texture*> texture, float x_offset, float y_offset, int numberOfTulips,int textureNumber)
{


	RectangleShape Tulip(Vector2f(32+y_offset, 32+y_offset));
	Tulip.setOrigin(16, 32);
	Tulip.setTexture(texture[textureNumber]);
	for (int i = 0; i <numberOfTulips; i++)
	{
		tulips.push_back(Tulip);
		tulips[i].setPosition((x - 150+(x_offset*10) )- (i*x_offset),320-30-y_offset);
	}

	return tulips;
}

RectangleShape Objects::Ground(vector<Texture*> texture, int textureNumber)
{

	RectangleShape ground(Vector2f(512, 32));
	ground.setOrigin(512/2, 32);
	ground.setTexture(texture[textureNumber]);
	ground.setPosition(256, 320);

	return ground;
}

RectangleShape Objects::Sky(vector<Texture*> texture, int textureNumber)
{
	RectangleShape sky(Vector2f(512,512));
	sky.setOrigin(256, 256);
	sky.setTexture(texture[textureNumber]);
	sky.setPosition(256, 256);

	return sky;
}

vector<RectangleShape> Objects::Windmill_body(vector<Texture*> texture, float offset, int numberOfMills,int textureNumber)
{
	float temp = offset;
	RectangleShape windmill_body(Vector2f(300, 300));
	windmill_body.setOrigin(150, 300);
	windmill_body.setTexture(texture[textureNumber]);
	for (int i = 0; i < numberOfMills; i++)
	{
		if (!i)
		{
		scene.push_back(windmill_body);
		scene[i].setPosition((x / 2) + (x / 3) , y - 28);
		}
		else
		{
			scene.push_back(windmill_body);
			scene[i].setScale((temp), (temp));
			scene[i].setPosition((x / 2) + (x / 3) - (i * (scene[i].getSize().x/2)), y - 28);
			temp *= temp;
		}
	}
	return scene;
}
