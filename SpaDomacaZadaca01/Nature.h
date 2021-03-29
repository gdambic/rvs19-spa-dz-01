#pragma once
#include <SFML/Graphics.hpp>
#include "Sky.h"
#include "Flower.h"
#include "Butterfly.h"
#include "Grass.h"
#include "Sun.h"
#include "Clouds.h"

using namespace sf;

class Nature
{
public:
	Nature(RenderWindow* window);
	void render();
private:
	RenderWindow* renderWindow;
	Sky sky;
	Flower flower;
	Butterfly butterfly;
	Grass grass;
	Sun sun;
	Clouds clouds;
};

