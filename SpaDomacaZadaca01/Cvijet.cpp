#include "Cvijet.h"
#include <windows.h>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}


void Cvijet::draw()
{
	// Cvijet
	sf::CircleShape cvijet(47);
	cvijet.setFillColor(sf::Color::Cyan);
	cvijet.setOutlineThickness(-8.f);
	cvijet.setOutlineColor(sf::Color::White);
	cvijet.setPosition(283.f, 184.f);
	window->draw(cvijet);



	// Stabljika
	sf::RectangleShape stabljika(sf::Vector2f(200, 5));
	stabljika.rotate(90);
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setPosition(332.f, 300.f);
	window->draw(stabljika);

	//Veliki list 1
	sf::ConvexShape velikiList1;

	velikiList1.setPointCount(5);
	velikiList1.setFillColor(sf::Color::Cyan);
	velikiList1.setPoint(0, sf::Vector2f(0.f, 100.f));
	velikiList1.setPoint(1, sf::Vector2f(150.f, 10.f));
	velikiList1.setPoint(2, sf::Vector2f(120.f, 90.f));
	velikiList1.setPoint(3, sf::Vector2f(30.f, 100.f));
	velikiList1.setPoint(4, sf::Vector2f(0.f, 50.f));

	velikiList1.setPosition(332.f, 310.f);
	window->draw(velikiList1);


	//Veliki list 2
	sf::ConvexShape velikiList2;

	velikiList2.setPointCount(5);
	velikiList2.setFillColor(sf::Color::White);
	velikiList2.setPoint(0, sf::Vector2f(0.f, 100.f));
	velikiList2.setPoint(1, sf::Vector2f(150.f, 10.f));
	velikiList2.setPoint(2, sf::Vector2f(120.f, 90.f));
	velikiList2.setPoint(3, sf::Vector2f(30.f, 100.f));
	velikiList2.setPoint(4, sf::Vector2f(0.f, 50.f));
	velikiList2.rotate(180);
	velikiList2.setPosition(327.f, 455.f);
	window->draw(velikiList2);

	//Mini latice
	latice.push_back(latica(18, sf::Color::White, 284.f, 162.f));
	latice.push_back(latica(18, sf::Color::White, 254.f, 210.f));
	latice.push_back(latica(18, sf::Color::White, 284.f, 263.f));
	latice.push_back(latica(18, sf::Color::White, 340.f, 162.f));
	latice.push_back(latica(18, sf::Color::White, 370.f, 210.f));
	latice.push_back(latica(18, sf::Color::White, 340.f, 263.f));
	latice.push_back(latica(18, sf::Color::Cyan, 312.f, 155.f));
	latice.push_back(latica(18, sf::Color::Cyan, 362.f, 182.f));
	latice.push_back(latica(18, sf::Color::Cyan, 362.f, 240.f));
	latice.push_back(latica(18, sf::Color::Cyan, 312.f, 270.f));
	latice.push_back(latica(18, sf::Color::Cyan, 262.f, 240.f));
	latice.push_back(latica(18, sf::Color::Cyan, 263.f, 182.f));


	for (int i = 0; i < latice.size(); i++)
	{
		window->draw(latice[i]);
	}

	sf::Time glavnoVrijemeProvjere = sf::seconds(3);
	sf::Time yVrijeme = frameClock.getElapsedTime() - xVrijeme;
	xVrijeme += yVrijeme;

	//Promjeni boju
	randomLatica();

	//Vrati na pocetnu boju
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
	for (int i = 0; i < 11; i++)
	{
		if (i % 2 == 0) {
			latice[rand() % 11 + 1].setFillColor(sf::Color::Cyan);
		}
		else {
			latice[rand() % 11 + 1].setFillColor(sf::Color::White);
		}
		Sleep(1);
		window->draw(latice[i]);
	}
}

void Cvijet::postavljanjeLaticaNaPocetnuVrijednost(sf::Time glavnoVrijemeProvjere)
{
	if (xVrijeme.asSeconds() > glavnoVrijemeProvjere.asSeconds())
	{
		for (int i = 0; i < 11; i++)
		{
			if (i % 2 == 0) {
				latice[i].setFillColor(sf::Color::White);
			}
			else {
				latice[i].setFillColor(sf::Color::Cyan);
			}
			window->draw(latice[i]);
		}
		frameClock.restart();
	}
}

