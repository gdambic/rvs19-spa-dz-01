#include <SFML/Graphics.hpp>
#include"Cvijet.h"
#include"CvijetMover.h"
#include"Pravokutnik.h"
#include"Sunce.h"

#include<vector>
#include<iostream>
#include<ctime>
using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 600), "Hello, SFML world!");
	sf::Vector2f V;
	window.setFramerateLimit(60);

	Sunce Sunceko(&window);
	Sunceko.SetPoz(0, 0);

	srand(time(nullptr));

	CvijetMover BKCvijet(&window, 0.75, 0);
	CvijetMover MDCvijet(&window, 1.3, 0);
	CvijetMover FRCvijet(&window, 2.45, 0);

	int BackCooldown = 0;
	int MidCooldown = 0;
	int FrontCooldown = 0;

	const int CreationDelay = 75;

	//Pozadinska trava
	Pravokutnik Trava(&window);
	Trava.SetPosGL(0, 0);
	Trava.SetPosDD(window.getSize().x, window.getSize().y);
	Trava.SetBoja(sf::Color::Color(51, 204, 51, 255));

	Trava.GenPravokutnik();

	//Pozadinsko nebo
	Pravokutnik Nebo(&window);
	Nebo.SetPosGL(0, 0);
	Nebo.SetPosDD(window.getSize().x, window.getSize().y / 5);
	Nebo.SetBoja(sf::Color::Color(0, 204, 255, 255));

	Nebo.GenPravokutnik();

	//Trava za odvajanje redova cvijeca
	Pravokutnik PrednjaTrava(&window);
	PrednjaTrava.SetPosGL(0, window.getSize().y / 1.25);
	PrednjaTrava.SetPosDD(window.getSize().x, window.getSize().y);
	PrednjaTrava.SetBoja(sf::Color::Color(51, 204, 51, 255));
	PrednjaTrava.SetOutline(true, 2);
	
	PrednjaTrava.GenPravokutnik();

	//Trava za odvajanje srednjeg cvijeca
	Pravokutnik SrednjaTrava(&window);
	SrednjaTrava.SetPosGL(0,window.getSize().y / 2.25);
	SrednjaTrava.SetPosDD(window.getSize().x, window.getSize().y);
	SrednjaTrava.SetBoja(sf::Color::Color(51, 204, 51, 255));
	SrednjaTrava.SetOutline(true, 1);

	SrednjaTrava.GenPravokutnik();
	
	//Pocetni cvijetici, kako polje ne bi pocelo prazno
	const int PocetniBrojCvijeca = 4;
	for (int i = 0; i < PocetniBrojCvijeca; i++) {
		Cvijet temp(&window);
		//Pozadina
		temp.GenerirajNasumicniCvijet(8, 40, 5, 9);
		temp.GenerirajNasumicnuPoziciju(0, (int)(window.getSize().y / 3.5), (int)window.getSize().x, (int)(window.getSize().y / 3.0));
		BKCvijet.PushCvijet(temp);
		//Sredina
		temp.GenerirajNasumicniCvijet(15, 90, 7, 15);
		temp.GenerirajNasumicnuPoziciju(0, (int)(window.getSize().y / 3.0), (int)window.getSize().x, (int)(window.getSize().y / 2.0));

		MDCvijet.PushCvijet(temp);
		//Naprijed
		temp.GenerirajNasumicniCvijet(25, 100, 10, 21);
		temp.GenerirajNasumicnuPoziciju(0, (int)(window.getSize().y / 1.5), (int)window.getSize().x, (int)(window.getSize().y / 1.25));

		FRCvijet.PushCvijet(temp);
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Nasumicno stvranje cvijeca u pozadini
		if (rand() % 100 == 1 && BackCooldown < 0) {
			Cvijet temp(&window);
			temp.GenerirajNasumicniCvijet(8, 40, 5, 9);
			temp.GenerirajNasumicnuPoziciju(-50, (int)(window.getSize().y / 3.5), -50, (int)(window.getSize().y / 3.0));

			BKCvijet.PushCvijet(temp);
			BackCooldown = CreationDelay;
		}
		//Nasumicno stvaranje cvijeca u sredini
		if (rand() % 80 == 1 && MidCooldown < 0) {
			Cvijet temp(&window);
			temp.GenerirajNasumicniCvijet(15, 90, 7, 15);
			temp.GenerirajNasumicnuPoziciju(-50, (int)(window.getSize().y / 3.0), -50, (int)(window.getSize().y / 2.0));

			MDCvijet.PushCvijet(temp);
			MidCooldown = CreationDelay;
		}
		//Nasumicno stvaranje cvijeca naprijed
		if (rand() % 90 == 1 && FrontCooldown < 0) {
			Cvijet temp(&window);
			temp.GenerirajNasumicniCvijet(25, 100, 10, 21);
			temp.GenerirajNasumicnuPoziciju(-50, (int)(window.getSize().y / 1.5), -50, (int)(window.getSize().y / 1.25));

			FRCvijet.PushCvijet(temp);
			FrontCooldown = CreationDelay;
		}

		//Move BackFlower
		BKCvijet.UpdateCvijece();
		//Move MidFlower
		MDCvijet.UpdateCvijece();
		//Move FrontFlower
		FRCvijet.UpdateCvijece();

		BackCooldown--;
		MidCooldown--;
		FrontCooldown--;	

		//window.clear();

		Trava.draw();
		Nebo.draw();
		Sunceko.draw();

		BKCvijet.draw();
		SrednjaTrava.draw();
		MDCvijet.draw();
		PrednjaTrava.draw();
		FRCvijet.draw();

		window.display();
	}

	return 0;
}