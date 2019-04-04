#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Vertex.hpp>


using namespace std;
using namespace sf;

class Cvijet
{
private:
	RenderWindow* w;
public:
	Cvijet(RenderWindow* w);
	void draw();
};

