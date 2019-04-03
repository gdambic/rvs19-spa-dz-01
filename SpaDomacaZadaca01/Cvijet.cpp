#include "Cvijet.h"
using namespace sf;


Cvijet::Cvijet(RenderWindow* prozor)
{
	this->prozor = prozor;
}

void Cvijet::draw()
{
	//NAMJESTANJE LIKOVA
	pozadina_setup();
	latice1_setup();
	latice2_setup();
	stabiljka_setup();
	sjemenka_setup();
	trava_setup();

	//CRTANJE NA PROZOR
	//pozadina
	prozor->draw(pozadina);
	//stabiljka i latice
	prozor->draw(stabiljka);
	prozor->draw(latice1);
	prozor->draw(latice2);
	//4 sjemenke na sredini cvijeta
	prozor->draw(sjemenka);
	sjemenka.setPosition(358, 237);
	prozor->draw(sjemenka);
	sjemenka.setPosition(309, 282);
	prozor->draw(sjemenka);
	sjemenka.setPosition(358, 282);
	prozor->draw(sjemenka);
	//trava
	prozor->draw(trava);
	//lopta
	//Slika lopte je open source
	slika_lopte.loadFromFile("lopta.png");
	if (!slika_lopte.loadFromFile("lopta.png")) {
		lopta.setColor(Color::White);
	}
	lopta.setTexture(slika_lopte);
	lopta.setPosition(604, visina_lopte);

	//ANIMACIJA
		if (sat.getElapsedTime() >= milliseconds(10) && !provjera_visine) {
			prozor->draw(lopta);
			visina_lopte -= 2;
			lopta.move(604, visina_lopte);
			if (visina_lopte == 100) {
				provjera_visine = true;
			}
			sat.restart();
	}
		if (sat.getElapsedTime() >= milliseconds(10) && provjera_visine) {
			prozor->draw(lopta);
			visina_lopte += 2;
			lopta.move(604, visina_lopte);
			if (visina_lopte == 434) {
				provjera_visine = false;
			}
			sat.restart();
		}
}

void Cvijet::pozadina_setup()
{
	pozadina.setFillColor(Color(79, 150, 255));
	pozadina.setSize(Vector2f(800, 600));
	pozadina.setPosition(Vector2f(0, 0));
}

Cvijet::Cvijet() {}

void Cvijet::latice1_setup()
{
	latice1.setFillColor(Color(210, 82, 127));
	latice1.setPointCount(16);
	latice1.setPoint(0, Vector2f(336, 86));
	latice1.setPoint(1, Vector2f(337, 86));
	latice1.setPoint(2, Vector2f(375, 204));
	latice1.setPoint(3, Vector2f(375, 205));
	latice1.setPoint(4, Vector2f(501, 205));
	latice1.setPoint(5, Vector2f(399, 279));
	latice1.setPoint(6, Vector2f(399, 280));
	latice1.setPoint(7, Vector2f(438, 398));
	latice1.setPoint(8, Vector2f(337, 324));
	latice1.setPoint(9, Vector2f(336, 324));
	latice1.setPoint(10, Vector2f(235, 398));
	latice1.setPoint(11, Vector2f(274, 280));
	latice1.setPoint(12, Vector2f(274, 279));
	latice1.setPoint(13, Vector2f(173, 205));
	latice1.setPoint(14, Vector2f(297, 205));
	latice1.setPoint(15, Vector2f(298, 204));
}

void Cvijet::latice2_setup()
{
	latice2.setFillColor(Color(191, 85, 236));
	latice2.setPointCount(17);
	latice2.setPoint(0, Vector2f(234, 134));
	latice2.setPoint(1, Vector2f(235, 133));
	latice2.setPoint(2, Vector2f(336, 207));
	latice2.setPoint(3, Vector2f(337, 207));
	latice2.setPoint(4, Vector2f(437, 134));
	latice2.setPoint(5, Vector2f(438, 134));
	latice2.setPoint(6, Vector2f(399, 251));
	latice2.setPoint(7, Vector2f(399, 252));
	latice2.setPoint(8, Vector2f(500, 327));
	latice2.setPoint(9, Vector2f(376, 327));
	latice2.setPoint(10, Vector2f(375, 328));
	latice2.setPoint(11, Vector2f(336, 445));
	latice2.setPoint(12, Vector2f(336, 444));
	latice2.setPoint(13, Vector2f(296, 327));
	latice2.setPoint(14, Vector2f(172, 327));
	latice2.setPoint(15, Vector2f(273, 253));
	latice2.setPoint(16, Vector2f(273, 252));
}

void Cvijet::stabiljka_setup()
{
	stabiljka.setFillColor(Color::Green);
	stabiljka.setSize(Vector2f(32, 250));
	stabiljka.setPosition(Vector2f(320, 299));
}

void Cvijet::sjemenka_setup()
{
	sjemenka.setFillColor(Color(234, 161, 224));
	sjemenka.setRadius(8.0f);
	sjemenka.setPosition(309, 237);
}

void Cvijet::trava_setup()
{
	trava.setFillColor(Color(19, 130, 0));
	trava.setSize(Vector2f(800, 76));
	trava.setPosition(Vector2f(0, 524));
}