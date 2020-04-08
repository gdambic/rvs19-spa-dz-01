#pragma once
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include<thread>
#include<chrono> // includushe

using namespace sf;
using namespace std::chrono_literals;
using std::chrono::system_clock;

class Cvijet 
{
public:

	Cvijet(RenderWindow* window); // Konstruktor objekta Cvijet, prima adresu prozora
	void draw(); // Javna funkcija za iscrtavanje cvijeta i animacije

private:

	RenderWindow* theWindow; // prozor
	CircleShape flowerCircle{}; // cvijet
	ConvexShape flowerLeafOne{}; // list 1
	ConvexShape flowerLeafTwo{}; // list 2
	RectangleShape flowerPlant{ Vector2f(200.f, 15.f) }; // stabiljka + set
	CircleShape sun{}; // sunce
};
