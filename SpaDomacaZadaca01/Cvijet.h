#pragma once 
#include <SFML/Graphics.hpp> 
#include <chrono> 
#include <ctime> 
using namespace std; 

class Cvijet
{ 
private: 
	sf::RenderWindow* w; 
public: 
	Cvijet(sf::RenderWindow* window); 
	void nacrtajcvijet(); 

}; 

