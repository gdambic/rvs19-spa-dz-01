#pragma once
#include <SFML/Graphics.hpp>
class cvijet
{
	sf::RenderWindow* window; 
	sf::Clock clock; 
public :
	void draw();
	void draw_latice(); 
	void draw_noga(); 
	void draw_sunce(); 
	void draw_background(); 
	 
	cvijet(sf::RenderWindow* window);

};

