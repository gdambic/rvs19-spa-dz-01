#include "Cvijet.h"

Cvijet::Cvijet
(sf::RenderWindow& w) : window(w) {
	//centar
	center.setRadius(20.f);
	center.setFillColor(sf::Color::Yellow);
	center.setPosition(295.f, 195.f);
	//latice 1
	petal1.setRadius(15.f);
	petal1.setFillColor(sf::Color::Magenta);
	petal1.setPosition(280.f, 180.f);

	petal2 = petal1;
	petal2.setPosition(320.f, 180.f);

	petal3 = petal1;
	petal3.setPosition(280.f, 220.f);

	petal4 = petal1;
	petal4.setPosition(320.f, 220.f);

	//stabiljka
	stem.setSize(sf::Vector2f(10.f, 100.f));
	stem.setFillColor(sf::Color::Green);
	stem.setPosition(310.f, 240.f);

	//sunce
	sun.setRadius(sunRadius);
	sun.setFillColor(sf::Color::Yellow);
	sun.setPosition(50.f, 50.f);
}
void Cvijet::draw() {
	float dt = frameClock.restart().asSeconds();
	float speed = 10.f;
	if (sunShrinking) {
		sunRadius -= speed * dt;
		if (sunRadius <= 15.f) {
			sunRadius = 15.f;
			sunShrinking = false;
		}
	}
	else {
		sunRadius += speed * dt;
		if (sunRadius >= 20.f) {
			sunRadius = 20.f;
			sunShrinking = true;
		}
	}
	sun.setRadius(sunRadius);

	sun.setOrigin(sunRadius, sunRadius);
	sun.setPosition(80.f, 80.f);
	
	
	
	window.draw(stem);
	window.draw(petal1);
	window.draw(petal2);
	window.draw(petal3);
	window.draw(petal4);
	window.draw(center);
	window.draw(sun);



}