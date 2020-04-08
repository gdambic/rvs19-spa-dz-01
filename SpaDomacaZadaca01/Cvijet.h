#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
using namespace std;

class Cvijet {

private:
	sf::RenderWindow *mWindow;

public:
	Cvijet(sf::RenderWindow *window);
	void draw();
};

