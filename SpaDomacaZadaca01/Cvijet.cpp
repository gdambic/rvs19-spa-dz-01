#include "Cvijet.h"
#include <cmath>

Cvijet::Cvijet(sf::RenderWindow* win) {
	window = win;

	// Postavi početni radijus i sredinu
	sredina.setRadius(trenutniRadijus);
	sredina.setFillColor(sf::Color::Red);
	sredina.setOrigin(trenutniRadijus, trenutniRadijus);
	sredina.setPosition(400, 300);

	// Latice
	const int brojLatica = 6;
	for (int i = 0; i < brojLatica; ++i) {
		sf::CircleShape latica(25);
		latica.setFillColor(sf::Color::Green);
		latica.setOrigin(25, 25);
		float angle = i * 2 * 3.14159f / brojLatica;
		float x = 400 + std::cos(angle) * 60;
		float y = 300 + std::sin(angle) * 60;
		latica.setPosition(x, y);
		latice.push_back(latica);
	}

	// Stapka
	stapka.setSize(sf::Vector2f(10, 150));
	stapka.setFillColor(sf::Color(0, 100, 0));
	stapka.setOrigin(5, 0);
	stapka.setPosition(400, 330);
}

void Cvijet::draw() {
	// Animacija radijusa (pulsiranje)
	sf::Time elapsed = frameClock.getElapsedTime();
	if (elapsed.asMilliseconds() > 50) {
		if (smanjuje)
			trenutniRadijus -= 0.5;
		else
			trenutniRadijus += 0.5;

		if (trenutniRadijus <= 15)
			smanjuje = false;
		else if (trenutniRadijus >= 20.0)
			smanjuje = true;
		// Latice (s rotacijom)
		const int brojLatica = 6;

		float radius = 60.0;

		for (int i = 0; i < brojLatica; ++i) {

			float angle = kut + i * 2 * 3.14159 / brojLatica;
			float x = 400 + std::cos(angle) * radius;
			float y = 300 + std::sin(angle) * radius;
			latice[i].setPosition(x, y);
		}
		kut += 0.01f; // brzina rotacije 
		if (kut > 2 * 3.14159f)
			kut -= 2 * 3.14159f;

		sredina.setRadius(trenutniRadijus);
		sredina.setOrigin(trenutniRadijus, trenutniRadijus);
		frameClock.restart();
	}

	// Iscrtavanje
	for (const auto& latica : latice)
		window->draw(latica);

	window->draw(sredina);
	window->draw(stapka);
}
