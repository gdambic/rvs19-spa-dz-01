#pragma once
#include <SFML/Graphics.hpp>

class Cvijet
{
private:
	
	
	

	sf::RenderWindow* window;
	float radius;
	float scaling;
    sf::RectangleShape line;
	sf::Color line_Color;
	sf::Vector2f middlePoint;
	
	sf::CircleShape bud;
	sf::CircleShape petalOne;
	sf::CircleShape petalTwo;
	sf::CircleShape petalThree;

	float size;
	float degree;
	sf::Color colour;
	bool stepOne;
	bool stepTwo;
	bool stepThree;
	bool stepFinal;

public:
	Cvijet();
	Cvijet(sf::RenderWindow* window);
	void draw();
	
	void set_degree(float degree);
	float get_degree();


};

