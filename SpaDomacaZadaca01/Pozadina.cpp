#include <random>
#include <functional>
#include "Pozadina.h"

Pozadina::Pozadina(sf::RenderWindow* window)
{
	this->window = window;

	auto rndx = std::bind(std::normal_distribution<>(0, 1600), std::default_random_engine());
	auto rndy = std::bind(std::uniform_int_distribution<>(0, 400), std::default_random_engine());
	for (int i = 0; i < 100; i++) {
		zvjezde_lokacija[i] = sf::Vector2f(rndx(), rndy());
	}
}

void Pozadina::draw()
{
	drawPozadina();
	drawZvijezde();
}

void Pozadina::drawPozadina()
{
	sf::VertexArray pozadina(sf::TriangleStrip, 6);

	//pozicija
	pozadina[0].position = sf::Vector2f(0.f, 0.f);	//gore ljevo
	pozadina[1].position = sf::Vector2f(0.f, 900.f);//dolje ljevo
	pozadina[2].position = sf::Vector2f(800.f, 0.f);//gore centar
	pozadina[3].position = sf::Vector2f(800.f, 900.f);//dole centar
	pozadina[4].position = sf::Vector2f(1600.f, 0.f);//gore desno
	pozadina[5].position = sf::Vector2f(1600.f, 900.f);//dolje desno

	// boja
	pozadina[0].color = sf::Color(k / 4, k / 4, 0);
	pozadina[1].color = sf::Color(0, 0, noc / 2 - 40);
	pozadina[2].color = sf::Color(j / 2, j / 2, 0);
	pozadina[3].color = sf::Color(0, 0, noc / 2 - 40);
	pozadina[4].color = sf::Color(i / 4, i / 4, 0);
	pozadina[5].color = sf::Color(h / 2, h / 2, noc / 2 - h / 2);

	if (k > 512)
		j++;
	else if (j != 0)
		j--;

	if (i > 512 and h != 511)
		h++;
	else if (i == 0 and h != 0) 
		h--;
	else if (h == 0 and i == 0 and noc != 150)
		noc--;

	if (k == 0 and i != 0) {
		i--;
	}
	else if (i != 0) {
		i++;
		k--;
	}
	window->draw(pozadina);
}

void Pozadina::drawZvijezde()
{
	for (int z = 0; z < 100; z++)
	{
		sf::CircleShape zvjezda(5);
		zvjezda.setPosition(zvjezde_lokacija[z]);
		zvjezda.setFillColor(sf::Color(255, 255, 255, (noc / 2 * -1) + 255));
		window->draw(zvjezda);
	}
}


int Pozadina::getNoc()
{
	return noc;
}
