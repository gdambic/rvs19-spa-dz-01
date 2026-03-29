#include "Cvijet.h"
#include <cmath>

//konstruktor, ovdje pozivam svo namjestanje raznih shapeova kako bi formirali cvijet
Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	setFlowerPod();
	setFlowerPetals();
	setFlowerStem();
	setBackground();
	setBee();

	//pocetna stanja za animaciju pcele
	beeX = 700.f;
	beeBaseY = 300.f;
	beeSpeed = 180.f;
	beeAmplitude = 40.f;
	beeFrequency = 4.f; 
	beePhase = 0.f;

}

void Cvijet::setFlowerPod()
{
	flowerPod.setRadius(65.f);
	flowerPod.setPosition(230.f, 90.f);
	flowerPodTexture.loadFromFile("FlowerPodTexture.png");
	flowerPod.setTexture(&flowerPodTexture);
}

void Cvijet::setFlowerPetals()
{
	flowerPetals.setSize(sf::Vector2f(500.f,350.f));
	flowerPetalsTexture.loadFromFile("FlowerPetals.png");
	flowerPetals.setTexture(&flowerPetalsTexture);
	flowerPetals.setPosition(100.f, 0.f);


	//racunica i prilagodjavanja scalea kako bi textura bolje pasala
	sf::Vector2u textureSize = flowerPetalsTexture.getSize();
	sf::Vector2f petalsSize = flowerPetals.getSize();

	flowerPetals.setScale(
		petalsSize.x / textureSize.x,
		petalsSize.y / textureSize.y
	);
}

void Cvijet::setFlowerStem()
{
	flowerStem.setSize(sf::Vector2f(350.f, 500.f));
	flowerStemTexture.loadFromFile("FlowerStemTexture.png");
	flowerStem.setTexture(&flowerStemTexture);
	flowerStem.setPosition(100.f, 100.f);

}

void Cvijet::setBackground()
{
	backgroundTexture.loadFromFile("Background.png");
	background.setTexture(&backgroundTexture);
	background.setSize(sf::Vector2f(800.f, 600.f));
	
}

void Cvijet::setBee()
{
	bee.setSize(sf::Vector2f(100.f, 70.f));
	beeTexture.loadFromFile("beeTexture.png");
	if (!beeTexture.loadFromFile("beeTexture.png")) cout << "beeTexture.png failed to load correctly" << endl;
	bee.setTexture(&beeTexture);
	bee.setPosition(700.f, 300.f);

}

//shapeovi se crtaju po redoslijedu
void Cvijet::draw()
{
	//vrijeme od zadnjeg framea
	float dt = frameClock.restart().asSeconds();

	//pomak pcele s desna na lijevo
	beeX -= beeSpeed * dt;

	//faza vala
	beePhase += beeFrequency * dt;

	//valovito gibanje po y osi
	float beeY = beeBaseY + sin(beePhase) * beeAmplitude;

	bee.setPosition(beeX, beeY);

	//kada pcela potpuno izadje lijevo, vracamo ju na desni kraj ekrana
	if (beeX + bee.getSize().x < 0.f)
	{
		//vracamo pcelu na desni rub prozora, radimo konverziju u float tipove podataka
		beeX = static_cast<float>(window->getSize().x);
	}

	window->draw(background);
	window->draw(flowerStem);
	window->draw(flowerPetals);
	window->draw(flowerPod);
	window->draw(bee);
	
}
