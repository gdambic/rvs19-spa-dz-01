#pragma once
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

struct Tocka {
	float x, y;

	Tocka() {
		x = 0;
		y = 0;
	}

	Tocka(float _x, float _y) {
		x = _x;
		y = _y;
	}
};

class Cvijet {

private:
	std::vector<Tocka> tocka_latica1;
	std::vector<Tocka> tocka_latica2;
	std::vector<Tocka> tocka_latica3;
	std::vector<Tocka> tocka_latica4;
	std::vector<Tocka> tocka_stabljika;
	std::vector<Tocka> tocka_listL;
	std::vector<Tocka> tocka_listR;
	
	sf::ConvexShape shape_latica1;
	sf::ConvexShape shape_latica2;
	sf::ConvexShape shape_latica3;
	sf::ConvexShape shape_latica4;
	sf::ConvexShape shape_stabljika;
	sf::ConvexShape shape_listL;
	sf::ConvexShape shape_listR;

	sf::Color boja_latica1;
	sf::Color boja_latica2;
	sf::Color boja_latica3;
	sf::Color boja_latica4;
	sf::Color boja_stabljika;
	sf::Color boja_listL;
	sf::Color boja_listR;

	sf::RenderWindow* window;
	
public:
	Cvijet(sf::RenderWindow* _window) {
		window = _window;
	}

	void InicijalizirajKoordinate();
	void InicijalizirajBoje();

	Tocka IzracunajAnimaciju(int x, int y, float min_swing, float swing_step, int swing_cutoff, sf::Time vrijeme);

	void draw(sf::Time vrijeme);
	void Animacija(sf::Time vrijeme);
};

