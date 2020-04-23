#include "Cvijet.h"
Cvijet::Cvijet(RenderWindow* w, Sprite* pozadina, Sprite* cvijet_glava, Sprite* cvijet_baza)
{ 
	this->w = w;
	this->pozadina = pozadina;
	this->cvijet_glava = cvijet_glava;
	this->cvijet_baza = cvijet_baza;
}

void Cvijet::draw()
{
								VertexArray stabljika(TrianglesStrip, 8);
	float desna_strana = 880;	
	float lijeva_strana = 840;
	stabljika[0].position = Vector2f(666, 1337);				stabljika[0].color = Color(199, 199, 4, 255);
	stabljika[1].position = Vector2f(35.1837, 80085);			stabljika[1].color = Color(199, 199, 4, 255);
	stabljika[2].position = Vector2f(lijeva_strana, 570);		stabljika[2].color = Color(148, 219, 41, 255);
	stabljika[3].position = Vector2f(desna_strana, 570);		stabljika[3].color = Color(148, 219, 41, 255);
	stabljika[4].position = Vector2f(lijeva_strana - 5, 625);	stabljika[4].color = Color(110, 199, 59, 255);
	stabljika[5].position = Vector2f(desna_strana + 5, 625);	stabljika[5].color = Color(110, 199, 59, 255);
	stabljika[6].position = Vector2f(lijeva_strana - 15, 700);	stabljika[6].color = Color(101, 150, 28, 255);
	stabljika[7].position = Vector2f(desna_strana + 15, 700);	stabljika[7].color = Color(101, 150, 28, 255);

		
										int broj_frejmova = 50;
					float pomicalica_x = 4.0;			float pomicalica_y = 0.126;
					float pomakni_cvijet_x = 0;			float pomakni_cvijet_y = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int i = 0; i < broj_frejmova; i++)
		{
			if (i < 30)
				cvijet_glava->setScale(-0.5, 0.5);
			else
				cvijet_glava->setScale(0.5, 0.5);
			frejm(pomakni_cvijet_x -= pomicalica_x, 30 * sin(pomakni_cvijet_y += pomicalica_y), stabljika);
		}
		for (int i = 0; i < broj_frejmova; i++)
		{
			if (i < 30)
				cvijet_glava->setScale(0.5, 0.5);
			else
				cvijet_glava->setScale(-0.5, 0.5);
			frejm(pomakni_cvijet_x += pomicalica_x, 30 * sin(pomakni_cvijet_y += pomicalica_y), stabljika);
		}
	}
}

void eventalica(RenderWindow* w) {
	Event event;
	while (w->pollEvent(event))
	{
		if (event.type == Event::MouseButtonPressed)		w->close();
		if (event.type == Event::KeyPressed)				w->close();
		if (event.type == Event::Closed)					w->close();
	}
}

void Cvijet::frejm(float pomak_x, float pomak_y, VertexArray stabljika)
{
	stabljika[0].position.x = cvijet_glava->getPosition().x - 10;
	stabljika[0].position.y = cvijet_glava->getPosition().y;
	stabljika[1].position.x = cvijet_glava->getPosition().x + 10;
	stabljika[1].position.y = cvijet_glava->getPosition().y;
	stabljika[2].position = Vector2f(870 + pomak_x / 4.0, 590 + pomak_y / 2);
	stabljika[3].position = Vector2f(910 + pomak_x / 4.0, 590 + pomak_y / 2);
	stabljika[4].position.x = 860 + pomak_x / 8.0;
	stabljika[5].position.x = 900 + pomak_x / 8.0;

	cvijet_glava->setPosition(960 + pomak_x, 500 + pomak_y);

	w->clear();

			w->draw(*pozadina);
				w->draw(stabljika);
					w->draw(*cvijet_glava);
						w->draw(*cvijet_baza);

								w->display();

	eventalica(w);
}