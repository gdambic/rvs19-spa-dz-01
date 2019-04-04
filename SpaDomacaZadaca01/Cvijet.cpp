#include "Cvijet.h"	

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

sf::Vector2f Cvijet::getPlatformPos(sf::RectangleShape platforma)
{
	return platforma.getPosition();
}

void Cvijet::setWindowWidthHeight(unsigned& windowWidth, unsigned& windowHeight)
{
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
}

void Cvijet::draw()
{
	circle.setOrigin(25.f, 25.f);
	circle.setPosition((float)(windowWidth / 2) - 25.f, (float)(windowHeight / 2) - 25.f);
	circle.setFillColor(sf::Color(255, 239, 10));
	//top of the flower
	elipsaGore.setOrigin(sf::Vector2f(0.f, 1.f));
	elipsaGore.setPosition(423.f, 130.f);
	elipsaGore.setRotation(90.f);
	//left of the flower
	elipsaLijevo.setOrigin(sf::Vector2f(0.f, 1.f));
	elipsaLijevo.setPosition(230.f, 275.f);
	//right of the flower
	elipsaDesno.setOrigin(sf::Vector2f(0.f, 1.f));
	elipsaDesno.setPosition(450.f, 274.f);
	//bottom of the flower
	elipsaDolje.setOrigin(sf::Vector2f(0.f, 1.f));
	elipsaDolje.setPosition(423.f, 350.f);
	elipsaDolje.setRotation(90.f);

	//stabljika
	stabljika.setPosition(420.f, 325.f);
	stabljika.setRotation(-20.f);
	stabljika.setFillColor(sf::Color(28, 173, 9));

	//list stabljike desno
	listStabljikeDesno.setPosition(465.f, 425.f);
	listStabljikeDesno.setRotation(-25.f);
	listStabljikeDesno.setFillColor(sf::Color(31, 214, 7));

	//list stabljike lijevo
	listStabljikeLijevo.setPosition(428.f, 465.f);
	listStabljikeLijevo.setFillColor(sf::Color(22, 148, 6));

	//pod
	pod.setFillColor(sf::Color(109, 52, 31));
	pod.setPosition(0.f, 550.f);

	//platforma 1
	platforma1.setFillColor(sf::Color(242, 221, 128));
	platforma1.setOrigin(0.f, 0.f);
	platforma1.setPosition(100.f, 450.f);

	//platforma 2
	platforma2.setFillColor(sf::Color(242, 221, 128));
	platforma2.setOrigin(0.f, 0.f);
	platforma2.setPosition(200.f, 375.f);

	//platforma 3
	platforma3.setFillColor(sf::Color(242, 221, 128));
	platforma3.setOrigin(0.f, 0.f);
	platforma3.setPosition(300.f, 400.f);

	//platforma 4
	platforma4.setFillColor(sf::Color(242, 221, 128));
	platforma4.setOrigin(0.f, 0.f);
	platforma4.setPosition(400.f, 450.f);

	//platforma 5
	platforma5.setFillColor(sf::Color(242, 221, 128));
	platforma5.setOrigin(0.f, 0.f);
	platforma5.setPosition(500.f, 375.f);

	//platforma 6
	platforma6.setFillColor(sf::Color(242, 221, 128));
	platforma6.setOrigin(0.f, 0.f);
	platforma6.setPosition(625.f, 400.f);

	//lijevi dio oblaka
	oblak11.setFillColor(sf::Color::White);
	oblak11.setOrigin(12.5f, 12.5f);
	oblak11.setPosition(75.f, 75.f);
	
	//srednji dio oblaka
	oblak12.setFillColor(sf::Color::White);
	oblak12.setOrigin(17.5f, 17.5f);
	oblak12.setPosition(100.f, 75.f);

	//desni dio oblaka
	oblak13.setFillColor(sf::Color::White);
	oblak13.setOrigin(12.5f, 12.5f);
	oblak13.setPosition(125.f, 75.f);
	
	//lijevi dio oblaka2
	oblak21.setFillColor(sf::Color(203, 206, 211));
	oblak21.setOrigin(12.5f, 12.5f);
	oblak21.setPosition(300.f, 85.f);
	
	//srednji dio oblaka2
	oblak22.setFillColor(sf::Color(203, 206, 211));
	oblak22.setOrigin(17.5f, 17.5f);
	oblak22.setPosition(325.f, 85.f);

	//desni dio oblaka2
	oblak23.setFillColor(sf::Color(203, 206, 211));
	oblak23.setOrigin(12.5f, 12.5f);
	oblak23.setPosition(350.f, 85.f);
	
	//lijevi dio oblaka3
	oblak31.setFillColor(sf::Color(213, 221, 234));
	oblak31.setOrigin(12.5f, 12.5f);
	oblak31.setPosition(500.f, 65.f);
	
	//srednji dio oblaka3
	oblak32.setFillColor(sf::Color(213, 221, 234));
	oblak32.setOrigin(17.5f, 17.5f);
	oblak32.setPosition(525.f, 65.f);

	//desni dio oblaka3
	oblak33.setFillColor(sf::Color(213, 221, 234));
	oblak33.setOrigin(12.5f, 12.5f);
	oblak33.setPosition(550.f, 65.f);

	//PEPE
	sf::Texture pepePNG;
	pepePNG.loadFromFile("Pepe.png");
	pepe.setTexture(&pepePNG);
	pepe.setTextureRect(sf::IntRect(0, 0, 100, 100));
	pepe.setPosition(700.f, 0.f);
	pepe.setRotation(-25.f);

	window->draw(pepe);

	window->draw(oblak12);
	window->draw(oblak11);
	window->draw(oblak13);
	
	window->draw(oblak22);
	window->draw(oblak21);
	window->draw(oblak23);
	
	window->draw(oblak32);
	window->draw(oblak31);
	window->draw(oblak33);

	window->draw(elipsaGore);
	window->draw(elipsaLijevo);
	window->draw(elipsaDesno);
	window->draw(elipsaDolje);

	window->draw(listStabljikeLijevo);
	window->draw(stabljika);
	window->draw(listStabljikeDesno);
	
	window->draw(pod);
	window->draw(platforma1);
	window->draw(platforma2);
	window->draw(platforma3);
	window->draw(platforma4);
	window->draw(platforma5);
	window->draw(platforma6);

	window->draw(circle);
}
