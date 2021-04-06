#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window): window(window){

	
}

void Cvijet::draw_glava()
{
	
	sf::CircleShape oblik(60.f);
	
	oblik.setFillColor(sf::Color::Yellow);
	oblik.setPosition(300, 200);
	window.draw(oblik);

}

void Cvijet::draw_tijelo()
{
	sf::RectangleShape line(sf::Vector2f(180, 8));
	line.setPosition(340, 290);
	line.setFillColor(sf::Color::Green);
	line.rotate(110);
	window.draw(line);

	sf::RectangleShape line2(sf::Vector2f(200, 8));
	line2.setPosition(278, 450);
	line2.setFillColor(sf::Color::Green);
	line2.rotate(60);
	window.draw(line2);

}

void Cvijet::draw_latice()
{
	sf::ConvexShape latica1;

	latica1.setPointCount(5);
	latica1.setFillColor(sf::Color::Green);

	latica1.setPoint(0, sf::Vector2f(290, 400));
	latica1.setPoint(1, sf::Vector2f(400, 380));
	latica1.setPoint(2, sf::Vector2f(500, 400));
	latica1.setPoint(3, sf::Vector2f(450, 450));
	latica1.setPoint(4, sf::Vector2f(350, 450));
	
	window.draw(latica1);

	sf::ConvexShape latica2;

	latica2.setPointCount(5);
	latica2.setFillColor(sf::Color::Green);

	latica2.setPoint(0, sf::Vector2f(100, 420));
	latica2.setPoint(1, sf::Vector2f(200, 450));
	latica2.setPoint(2, sf::Vector2f(290, 420));
	latica2.setPoint(3, sf::Vector2f(230, 380));
	latica2.setPoint(4, sf::Vector2f(160, 380));

	
	window.draw(latica2);
}

void Cvijet::draw_kruna()
{
	sf::CircleShape kruna(80, 6);

	kruna.setFillColor(sf::Color::Red);
	kruna.setPosition(280, 180);

	window.draw(kruna);



}

void Cvijet::draw()
{
	draw_tijelo();
	draw_kruna();
	draw_glava();
	draw_latice();
}


//Spriteovi -> https://www.youtube.com/watch?v=1ND_VRJChO4&ab_channel=SonarSystems