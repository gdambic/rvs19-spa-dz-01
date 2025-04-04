#include "Cvijet.h"
#include <ctime>


Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	x = -180.f;
	y = 0;
	srand(time(nullptr));
}

void Cvijet::generateClouds() {
	while (clouds.size() < 10) {
		int maxx = 250;
		int minx = 50;
		int maxy = 55;
		int miny = 15;
		int sizex = rand() % (maxx - minx + 1) + minx;
		int sizey = rand() % (maxy - miny + 1) + miny;
		int locx = sizex + 800.f + rand() % (1000 - 50 + 1) + 50;
		int locy = rand() % (200 - 0 + 1) + 0;
		Cloud cloud{ locx, locy, sizex, sizey };
		clouds.push_back(cloud);
	}
}

void Cvijet::generateWaves()
{
	int x = -15.0f;
	int y = 510.f;
	while (wavegroups.size() < 20) 
	{
		if (wavegroups.size() > 0) {
			WaveGroup wg{ wavegroups[wavegroups.size() - 1].x - 80, y};
			wavegroups.push_back(wg);
		}
		else {
			WaveGroup wg{ x, y };
			wavegroups.push_back(wg);
		}
	}

}

void Cvijet::draw()
{

	//Nebo

	sf::RectangleShape Sky(sf::Vector2f(800.f, 350.f));
	if( x < 800.f)
		Sky.setFillColor(sf::Color(135, 206, 235));
	else
		Sky.setFillColor(sf::Color(32, 32, 43));
	Sky.setPosition(0, 0);
	window->draw(Sky);

	// Sunce i mjesec
	x++;

	sf::CircleShape Sun(80.f, 16.f);
	Sun.setFillColor(sf::Color::Yellow);
	Sun.setPosition(x, 0.001 * ((x - 350.f) * (x - 350.f)));
	window->draw(Sun);

	Sun.setFillColor(sf::Color(200,200,200));
	Sun.setPosition(x - 980.f, 0.001 * ((x - 350.f - 960.f) * (x - 350.f - 960.f)));
	window->draw(Sun);

	Sun.setFillColor(sf::Color(32, 32, 43));
	Sun.setPosition(x - 980.f - 20.f, 0.001 * ((x - 350.f - 960.f) * (x - 350.f - 960.f)) - 20.f);
	window->draw(Sun);

	if (x > 1800.f) x = - 180.f;

	//Pozadina

	sf::RectangleShape Grass(sf::Vector2f(800.f, 250.f));
	if (x < 800.f)
		Grass.setFillColor(sf::Color(0, 150, 0));
	else
		Grass.setFillColor(sf::Color(0, 50, 0));
	Grass.setPosition(0, 350.f);
	window->draw(Grass);

	sf::RectangleShape River(sf::Vector2f(800.f, 50.f));
	if (x < 800.f)
		River.setFillColor(sf::Color(57, 88, 121));
	else
		River.setFillColor(sf::Color(3, 41, 72));
	River.setPosition(0, 500.f);
	window->draw(River);

	generateWaves();

	for (int i = 0; i < wavegroups.size(); i++)
	{
		if (wavegroups[0].x > 800.f) {
			wavegroups.erase(wavegroups.begin());
			continue;
		}
		wavegroups[i].x++;
		sf::RectangleShape Wave(sf::Vector2f(15.f, 3.f));
		if (x < 800.f)
			Wave.setFillColor(sf::Color(143, 205, 217));
		else
			Wave.setFillColor(sf::Color(40, 87, 111));
		Wave.setPosition(wavegroups[i].x, wavegroups[i].y);
		window->draw(Wave);
		Wave.setPosition(wavegroups[i].x + 5.f, wavegroups[i].y + 10.f);
		window->draw(Wave);
		Wave.setPosition(wavegroups[i].x, wavegroups[i].y + 20.f);
		window->draw(Wave);
	}

	//Oblaci

	generateClouds();

	for (int i = 0; i < clouds.size(); i++)
	{
		if (clouds[i].x > -clouds[i].sizex) {
			clouds[i].x--;
		}
		else {
			clouds.erase(clouds.begin() + i);
			continue;
		}
		sf::RectangleShape Cloud(sf::Vector2f(clouds[i].sizex, clouds[i].sizey));
		if (x < 800.f)
			Cloud.setFillColor(sf::Color(255, 255, 255));
		else
			Cloud.setFillColor(sf::Color(150, 150, 150));
		Cloud.setPosition(clouds[i].x, clouds[i].y);
		window->draw(Cloud);
	}

	//Planine

	sf::ConvexShape mountain;
	mountain.setPointCount(3);
	mountain.setPoint(0, { 300.f, 400.f });
	mountain.setPoint(1, { 550.f, 100.f });
	mountain.setPoint(2, { 800.f, 400.f });
	if (x < 800.f)
		mountain.setFillColor(sf::Color(128, 128, 128));
	else
		mountain.setFillColor(sf::Color(58, 58, 58));

	sf::ConvexShape snowCap;
	snowCap.setPointCount(3);
	snowCap.setPoint(0, { 508.f, 150.f });
	snowCap.setPoint(1, { 550.f, 100.f });
	snowCap.setPoint(2, { 592.f, 150.f });
	if (x < 800.f)
		snowCap.setFillColor(sf::Color::White);
	else
		snowCap.setFillColor(sf::Color(128, 128, 128));

	window->draw(mountain);
	window->draw(snowCap);

	//Cvijet

	sf::RectangleShape stemaxis(sf::Vector2f(10.f, 100.f));
	if (x < 800.f)
		stemaxis.setFillColor(sf::Color::Green);
	else
		stemaxis.setFillColor(sf::Color(0, 75, 0));
	stemaxis.setPosition(145.f, 350.f);
	window->draw(stemaxis);

	sf::ConvexShape leaf;
	leaf.setPointCount(3);
	leaf.setPoint(0, sf::Vector2f(150.f, 425.f));
	leaf.setPoint(1, sf::Vector2f(250.f, 400.f));
	leaf.setPoint(2, sf::Vector2f(200.f, 380.f));
	if (x < 800.f)
		leaf.setFillColor(sf::Color::Green);
	else
		leaf.setFillColor(sf::Color(0, 75, 0));
	window->draw(leaf);

	sf::CircleShape circle(50.f);
	if (x < 800.f) {
		circle.setFillColor(sf::Color::Yellow);
		circle.setOutlineColor(sf::Color::Magenta);
	}
	else {
		circle.setFillColor(sf::Color(100, 100, 0));
		circle.setOutlineColor(sf::Color(50, 0, 50));
	}
	circle.setOutlineThickness(25.f);
	circle.setPosition(100.f, 250.f);
	window->draw(circle);

}
