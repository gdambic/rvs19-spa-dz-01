#include "Cvijet.h"
#define PI   3.14159265358979323846264338327950288
#define degToRad(input) ((input) * PI / 180.0)

Cvijet::Cvijet(sf::RenderWindow* window) {
	this->window = window;
	nKockast = 0;
	kKockast = 0;
	cKockast = 2;
	nKruzic = 0;
	kKruzic = 0;
	cKruzic = 4;
	nRuza = 0;
	kRuza = 0;
	cRuza = 3;
}

void Cvijet::draw()
{
	//kad se stabljika nacrta onda gre cvijet
	if (kKockast < 500)
	{
		drawStabljikaKockast();
	}
	else if (nKockast < 512)
	{
		drawCvijetKockast();
	}

	if (kKruzic < 550)
	{
		drawStabljikaKruzic();
	}
	else if (nKruzic < 512)
	{
		drawCvijetKruzic();
	}

	if (kRuza < 500)
	{
		drawStabljikaRuza();
	}
	else if (nRuza < 512)
	{
		drawCvijetRuza();
	}

	for (auto it = stabljikaKockast.begin(); it != stabljikaKockast.end(); ++it)
	{
		window->draw(*it);
	}
	for (auto it = laticeKockast.begin(); it != laticeKockast.end(); ++it)
	{
		window->draw(*it);
	}

	for (auto it = stabljikaKruzic.begin(); it != stabljikaKruzic.end(); ++it)
	{
		window->draw(*it);
	}
	for (auto it = laticeKruzic.begin(); it != laticeKruzic.end(); ++it)
	{
		window->draw(*it);
	}

	for (auto it = stabljikaRuza.begin(); it != stabljikaRuza.end(); ++it)
	{
		window->draw(*it);
	}
	for (auto it = laticeRuza.begin(); it != laticeRuza.end(); ++it)
	{
		window->draw(*it);
	}

}

void Cvijet::drawStabljikaKockast()
{
	sf::Vector2f pos((1600 / 4) - 5, 900 - kKockast);
	sf::CircleShape cvijet(8);
	cvijet.setPosition(pos);
	cvijet.setFillColor(sf::Color(0, fmod(kKockast / 2, 256), 0));
	stabljikaKockast.push_back(cvijet);
	kKockast += 1;
}

void Cvijet::drawCvijetKockast() {

	double a = nKockast * 137.6;
	double r = cKockast * sqrt(nKockast);
	double x = r * cos(degToRad(a));
	double y = r * sin(degToRad(a));
	sf::Vector2f pos(x + 1600 / 4, y + 800 / 2);
	sf::Vector2f size(5 * cKockast, 5 * cKockast);
	sf::RectangleShape cvijet(size);
	cvijet.setPosition(pos);
	if (nKockast <= 255)
	{
		cvijet.setFillColor(sf::Color(fmod(nKockast / 2, 128) + 128, fmod(nKockast / 2, 128) + 128, 0));
	}
	else
	{
		cvijet.setFillColor(sf::Color(fmod(nKockast / 2, 128) + 128, 0, fmod(nKockast / 2, 128) + 128));
	}
	cKockast += 0.005;
	nKockast += 1;
	laticeKockast.push_back(cvijet);
}

void Cvijet::drawStabljikaKruzic() {
	sf::Vector2f pos((1600 / 2) - 5, 900 - kKruzic);
	sf::CircleShape cvijet(12);
	cvijet.setPosition(pos);
	cvijet.setFillColor(sf::Color(0, fmod(kKruzic / 3, 256)+20, 0));
	stabljikaKruzic.push_back(cvijet);
	kKruzic += 1;
}

void Cvijet::drawCvijetKruzic() {
	double a = nKruzic * 137.5;
	double r = cKruzic * sqrt(nKruzic);
	double x = r * cos(degToRad(a));
	double y = r * sin(degToRad(a));
	sf::Vector2f pos(x + 1600 / 2, y + 700 / 2);
	sf::CircleShape cvijet(5);
	cvijet.setPosition(pos);
	if (nKruzic <= 255)
	{
		cvijet.setFillColor(sf::Color(fmod(nKruzic / 2, 128) + 128, fmod(nKruzic / 2, 128) + 128, 0));
	}
	else
	{
		cvijet.setFillColor(sf::Color(fmod(nKruzic / 2, 128) + 128, 0, 0));
	}
	nKruzic += 1;
	laticeKruzic.push_back(cvijet);
}

void Cvijet::drawStabljikaRuza() {
	sf::Vector2f pos((1200) - 5, 900 - kRuza);
	sf::CircleShape cvijet(10);
	cvijet.setPosition(pos);
	cvijet.setFillColor(sf::Color(0, fmod(kRuza / 2, 256), 0));
	stabljikaRuza.push_back(cvijet);
	kRuza += 1;
}

void Cvijet::drawCvijetRuza() {
	double a = nRuza * 137.5;
	double r = cRuza * sqrt(nRuza);
	double x = r * cos(degToRad(a));
	double y = r * sin(degToRad(a));
	sf::Vector2f pos(x + 1200, y + 800 / 2);
	sf::CircleShape cvijet(4);
	cvijet.setPosition(pos);
	cvijet.setFillColor(sf::Color(fmod(nRuza, 128) + 64, 0, 0));
	nRuza += 1;
	laticeRuza.push_back(cvijet);
}