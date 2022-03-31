#pragma once

#include <SFML/Graphics.hpp>

class Cvijet
{
public:
	Cvijet(RenderWindow* windowAdress);
	void set_windowAdress(RenderWindow windowAdress);

private:
	RenderWindow windowAdress;
};

