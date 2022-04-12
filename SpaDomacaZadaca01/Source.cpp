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

int main(){
	int br = 0;
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(1600, 600),"Kuglice");
	window.setFramerateLimit(60);
	vector<Cvijet> k;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		/*for (int i = 0; i < 30; i++)
		{
			Cvijet c(window, 50 + 50 * i, gen_rnd(i, 100),(double)(i)/30);
			k.push_back(c);
		}*/

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && br>=20)
		{
			sf::Vector2i position = sf::Mouse::getPosition(window);

			k.emplace_back(window, position.x, position.y, (double)gen_rnd(10, 20) / 30);
			br = 0;
		}

		window.clear();
		/*for (int i=0;i<k.size();i++)
		{
			k[i].update();
			k[i].draw();
			if (k[i].trebaUnistiti()) {
				k.erase(k.begin() + i);
			}
		}*/

		for (auto it = k.begin(); it != k.end();) {

			(* it).update();
			(* it).draw();
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