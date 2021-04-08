#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock frameClock;
	sf::Time xVrijeme = frameClock.getElapsedTime();
	std::vector<sf::CircleShape> latice;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();

	sf::CircleShape latica(int velicina, sf::Color boja, float xPozicija, float yPozicija);
	void randomLatica();
	void postavljanjeLaticaNaPocetnuVrijednost(sf::Time glavnoVrijemeProvjere);
};