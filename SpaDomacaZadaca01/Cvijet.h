#pragma once
#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<cmath>
using namespace std;

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock Clock;
	sf::Time Time;
	sf::Texture TexMoon;
	sf::Texture TexPrince;
	sf::Texture TexBackground;
	sf::Texture TexFlower;
	sf::Texture TexStem;
	sf::RectangleShape Background;
	sf::RectangleShape Prince;
	sf::RectangleShape Stem;
	sf::CircleShape Moon;
	sf::CircleShape Circle;
	sf::CircleShape Flower;

public:
	Cvijet(sf::RenderWindow* window);
	void set_Background();
	void set_Moon();
	void set_Circle();
	void set_Prince();
	void set_Flower();
	void set_Stem();
	void draw();
	
};

