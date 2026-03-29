#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class Cvijet
{
private:
	//Base varijable
	sf::RenderWindow* window; 
	sf::CircleShape flowerPod;
	sf::Texture flowerPodTexture;
	sf::RectangleShape flowerPetals;
	sf::Texture flowerPetalsTexture;
	sf::RectangleShape flowerStem;
	sf::Texture flowerStemTexture;
	sf::RectangleShape background;
	sf::Texture backgroundTexture;
	sf::RectangleShape bee;
	sf::Texture beeTexture;

	//Varijable za animaciju odnosno stanje pcele
	float beeX, beeBaseY, beeSpeed, beeAmplitude, beeFrequency, beePhase;
	sf::Clock frameClock;

public:
	//Konstruktor
	Cvijet(sf::RenderWindow* window);
	//Metode za postavljanje velicina, tekstura itd namjestavanje raznih shapeova
	void setFlowerPod();
	void setFlowerPetals();
	void setFlowerStem();
	void setBackground();
	void setBee();
	//Metoda za crtanje shapeova i animacije
	void draw();
};

