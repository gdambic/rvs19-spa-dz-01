#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Cvijet
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Shape*> shapes;
	void initShapes();
	sf::Clock frameClock;

public:
	//CONSTRUCTOR
	Cvijet(sf::RenderWindow* window);
	
	//DESTRCTOR
	~Cvijet();
	void draw();



};

