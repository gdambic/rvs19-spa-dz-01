#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <fstream>
#include <thread>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace sf;

class Cvijet
{
private:
	RenderWindow* w;
	Sprite* pozadina;
	Sprite* cvijet_glava;
	Sprite* cvijet_baza;
public:
	Cvijet(RenderWindow* w, Sprite* pozadina, Sprite* cvijet_glava, Sprite* cvijet_baza);
	void draw();
	void frejm(float pomak_x, float pomak_y, VertexArray stabljika);
};

