#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <vector>
#include <ctime>
#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std::chrono;

int gen_rnd(int min,int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	int br = 0;
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(900, 600), "Kuglice");
	sf::Clock zidniSat;
	sf::Texture lopta;
	if (!lopta.loadFromFile("lopta.png"))
	{
		return -1;
	}
	window.setFramerateLimit(60);
	vector<Cvijet> k;
	Cvijet cvijeto(window,lopta);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && br>=10) //Ako je stisnut lijevi klik na misu, uzeti koordinate i stvoriti objekt loptice na tom mjestu
		{
			sf::Vector2i position = sf::Mouse::getPosition(window);

			k.emplace_back(position.x, position.y, (double)gen_rnd(10, 14) / 30,lopta);
			br = 0;
		}

		window.clear();
		cvijeto.draw(window);
		cvijeto.drawSunce(zidniSat,window);
		for (auto it = k.begin(); it != k.end();) {

			(* it).update();
			(* it).drawKrug(window);
			if ((*it).trebaUnistiti()) {
				it = k.erase(it);
			}
			else {
				++it;
			}

		}
		window.display();
		br++;

	}

	return 0;
}