#include "Flower.h"
#include <SFML/Graphics.hpp>

Flower::Flower(sf::RenderWindow& window)
{
	this->window = &window;
	maker();
}

//funkcija za poziv svih setera
void Flower::maker() {
	setFlower();
	setMound();
	setShade();
	setPetal();
	setSun();
	setCloud();
	setStem();
}

//izrada brda
void Flower::setMound() {
	sf::CircleShape mound(150);
	mound.setPosition({flower.getGlobalBounds().left + flower.getGlobalBounds().width/2 - mound.getRadius(), (float)window->getSize().y - mound.getRadius() * (float)0.7});
	mound.setFillColor(sf::Color(120, 75, 0));
	this->mound = mound;
}

//izrada cvijeta
void Flower::setFlower() {
	sf::CircleShape flower(50);
	flower.setFillColor(sf::Color(150, 75, 0));
	flower.setPosition({ 350, 250 });
	flower.setOutlineThickness(10);
	flower.setOutlineColor(sf::Color(250, 255, 0));
	this->flower = flower;
}

//izrada shadera
void Flower::setShade() {
	sf::RectangleShape shade;
	shade.setSize({ (float)window->getSize().x, (float)window->getSize().y });
	this->shade = shade;
}

//izrada jedne originalne latice
void Flower::setPetal() {
	sf::CircleShape petal(50);
	petal.setFillColor(sf::Color(246, 190, 0));
	petal.scale({ flower.getScale().x, flower.getScale().y/2 });
	petal.setPosition({ flower.getGlobalBounds().left + flower.getGlobalBounds().width / 2, flower.getGlobalBounds().top + flower.getGlobalBounds().height / 2 });
	this->petal = petal;
}

//izrada stabljike
void Flower::setStem() {
	sf::RectangleShape stem({ flower.getGlobalBounds().width/5 , mound.getGlobalBounds().top});
	stem.setFillColor(sf::Color(0, 128, 0));
	stem.setPosition({ flower.getGlobalBounds().left + flower.getGlobalBounds().width / 2 - stem.getSize().x/2, flower.getGlobalBounds().top + flower.getGlobalBounds().height });
	this->stem = stem;
}

//izrada sunca
void Flower::setSun() {
	sf::CircleShape sun(50);
	sun.setFillColor(sf::Color(249, 215, 28));
	sun.setPosition({ 50, 20 });
	this->sun = sun;
}

//izrada oblaka
void Flower::setCloud() {
	sf::CircleShape cloud(sun.getRadius());
	cloud.setFillColor(sf::Color(220, 220, 220));
	cloud.scale({ 2, 1.2 });
	this->cloud = cloud;
}

void Flower::draw()
{
	int petalRotation = 0;
	float cloudPositionX = -cloud.getGlobalBounds().width;
	float cloudPositionY = sun.getGlobalBounds().top + sun.getGlobalBounds().height / 2 - cloud.getGlobalBounds().height / 2;

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window->close();
		}
		
		window->clear(sf::Color(135, 206, 235));
		window->draw(sun);
		window->draw(cloud);
		window->draw(stem);
		window->draw(mound);


		do {
			//zbrajamo sa x pozicijom oblaka da bi dobili efekt okretanja latica
			petal.setRotation(petalRotation + cloudPositionX);
			petalRotation += 10;
			cloud.setPosition({ cloudPositionX, cloudPositionY});
			window->draw(petal);
		} while (petalRotation <= 360);
		petalRotation = 0;

		//resetira oblak kad izade sa ekrana, a ako je jos na ekranu pomicemo ga u desno
		if (cloudPositionX >= window->getSize().x)
		{
			cloudPositionX = -(cloud.getRadius() * cloud.getScale().x) * 2;
		}
		else{
			cloudPositionX += 1;
		}

		window->draw(flower);
			
		//ako oblak prekriva sunce onda se "zatamnjuje" window  
		if (cloud.getGlobalBounds().left + cloud.getGlobalBounds().width >= sun.getGlobalBounds().left + sun.getGlobalBounds().width && cloud.getGlobalBounds().left < sun.getGlobalBounds().left && darkness < 130) {
			//mjenjanje transparentnosti 
			darkness += 5;
		}
		else if (cloud.getGlobalBounds().left >= sun.getGlobalBounds().left && darkness > 0)
		{
			darkness -= 5;
		}

		shade.setFillColor(sf::Color(0, 0, 0, darkness));
		window->draw(shade);
		window->display();
	}
}