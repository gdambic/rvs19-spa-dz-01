#include "Planina.h"

Planina::Planina(sf::RenderWindow* window)
{
	this->window = window;
}

void Planina::draw()
{
	sf::VertexArray planina(sf::TriangleStrip, 22);

	//pozicija

	planina[0].position = sf::Vector2f(0.f, 730.f);
	planina[1].position = sf::Vector2f(0.f, 900.f);

	planina[2].position = sf::Vector2f(250.f, 600.f); //vrh
	planina[3].position = sf::Vector2f(250.f, 900.f);

	planina[4].position = sf::Vector2f(350.f, 750.f);
	planina[5].position = sf::Vector2f(350.f, 900.f);

	planina[6].position = sf::Vector2f(500.f, 700.f);
	planina[7].position = sf::Vector2f(500.f, 900.f);

	planina[8].position = sf::Vector2f(700.f, 465.f);	//vrh
	planina[9].position = sf::Vector2f(700.f, 900.f);

	planina[10].position = sf::Vector2f(850.f, 700.f);	//
	planina[11].position = sf::Vector2f(850.f, 900.f);

	planina[12].position = sf::Vector2f(1000.f, 800.f);	//dno planine
	planina[13].position = sf::Vector2f(1000.f, 900.f);

	planina[14].position = sf::Vector2f(1200.f, 600.f);	//prvi vrh na planini
	planina[15].position = sf::Vector2f(1200.f, 900.f);

	planina[16].position = sf::Vector2f(1250.f, 650.f);	//udubina na planini
	planina[17].position = sf::Vector2f(1250.f, 900.f);

	planina[18].position = sf::Vector2f(1400.f, 400.f);	//zadnji vrh
	planina[19].position = sf::Vector2f(1400.f, 900.f);

	planina[20].position = sf::Vector2f(1600.f, 790.f);	//Kraj
	planina[21].position = sf::Vector2f(1600.f, 900.f);

	planina[0].color = sf::Color(35, 35, 35);
	planina[1].color = sf::Color(35, 35, 35);

	planina[2].color = sf::Color(255, 255, 255); //vrh
	planina[3].color = sf::Color(35, 35, 35);

	planina[4].color = sf::Color(35, 35, 35);
	planina[5].color = sf::Color(35, 35, 35);

	planina[6].color = sf::Color(70, 70, 70);
	planina[7].color = sf::Color(35, 35, 35);

	planina[8].color = sf::Color(255, 255, 255); //vrh
	planina[9].color = sf::Color(35, 35, 35);

	planina[10].color = sf::Color(100, 100, 100);
	planina[11].color = sf::Color(35, 35, 35);

	planina[12].color = sf::Color(35, 35, 35);
	planina[13].color = sf::Color(35, 35, 35);

	planina[14].color = sf::Color(220, 220, 220);
	planina[15].color = sf::Color(35, 35, 35);

	planina[16].color = sf::Color(60, 60, 60);
	planina[17].color = sf::Color(35, 35, 35);

	planina[18].color = sf::Color(255, 255, 255);
	planina[19].color = sf::Color(35, 35, 35);

	planina[20].color = sf::Color(35, 35, 35);
	planina[21].color = sf::Color(35, 35, 35);

	window->draw(planina);
}
