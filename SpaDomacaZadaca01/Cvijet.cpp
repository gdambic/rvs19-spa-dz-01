#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window): window(window){}


void Cvijet::draw_glava(sf::CircleShape& oblik)
{
	oblik.setRadius(60.f);
	oblik.setFillColor(sf::Color::Yellow);
	oblik.setPosition(300, 200);
	
	window.draw(oblik);

}

void Cvijet::draw_tijelo(sf::RectangleShape& line, sf::RectangleShape& line2)
{
	line.setSize (sf::Vector2f(180, 8));
	line.setPosition(340, 290);
	line.setFillColor(sf::Color::Green);
	line.setRotation(110);
	
	window.draw(line);

	line2.setSize(sf::Vector2f(200, 8));
	line2.setPosition(278, 450);
	line2.setFillColor(sf::Color::Green);
	line2.setRotation(60);
	
	window.draw(line2);

}

void Cvijet::draw_latice(sf::ConvexShape& latica1, sf::ConvexShape& latica2)
{
	latica1.setPointCount(5);
	latica1.setFillColor(sf::Color::Green);
	latica1.setPoint(0, sf::Vector2f(290, 400));
	latica1.setPoint(1, sf::Vector2f(400, 380));
	latica1.setPoint(2, sf::Vector2f(500, 400));
	latica1.setPoint(3, sf::Vector2f(450, 450));
	latica1.setPoint(4, sf::Vector2f(350, 450));
	
	window.draw(latica1);

	latica2.setPointCount(5);
	latica2.setFillColor(sf::Color::Green);
	latica2.setPoint(0, sf::Vector2f(100, 420));
	latica2.setPoint(1, sf::Vector2f(200, 450));
	latica2.setPoint(2, sf::Vector2f(290, 420));
	latica2.setPoint(3, sf::Vector2f(230, 380));
	latica2.setPoint(4, sf::Vector2f(160, 380));

	window.draw(latica2);
}

void Cvijet::draw_kruna(sf::CircleShape& kruna)
{
	kruna.setRadius(80);
	kruna.setPointCount(6);
	kruna.setFillColor(sf::Color::Red);
	kruna.setPosition(280, 180);

	window.draw(kruna);

}

void Cvijet::draw_kruna2(sf::CircleShape& kruna2, sf::Clock& clock, sf::Time& dt)
{
	dt = clock.restart();

	this->x = x;
	this->brzina = brzina;

	kruna2.setRadius(80);
	kruna2.setPointCount(8);
	kruna2.setFillColor(sf::Color::Red);
	kruna2.setOrigin(80, 80);
	kruna2.setPosition(360, 260);
	kruna2.setRotation(x);
	window.draw(kruna2);
	
	x += brzina * dt.asSeconds();

}

void Cvijet::draw_zemlja(sf::RectangleShape& zemlja) {

	zemlja.setSize(sf::Vector2f(800, 50));
	zemlja.setPosition(0, 580);
	zemlja.setFillColor(sf::Color(117, 87, 55));

	window.draw(zemlja);

}

void Cvijet::draw()
{
	draw_tijelo(line,line2);
	draw_kruna2(kruna2, clock, dt);
	draw_kruna(kruna);
	draw_glava(oblik);
	draw_latice(latica1, latica2);
	draw_zemlja(zemlja);
}


