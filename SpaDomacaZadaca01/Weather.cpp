#include "Weather.h"
Weather::Weather(sf::RenderWindow* window, struct colors* c)
{
	this->window = window;
	srand(time(NULL));
	rainDrop = vector<RectangleShape>(nbDrop, RectangleShape(Vector2f(width, height)));
	clouds = vector<CircleShape>(3, CircleShape(20.f));
	clock = Clock();
	initRain();
	initSun();
	initStars();
	this->c = c;
	clock2 = Clock();
}
bool Weather::getDay()
{
	return day;
}
bool Weather::getRain()
{
	return rain;
}
int genRand(int min, int max) {
	return rand() % (max - min + 1) + min;
}
void Weather::setRandPos(RectangleShape& rect) {
	Vector2f pos = rect.getPosition();
	pos.x = genRand(0, window->getSize().x);
	pos.y = genRand(0, window->getSize().y);
	rect.setPosition(pos);
}
void Weather::initSun()
{
	sun = CircleShape(30.f);
	sun.setPosition(Vector2f(15.f, 15.f));
	sun.setFillColor(Color().Yellow);
}
void Weather::initStars() {
	stars = vector<CircleShape>(100, CircleShape(5.f));
	for (auto it = stars.begin(); it != stars.end(); ++it) {
		(*it).setPosition(Vector2f(genRand(0, window->getSize().x), genRand(0, window->getSize().y / 2)));
	}
}
void Weather::initRain()
{
	for (int j = 0; j < nbDrop; j++) {
		setRandPos(rainDrop[j]);
		rainDrop[j].setFillColor(Color().Blue);
		window->draw(rainDrop[j]);
	}
}
void Weather::updateCloud()
{
	Vector2f pos = sun.getPosition();
	float i = -20;
	for (auto it = clouds.begin(); it != clouds.end(); ++it) {
		(*it).setPosition(Vector2f(pos.x + i, pos.y +30));
		(*it).setFillColor(c->grey);
		window->draw((*it));
		i += 20;
	}
}

void Weather::updateRain()
{
	if (!rain)
	{
		return;
	}
	for (int i = 0; i < nbDrop; i++) {
		Vector2f pos = rainDrop[i].getPosition();
		pos.y += height;
		if (pos.y > window->getSize().y)
			setRandPos(rainDrop[i]);
		else
			rainDrop[i].setPosition(pos); 
		window->draw(rainDrop[i]);
	}
}

void Weather::drawBackGround() {
	if (day) {
		RectangleShape rect(Vector2f(window->getSize().x, window->getSize().y));
		rect.setFillColor(Color().Cyan);
		window->draw(rect);
	}
	
}

void Weather::updateStars()
{
	if (day)
		return;
	Time elapsed = clock2.getElapsedTime();
	if (elapsed.asMilliseconds() >= 50	) {
		if (starColor == Color(135, 132, 1))
			starColor = Color(253, 245, 1);
		else
			starColor = Color(135, 132, 1);
		clock2.restart();
	}
	for (auto it = stars.begin(); it != stars.end(); ++it) {
		if(genRand(0,101)<10)
			(*it).setFillColor(starColor);
		window->draw((*it));
	}
	
}

void Weather::updateSun()
{
	Time elapsed = clock.getElapsedTime();
	Vector2f pos = sun.getPosition();
	if (day) {
		pos.x += 3.f;
		if (pos.x < window->getSize().x)
		{
			sun.setPosition(pos);
			window->draw(sun);
			if (rain)
				updateCloud();
		}
		else{
			day = false;
			rain = false;
			sun.setPosition(Vector2f(15.f, 15.f));
			clock.restart();
		}
	}
	else if (elapsed.asMilliseconds() >= 2000) {
		day = true;
		if (genRand(0, 4) > 1)
			rain = true;
	}
}
