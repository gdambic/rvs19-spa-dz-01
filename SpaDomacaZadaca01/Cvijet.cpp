#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window)
{
	//crtanje glave cvijeta
	glava.setRadius(90);
	glava.setFillColor(Color(203, 186, 29));
	glava.setPosition(270, 120);
	//crtanje lijevog oka
	lijevo_oko.setRadius(20);
	lijevo_oko.setFillColor(Color(165, 92, 9));
	lijevo_oko.setPosition(300, 170);
	//crtanje lijeve zijenice
	lijeva_zjenica.setRadius(14);
	lijeva_zjenica.setFillColor(Color(0, 0, 0));
	lijeva_zjenica.setPosition(305, 176);
	//crtanje lijevog odsjaja oka
	lijevi_odsjaj.setRadius(5);
	lijevi_odsjaj.setFillColor(Color(255, 255, 255));
	lijevi_odsjaj.setPosition(310, 180);
	//crtanje desnog oka
	desno_oko.setRadius(20);
	desno_oko.setFillColor(Color(165, 92, 9));
	desno_oko.setPosition(370, 170);
	//crtanje desne zijenice
	desna_zjenica.setRadius(14);
	desna_zjenica.setFillColor(Color(0, 0, 0));
	desna_zjenica.setPosition(375, 176);
	//crtanje desnog odsjaja oka
	desni_odsjaj.setRadius(5);
	desni_odsjaj.setFillColor(Color(255, 255, 255));
	desni_odsjaj.setPosition(380, 180);
	//crtanje nosa
	nos.setFillColor(Color(188, 107, 16));
	nos.setSize(Vector2f(15, 35));
	nos.setPosition(348, 210);
	//crtanje usta
	usta.setFillColor(Color(255, 255, 255));
	usta.setSize(Vector2f(70, 18));
	usta.setPosition(320, 258);
	//crtanje linija zubiju
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		linije_zubiju[i].setFillColor(Color(0, 0, 0));
		linije_zubiju[i].setSize(Vector2f(2, 18));
		linije_zubiju[i].setPosition(330 + j, 258);
		j += 12;
	}
	linije_zubiju[5].setFillColor(Color(0, 0, 0));
	linije_zubiju[5].setSize(Vector2f(70, 2));
	linije_zubiju[5].setPosition(320, 266);
	//crtanje tijela
	tijelo.setFillColor(Color(0, 255, 0));
	tijelo.setSize(Vector2f(30, 300));
	tijelo.setPosition(345, 299);
	//crtanje desnog lista
	desni_list.setPointCount(4);
	desni_list.setPoint(0, Vector2f(370, 470));
	desni_list.setPoint(1, Vector2f(570, 370));
	desni_list.setPoint(2, Vector2f(590, 470));
	desni_list.setPoint(3, Vector2f(350, 500));
	desni_list.setFillColor(Color(0, 255, 0));
	//crtanje lijevog lista
	lijevi_list.setPointCount(4);
	lijevi_list.setPoint(0, Vector2f(350, 470));
	lijevi_list.setPoint(1, Vector2f(200, 370));
	lijevi_list.setPoint(2, Vector2f(160, 470));
	lijevi_list.setPoint(3, Vector2f(350, 500));
	lijevi_list.setFillColor(Color(0, 255, 0));
	//crtanje sunca
	sunce.setFillColor(Color(255, 255, 0));
	sunce.setPosition(10, 10);
	sunce.setRadius(5);
}

void Cvijet::draw(sf::RenderWindow& window)
{
	window.draw(glava);
	window.draw(lijevo_oko);
	window.draw(desno_oko);
	window.draw(lijeva_zjenica);
	window.draw(desna_zjenica);
	window.draw(lijevi_odsjaj);
	window.draw(desni_odsjaj);
	window.draw(nos);
	window.draw(usta);
	window.draw(tijelo);
	window.draw(desni_list);
	window.draw(lijevi_list);
	window.draw(sunce);
	for (auto i = 0; i < 6; i++) window.draw(linije_zubiju[i]);

}

void Cvijet::anim(sf::Clock& clock)
{
	auto vrijeme_sekunde = clock.getElapsedTime().asSeconds();
	std::cout << vrijeme_sekunde << std::endl;

	if (clock.getElapsedTime().asSeconds() >= 1)
		sunce.setRadius(5 + 12 * vrijeme_sekunde);
 
	if (clock.getElapsedTime().asSeconds() >= 6)
		clock.restart();
}
