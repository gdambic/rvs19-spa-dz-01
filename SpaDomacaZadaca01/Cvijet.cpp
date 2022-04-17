#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp> // library za window
#include<SFML/System.hpp> // sistemski SFML library
#include <ctime>
#include <thread>
using namespace std;
using namespace sf;


//CircleShape head, mouth, eye1, eye2;

Cvijet::Cvijet(sf::RenderWindow& window)
{

	sunce.setPosition(Vector2f(0.f, 0.f));
	sunce.setRadius(30);
	sunce.setFillColor(Color::Yellow);

	//zemlja
	ground.setPosition(Vector2f(0.f, 400.f));
	ground.setSize(Vector2f(800.f, 400.f));
	ground.setFillColor(Color(139, 69, 19));

	
	//stabljika
	rectangle.setPosition(Vector2f(398.f, 250.f));
	rectangle.setSize(Vector2f(6.f, 150.f));
	rectangle.setFillColor(Color(0, 100, 0));

	//glava cvijeta
	head.setPosition(Vector2f(350.f, 150.f));
	head.setRadius(50.f);
	head.setFillColor(Color::Yellow);
	head.setOutlineThickness(10);
	head.setOutlineColor(Color::White);

	//cvijet sredina 1
	cc1.setPosition(Vector2f(386.f, 187.f));
	cc1.setRadius(15.f);
	cc1.setFillColor(Color(255, 216, 255));

	//2
	cc2.setPosition(Vector2f(374.f, 174.f));
	cc2.setRadius(11.f);
	cc2.setFillColor(Color(255, 216, 255));
	
	//3
	cc3.setPosition(Vector2f(394.f, 167.f));
	cc3.setRadius(11.f);
	cc3.setFillColor(Color(255, 216, 255));

	//4
	cc4.setPosition(Vector2f(396.f, 214.f));
	cc4.setRadius(11.f);
	cc4.setFillColor(Color(255, 216, 255));

	//5
	cc5.setPosition(Vector2f(411.f, 180.f));
	cc5.setRadius(11.f);
	cc5.setFillColor(Color(255, 216, 255));

	//6
	cc6.setPosition(Vector2f(365.f, 193.f));
	cc6.setRadius(11.f);
	cc6.setFillColor(Color(255, 216, 255));

	//7
	cc7.setPosition(Vector2f(375.f, 210.f));
	cc7.setRadius(11.f);
	cc7.setFillColor(Color(255, 216, 255));

	//8
	cc8.setPosition(Vector2f(413.f, 200.f));
	cc8.setRadius(11.f);
	cc8.setFillColor(Color(255, 216, 255));
}

void Cvijet::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(rectangle);
	window.draw(head);
	window.draw(cc1);
	window.draw(cc2);
	window.draw(cc3);
	window.draw(cc4);
	window.draw(cc5);
	window.draw(cc6);
	window.draw(cc7);
	window.draw(cc8);
	window.draw(ground);
	window.draw(sunce);
}

