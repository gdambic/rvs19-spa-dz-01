#include "Cvijet.h"
#include <windows.h>

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
}

Cvijet::~Cvijet()
{
}

void Cvijet::draw()
{
	//PRAVOKUTNIK

	sf::RectangleShape line(sf::Vector2f(170, 5));
	line.rotate(90);
	line.setFillColor(sf::Color::Green);
	line.setPosition(330.f, 230.f);
	window->draw(line);

	//KRUGOVI
	latice.push_back(latica(30, sf::Color::Yellow, 300.f, 200.f));
	latice.push_back(latica(18, sf::Color::White, 284.f, 162.f));
	latice.push_back(latica(18, sf::Color::White, 254.f, 210.f));
	latice.push_back(latica(18, sf::Color::White, 284.f, 263.f));
	latice.push_back(latica(18, sf::Color::White, 340.f, 162.f));
	latice.push_back(latica(18, sf::Color::White, 370.f, 210.f));
	latice.push_back(latica(18, sf::Color::White, 340.f, 263.f));
	latice.push_back(latica(18, sf::Color::Red, 312.f, 155.f));
	latice.push_back(latica(18, sf::Color::Red, 362.f, 182.f));
	latice.push_back(latica(18, sf::Color::Red, 362.f, 240.f));
	latice.push_back(latica(18, sf::Color::Red, 312.f, 270.f));
	latice.push_back(latica(18, sf::Color::Red, 262.f, 240.f));
	latice.push_back(latica(18, sf::Color::Red, 263.f, 182.f));

	//GLAVNI KRUG
	latice[0].setOutlineColor(sf::Color::Green);
	latice[0].setOutlineThickness(10.f);

	for (int i = 0; i < latice.size(); i++)
	{
		window->draw(latice[i]);
	}

	sf::Time glavnoVrijemeProvjere = sf::seconds(3);
	sf::Time yVrijeme = globalnoVrijeme.getElapsedTime() - xVrijeme;
	xVrijeme += yVrijeme;

	//Random latica
	randomLatica();

	//Postavljanje latica na pocetnu vrijednost
	postavljanjeLaticaNaPocetnuVrijednost(glavnoVrijemeProvjere);
}

sf::CircleShape Cvijet::latica(int velicina, sf::Color boja, float xPozicija, float yPozicija)
{
	sf::CircleShape globalniKrug(velicina);
	globalniKrug.setFillColor(boja);
	globalniKrug.setPosition(xPozicija, yPozicija);

	return globalniKrug;
}

void Cvijet::randomLatica()
{
	for (int i = 1; i < 13; i++)
	{
		if (i % 2 == 0) {
			latice[rand() % 12 + 1].setFillColor(sf::Color::Red);
		}
		else {
			latice[rand() % 12 + 1].setFillColor(sf::Color::White);
		}
		Sleep(10);
		window->draw(latice[i]);
	}
}

void Cvijet::postavljanjeLaticaNaPocetnuVrijednost(sf::Time glavnoVrijemeProvjere)
{

	if (xVrijeme.asSeconds() > glavnoVrijemeProvjere.asSeconds())
	{
		for (int i = 1; i < 13; i++)
		{
			if (i % 2 == 0) {
				latice[i].setFillColor(sf::Color::White);
			}
			else {
				latice[i].setFillColor(sf::Color::Red);
			}
			window->draw(latice[i]);
		}
		globalnoVrijeme.restart();
	}
}
