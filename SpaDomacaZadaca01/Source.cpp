#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Audio.hpp>
#include "Cvijet.h"
#include <thread>
#include <Windows.h>
#include <iostream>
using namespace std;
using namespace sf;

char main()
{
	RenderWindow window(VideoMode(1920,1080),"Cvijet"); window.setFramerateLimit (50);

	Texture pozadina_tekstura, cvijet_glava_tekstura, cvijet_baza_tekstura;
	if (!(pozadina_tekstura.loadFromFile("pozadina3.png"))) cout << "greska pozadina";
	if (!(cvijet_glava_tekstura.loadFromFile("cvijet_glava1.png"))) cout << "greska cvijet glava";
	if (!(cvijet_baza_tekstura.loadFromFile("baza_cvijeta.png"))) cout << "greska cvijet baza";

	Sprite pozadina, cvijet_glava, cvijet_baza; 
		pozadina.setTexture(pozadina_tekstura); 
		cvijet_glava.setTexture(cvijet_glava_tekstura);
		cvijet_baza.setTexture(cvijet_baza_tekstura);

					cvijet_glava.setOrigin(250, 250);		cvijet_baza.setOrigin(250, 250);
					pozadina.setScale(0.5, 0.5);			cvijet_baza.setPosition(850, 690);

	Cvijet cvijet(&window, &pozadina, &cvijet_glava, &cvijet_baza);





	/*******************************/while (window.isOpen()) cvijet.draw();/********************************/





	return '0' - 48;
}