void Cvijet::animacija(Clock& clock, Clock& clock2, Clock& clock3)
{


		if (clock.getElapsedTime().asSeconds() > 1) {
			sunce.setPosition(Vector2f(50, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 2) {
			sunce.setPosition(Vector2f(100, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 3) {
			sunce.setPosition(Vector2f(150, 0));
		}
		if(clock.getElapsedTime().asSeconds() > 4) {
			sunce.setPosition(Vector2f(200,0));
			sunce.setRadius(35);
		}
		if (clock.getElapsedTime().asSeconds() > 5) {
			sunce.setPosition(Vector2f(250, 0));
			sunce.setRadius(40);
		}
		if (clock.getElapsedTime().asSeconds() > 6) {
			sunce.setPosition(Vector2f(300, 0));
			sunce.setRadius(45);

		if (clock.getElapsedTime().asSeconds() > 7) {
			sunce.setPosition(Vector2f(350, 0));
			sunce.setRadius(45);
		}
		if (clock.getElapsedTime().asSeconds() > 8) {
			sunce.setPosition(Vector2f(400, 0));
			sunce.setRadius(40);
		}
		if (clock.getElapsedTime().asSeconds() > 9) {
			sunce.setPosition(Vector2f(450, 0));
			sunce.setRadius(35);
		}
		if (clock.getElapsedTime().asSeconds() > 10) {
			sunce.setPosition(Vector2f(500, 0));
			sunce.setRadius(30);
		}
		if (clock.getElapsedTime().asSeconds() > 11) {
			sunce.setPosition(Vector2f(550, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 12) {
			sunce.setPosition(Vector2f(600, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 13) {
			sunce.setPosition(Vector2f(650, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 14) {
			sunce.setPosition(Vector2f(700, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 15) {
			sunce.setPosition(Vector2f(750, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 16) {
			sunce.setPosition(Vector2f(800, 0));
		}
		if (clock.getElapsedTime().asSeconds() > 17) {
			sunce.setPosition(Vector2f(0, 0));
			clock.restart();
		}
	}

		if (clock2.getElapsedTime().asSeconds() > 3)
		{
			cc1.setFillColor(Color(255, 137, 255));
			cc2.setFillColor(Color(255, 137, 255));
			cc3.setFillColor(Color(255, 137, 255));
			cc4.setFillColor(Color(255, 137, 255));
			cc5.setFillColor(Color(255, 137, 255));
			cc6.setFillColor(Color(255, 137, 255));
			cc7.setFillColor(Color(255, 137, 255));
			cc8.setFillColor(Color(255, 137, 255));
		}
		if (clock2.getElapsedTime().asSeconds() > 5)
		{
			cc1.setFillColor(Color(255, 0, 255));
			cc2.setFillColor(Color(255, 0, 255));
			cc3.setFillColor(Color(255, 0, 255));
			cc4.setFillColor(Color(255, 0, 255));
			cc5.setFillColor(Color(255, 0, 255));
			cc6.setFillColor(Color(255, 0, 255));
			cc7.setFillColor(Color(255, 0, 255));
			cc8.setFillColor(Color(255, 0, 255));
		}
		if (clock2.getElapsedTime().asSeconds() > 7)
		{
			cc1.setFillColor(Color(137, 0, 137));
			cc2.setFillColor(Color(137, 0, 137));
			cc3.setFillColor(Color(137, 0, 137));
			cc4.setFillColor(Color(137, 0, 137));
			cc5.setFillColor(Color(137, 0, 137));
			cc6.setFillColor(Color(137, 0, 137));
			cc7.setFillColor(Color(137, 0, 137));
			cc8.setFillColor(Color(137, 0, 137));
		}
		if (clock2.getElapsedTime().asSeconds() > 9)
		{
			cc1.setFillColor(Color(59, 0, 59));
			cc2.setFillColor(Color(59, 0, 59));
			cc3.setFillColor(Color(59, 0, 59));
			cc4.setFillColor(Color(59, 0, 59));
			cc5.setFillColor(Color(59, 0, 59));
			cc6.setFillColor(Color(59, 0, 59));
			cc7.setFillColor(Color(59, 0, 59));
			cc8.setFillColor(Color(59, 0, 59));
		}
		if (clock2.getElapsedTime().asSeconds() > 11)
		{
			cc1.setFillColor(Color(137, 0, 137));
			cc2.setFillColor(Color(137, 0, 137));
			cc3.setFillColor(Color(137, 0, 137));
			cc4.setFillColor(Color(137, 0, 137));
			cc5.setFillColor(Color(137, 0, 137));
			cc6.setFillColor(Color(137, 0, 137));
			cc7.setFillColor(Color(137, 0, 137));
			cc8.setFillColor(Color(137, 0, 137));
		}
		if (clock2.getElapsedTime().asSeconds() > 13)
		{
			cc1.setFillColor(Color(255, 0, 255));
			cc2.setFillColor(Color(255, 0, 255));
			cc3.setFillColor(Color(255, 0, 255));
			cc4.setFillColor(Color(255, 0, 255));
			cc5.setFillColor(Color(255, 0, 255));
			cc6.setFillColor(Color(255, 0, 255));
			cc7.setFillColor(Color(255, 0, 255));
			cc8.setFillColor(Color(255, 0, 255));
		}
		if (clock2.getElapsedTime().asSeconds() > 15)
		{
			cc1.setFillColor(Color(255, 137, 255));
			cc2.setFillColor(Color(255, 137, 255));
			cc3.setFillColor(Color(255, 137, 255));
			cc4.setFillColor(Color(255, 137, 255));
			cc5.setFillColor(Color(255, 137, 255));
			cc6.setFillColor(Color(255, 137, 255));
			cc7.setFillColor(Color(255, 137, 255));
			cc8.setFillColor(Color(255, 137, 255));
		}
		if (clock2.getElapsedTime().asSeconds() > 17)
		{
			cc1.setFillColor(Color(255, 216, 255));
			cc2.setFillColor(Color(255, 216, 255));
			cc3.setFillColor(Color(255, 216, 255));
			cc4.setFillColor(Color(255, 216, 255));
			cc5.setFillColor(Color(255, 216, 255));
			cc6.setFillColor(Color(255, 216, 255));
			cc7.setFillColor(Color(255, 216, 255));
			cc8.setFillColor(Color(255, 216, 255));
			clock2.restart();
		}
}
