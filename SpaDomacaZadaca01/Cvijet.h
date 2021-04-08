#pragma once
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::Clock globalnoVrijeme;
	sf::Time xVrijeme = globalnoVrijeme.getElapsedTime();
	std::vector<sf::CircleShape> latice;
public:
	Cvijet(sf::RenderWindow* window);
	void draw();

	sf::CircleShape latica(int velicina, sf::Color boja, float xPozicija, float yPozicija);
	void randomLatica();
	void postavljanjeLaticaNaPocetnuVrijednost(sf::Time glavnoVrijemeProvjere);
};