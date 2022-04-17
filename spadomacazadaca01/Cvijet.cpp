#include "Cvijet.h"
#include<ctime>

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
  transform.translate(-circle_center.x, -circle_center.y);
  int i = 0;
  for(auto &petal: petals1) {
	 petal.setFillColor(sf::Color(223,24,130));
    petal.setPointCount(3);
    petal.setPoint(0, sf::Vector2f(circle_radius-15, -35));
    petal.setPoint(1, sf::Vector2f(circle_radius-15+75, 0));
    petal.setPoint(2, sf::Vector2f(circle_radius-15, 35));
    petal.setRotation(i * 90);
    i++;
  }
  int z = 0;
  for (auto& petal : petals2) {
	  petal.setFillColor(sf::Color(255, 0, 255));
	  petal.setPointCount(3);
	  petal.setPoint(0, sf::Vector2f(circle_radius - 15, -35));
	  petal.setPoint(1, sf::Vector2f(circle_radius - 15 + 75, 0));
	  petal.setPoint(2, sf::Vector2f(circle_radius - 15, 35));
	  petal.setRotation(z * 90 + 45);
	  z++;
  }
  transform2.translate(10, 550);
  int y = 0;
  for (auto& grasss1 : grass1) {
	  grasss1.setFillColor(sf::Color(0, 230, 20));
	  grasss1.setPointCount(5);
	  grasss1.setPoint(0, sf::Vector2f(0, 0));
	  grasss1.setPoint(1, sf::Vector2f(5, -17));
	  grasss1.setPoint(2, sf::Vector2f(13, -35));
	  grasss1.setPoint(3, sf::Vector2f(15, -15));
	  grasss1.setPoint(4, sf::Vector2f(10, 0));
	  grasss1.move(sf::Vector2f(get_rnd(35, 75) * y, 15));
	  y++;
  }
  int p = 0;
  for (auto& grasss2 : grass2) {
	  grasss2.setFillColor(sf::Color(15, 220, 20));
	  grasss2.setPointCount(5);
	  grasss2.setPoint(0, sf::Vector2f(0, 0));
	  grasss2.setPoint(1, sf::Vector2f(-5, -17));
	  grasss2.setPoint(2, sf::Vector2f(-13, -35));
	  grasss2.setPoint(3, sf::Vector2f(-15, -15));
	  grasss2.setPoint(4, sf::Vector2f(-10, 0));
	  grasss2.move(sf::Vector2f(get_rnd(35, 75) * p, get_rnd(15,35)));
	  p++;
  }
}

void Cvijet::set_raindrops() {
	float x = 1;
	int y = 1;
	float temp;
	for (auto& raindrop : raindrops) {
		raindrop.setSize(sf::Vector2f(5, 50));
		raindrop.setPosition(sf::Vector2f(raindropPosition));
		raindrop.setFillColor(sf::Color(0, 0, 205));

		if (raindropPosition.y > 550) {
			raindropPosition.y = 75;
		}
		if (y % 2 == 0) {
			temp = -15;
		}
		if (y % 2 == 1) {
			temp = 15;
		}
		raindropPosition.y += raindropVelocity;
		raindrop.setPosition(raindropPosition);
		raindrop.move(sf::Vector2f(x*35,y*temp ));
		x++;
		y++;
	}
}

void Cvijet::set_raindrops2() {
	float x = 1;
	int y = 1;
	float temp;
	for (auto& raindrop2 : raindrops2) {
		raindrop2.setSize(sf::Vector2f(5, 50));
		raindrop2.setPosition(sf::Vector2f(raindropPosition2));
		raindrop2.setFillColor(sf::Color(0, 0, 205));

		if (raindropPosition2.y > 550) {
			raindropPosition2.y = -150;
		}
		if (y % 2 == 0) {
			temp = -15;
		}
		if (y % 2 == 1) {
			temp = 15;
		}
		raindropPosition2.y += raindropVelocity;
		raindrop2.setPosition(raindropPosition2);
		raindrop2.move(sf::Vector2f(x * 35, y * temp));
		x++;
		y++;
	}
}

void Cvijet::set_circle()
{
	circle.setRadius(circle_radius);
	circle.setFillColor(sf::Color(255, 255, 0));
	circle.setOrigin(circle_center.x+circle_radius, circle_center.y+circle_radius);
}

void Cvijet::set_stem()
{
	stem.setFillColor(sf::Color(0, 255, 0));
	stem.setSize(sf::Vector2f(25, 265));
	stem.setPosition(285, 300);
}

void Cvijet::set_background() {
	sky.setFillColor(sf::Color(30, 144, 255));
	sky.setSize(sf::Vector2f(800,550));
	sky.setPosition(0, 0);
	ground.setFillColor(sf::Color(233, 116, 81));
	ground.setSize(sf::Vector2f(800,50));
	ground.setPosition(sf::Vector2f(0, 550));
}

void Cvijet::set_sun()
{
	sun.setRadius(35);
	sun.setFillColor(sf::Color(255, 255, 0));
	sun.setPosition(sf::Vector2f(750, -5));

}

void Cvijet::set_leaf()
{
	leaf.setFillColor(sf::Color(0, 255, 0));
	leaf.setPosition(285, 425);
	leaf.setPointCount(4);
	leaf.setPoint(0, sf::Vector2f(0, 0));
	leaf.setPoint(1, sf::Vector2f(75, -25));
	leaf.setPoint(2, sf::Vector2f(175, 50));
	leaf.setPoint(3, sf::Vector2f(50, 50));
}

int Cvijet::get_rnd(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Cvijet::set_cloud() {
	cloud.setPosition(315, 75);
	cloud.setPointCount(12);
	cloud.setPoint(0, sf::Vector2f(100, 0));
	cloud.setPoint(1, sf::Vector2f(150, -30));
	cloud.setPoint(2, sf::Vector2f(120, -70));
	cloud.setPoint(3, sf::Vector2f(75, -100));
	cloud.setPoint(4, sf::Vector2f(-20, -100));
	cloud.setPoint(5, sf::Vector2f(-50, -120));
	cloud.setPoint(6, sf::Vector2f(-100, -100));
	cloud.setPoint(7, sf::Vector2f(-150, -50));
	cloud.setPoint(8, sf::Vector2f(-120, -5));
	cloud.setPoint(9, sf::Vector2f(-50, 15));
	cloud.setPoint(10, sf::Vector2f(0, 5));
	cloud.setPoint(11, sf::Vector2f(30, 20));
}


void Cvijet::draw()
{
	set_circle();
	set_stem();
	set_leaf();
	set_sun();
	set_background();
	set_cloud();
	set_raindrops();
	set_raindrops2();

	window->draw(sky);
	window->draw(ground);
	window->draw(raindrop);
	window->draw(stem);
	window->draw(leaf);
	window->draw(sun);
	window->draw(cloud);

	for (auto& raindrop2 : raindrops2) {
		window->draw(raindrop2);
	}

	for (auto& raindrop : raindrops) {
		window->draw(raindrop);
	}

	for (auto& petal : petals2) {
		window->draw(petal, transform);
	}
	for (auto& petal : petals1) {
		window->draw(petal, transform);
	}

	window->draw(circle);

	for (auto& grasss1 : grass1) {
		window->draw(grasss1, transform2);
	}
	for (auto& grasss2 : grass2) {
		window->draw(grasss2, transform2);
	}
}