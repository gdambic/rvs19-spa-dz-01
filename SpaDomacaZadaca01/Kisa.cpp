#include "Kisa.h"

Kisa::Kisa(sf::RenderWindow* window)
{
	this->window = window;

	srand(std::time(0));
	for (int i = 0; i < 200; i++) {
		sf::RectangleShape kapljica(sf::Vector2f((rand() % 15) / 10.f + 1, (rand() % 500) / 10.f + 3));
		kapljica.setFillColor(sf::Color(0, 0, 255, 128));
		kisa.push_back(kapljica);
		kisa[i].setPosition(sf::Vector2f(rand() % 1600, rand() % 900));
		kapljicaSpeed.push_back((kisa[i].getSize().x) * kisa[i].getSize().x);
	}
}

void Kisa::draw(int noc)
{
	if (noc != 150)
	{
		for (int i = 0; i < kisa.size(); i++) {
			if (kisa[i].getPosition().y <= 900)
				kisa[i].setPosition(kisa[i].getPosition().x, kisa[i].getPosition().y + kapljicaSpeed[i] + spd);
			else {
				kisa[i].setPosition(kisa[i].getPosition().x, -40);
			}
			window->draw(kisa[i]);
		}
	}
}
