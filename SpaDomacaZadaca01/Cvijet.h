#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>






class Cvijet 
{
private:
    sf::Clock frameClock;
	sf::RenderWindow* window;
	

	

public:
	Cvijet(sf::RenderWindow* window);
	void draw();
	void drawSunce();

};

