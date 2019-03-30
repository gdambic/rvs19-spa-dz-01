#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet
{

public:
	Cvijet(sf::RenderWindow *window);
	~Cvijet();
	void draw();
	sf::CircleShape latica(int velicina, sf::Color boja, float xPozicija, float yPozicija);
	void randomLatica();
	void postavljanjeLaticaNaPocetnuVrijednost(sf::Time glavnoVrijemeProvjere);

private:
	sf::RenderWindow *window;
	std::vector<sf::CircleShape> latice;
	sf::Clock globalnoVrijeme;
	sf::Time xVrijeme = globalnoVrijeme.getElapsedTime();
};


