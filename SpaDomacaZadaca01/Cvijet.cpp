#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window): window(window){}

void Cvijet::set_cvijet(float x, float brzina) {
	this->x = x;
	this->brzina = brzina;

}
void Cvijet::draw_glava(sf::CircleShape& oblik)
{
	oblik.setRadius(60.f);
	oblik.setFillColor(sf::Color::Yellow);
	oblik.setPosition(300, 200);
	oblik.setOutlineThickness(1);
	oblik.setOutlineColor(sf::Color::Black);

	window.draw(oblik);

}

void Cvijet::draw_tijelo(sf::RectangleShape& line, sf::RectangleShape& line2, sf::RectangleShape& line3)
{

	line.setSize (sf::Vector2f(182, 8));
	line.setPosition(340, 290);
	line.setFillColor(sf::Color(35, 194, 83));
	line.setRotation(110);
	line.setOutlineThickness(1);
	line.setOutlineColor(sf::Color::Black);
	
	line2.setSize(sf::Vector2f(200, 8));
	line2.setPosition(275, 457);
	line2.setFillColor(sf::Color(35, 194, 83));
	line2.setRotation(60);
	line2.setOutlineThickness(1);
	line2.setOutlineColor(sf::Color::Black);
	
	line3.setSize(sf::Vector2f(183, 8));
	line3.setPosition(340, 290);
	line3.setFillColor(sf::Color(35, 194, 83));
	line3.setRotation(110);


	window.draw(line2);
	window.draw(line);
	window.draw(line3);

}

void Cvijet::draw_latice(sf::ConvexShape& latica1, sf::ConvexShape& latica2)
{
	latica1.setPointCount(5);
	latica1.setFillColor(sf::Color(35, 194, 83));
	latica1.setPoint(0, sf::Vector2f(295, 400));
	latica1.setPoint(1, sf::Vector2f(400, 380));
	latica1.setPoint(2, sf::Vector2f(500, 400));
	latica1.setPoint(3, sf::Vector2f(450, 450));
	latica1.setPoint(4, sf::Vector2f(350, 450));
	latica1.setOutlineThickness(1);
	latica1.setOutlineColor(sf::Color::Black);

	window.draw(latica1);

	latica2.setPointCount(5);
	latica2.setFillColor(sf::Color(35, 194, 83));
	latica2.setPoint(0, sf::Vector2f(100, 420));
	latica2.setPoint(1, sf::Vector2f(200, 450));
	latica2.setPoint(2, sf::Vector2f(290, 420));
	latica2.setPoint(3, sf::Vector2f(230, 380));
	latica2.setPoint(4, sf::Vector2f(160, 380));
	latica2.setOutlineThickness(1);
	latica2.setOutlineColor(sf::Color::Black);

	window.draw(latica2);
}

void Cvijet::draw_kruna(sf::CircleShape& kruna,sf::Clock& clock, sf::Time& dt)
{
	dt = clock.restart();

	kruna.setRadius(80);
	kruna.setPointCount(6);
	kruna.setFillColor(sf::Color::Red);
	kruna.setPosition(360, 260);
	kruna.setOutlineThickness(1);
	kruna.setOutlineColor(sf::Color::Black);
	kruna.setOrigin(80, 80);
	kruna.setRotation(-x);
	window.draw(kruna);

	x += brzina * dt.asSeconds();

}

void Cvijet::draw_kruna2(sf::CircleShape& kruna2, sf::Clock& clock, sf::Time& dt)
{
	dt = clock.restart();

	

	kruna2.setRadius(80);
	kruna2.setPointCount(8);
	kruna2.setFillColor(sf::Color(143, 24, 0));
	kruna2.setOrigin(80, 80);
	kruna2.setPosition(360, 260);
	kruna2.setOutlineThickness(1);
	kruna2.setOutlineColor(sf::Color::Black);
	kruna2.setRotation(x);
	window.draw(kruna2);
	
	x += brzina * dt.asSeconds();

}

void Cvijet::draw_zemlja(sf::RectangleShape& zemlja) {

	zemlja.setSize(sf::Vector2f(800, 50));
	zemlja.setPosition(0, 580);
	zemlja.setFillColor(sf::Color(117, 87, 55));
	zemlja.setOutlineThickness(1);
	zemlja.setOutlineColor(sf::Color::Black);

	window.draw(zemlja);

}

void Cvijet::draw()
{
	draw_latice(latica1 , latica2);
	draw_tijelo(line,line2,line3);
	draw_kruna2(kruna2, clock, dt);
	draw_kruna(kruna, clock, dt);
	draw_glava(oblik);
	draw_zemlja(zemlja);
}


