#pragma once 
#include <SFML/Graphics.hpp> 
#include <chrono> 
#include <ctime> 
using namespace std; 

class Cvijet
{ 
private: 
	sf::RenderWindow* w; 
	sf::Clock frameClock_;
	sf::CircleShape sunce; 
public: 
	Cvijet(sf::RenderWindow* window); 
	void nacrtajcvijet(); 

}; 

