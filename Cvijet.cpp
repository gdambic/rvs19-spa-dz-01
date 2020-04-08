#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Cvijet.h"

using namespace std;

Cvijet::Cvijet(RenderWindow* window) : theWindow(window)
{ // this->theWindow = window
}

void Cvijet::draw() 
{
	// glava cvijeta
	flowerCircle.setRadius(30.f);
	flowerCircle.setOrigin(30.f, 30.f);
	flowerCircle.setPosition(335.f, 225.f);
	flowerCircle.setFillColor(Color::Yellow);
	flowerCircle.setOutlineThickness(95.f);
	flowerCircle.setOutlineColor(Color::Red);
	flowerCircle.setPointCount(100);

	// stabiljka
	flowerPlant.setPosition(340.f, 350.f);
	flowerPlant.setRotation(90.f);
	flowerPlant.setFillColor(Color::Green);

	// list desni
	flowerLeafOne.setPointCount(4);
	flowerLeafOne.setPoint(0, Vector2f(340.f, 450.f));
	flowerLeafOne.setPoint(1, Vector2f(450.f, 400.f));
	flowerLeafOne.setPoint(2, Vector2f(570.f, 400.f));
	flowerLeafOne.setPoint(3, Vector2f(460.f, 470.f));	
	flowerLeafOne.setFillColor(Color::Green);

	// list lijevi
	flowerLeafTwo.setPointCount(3);
	flowerLeafTwo.setPoint(0, Vector2f(330.f, 440.f));
	flowerLeafTwo.setPoint(1, Vector2f(180.f, 450.f));
	flowerLeafTwo.setPoint(2, Vector2f(160.f, 330.f));
	flowerLeafTwo.setFillColor(Color::Green);

	// sunce

	sun.setRadius(15.f);
	sun.setPosition(45.f, 25.f);
	sun.setFillColor(Color::Yellow);
	
	theWindow->draw(sun);
	theWindow->draw(flowerPlant);
	theWindow->draw(flowerCircle);
	theWindow->draw(flowerLeafOne);
	theWindow->draw(flowerLeafTwo);

	// animacija izlazeceg sunca

	int counter = 0;
	while (counter < 20)
	{
		sun.setRadius(15 + counter);
		sun.setPosition(45 + (counter*2), 25);
		sun.setFillColor(Color(255,(150+counter*2),0));
		theWindow->draw(sun);
		theWindow->draw(flowerPlant);
		theWindow->draw(flowerCircle);
		theWindow->draw(flowerLeafOne);
		theWindow->draw(flowerLeafTwo);
		theWindow->display();
		std::this_thread::sleep_until(system_clock::now() + 0.3s);
		theWindow->clear();
		counter++;
	}
}
