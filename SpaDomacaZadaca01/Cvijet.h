#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>

class Cvijet
{
private:
	//Window
	sf::RenderWindow* window;
	//Latice
	std::vector<sf::CircleShape> heads;
	sf::CircleShape head;
	sf::VertexArray stem1Complete;
	double angle[30];
	int time = 0;
	sf::ConvexShape list;
	void initList();
	void initStem1Complete();
	void initVariables();
	void initHeads();
public:
	//Constructors
	Cvijet(sf::RenderWindow* window);
	~Cvijet();
	void updateHeads();
	void draw();
};

