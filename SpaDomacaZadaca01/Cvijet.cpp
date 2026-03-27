#include "Cvijet.h"
//horten sia

Cvijet::Cvijet(sf::RenderWindow *windows)
{
	this->windows = windows;
	
	outflower.setPointCount(20);

	outflower.setPoint(0, sf::Vector2f(191.f, 161.f));
	outflower.setPoint(1, sf::Vector2f(160.f, 156.f));
	outflower.setPoint(2, sf::Vector2f(126.f, 184.f));
	outflower.setPoint(3, sf::Vector2f(134.f, 225.f));
	outflower.setPoint(4, sf::Vector2f(164.f, 242.f));
	outflower.setPoint(5, sf::Vector2f(148.f, 271.f));
	outflower.setPoint(6, sf::Vector2f(158.f, 312.f));
	outflower.setPoint(7, sf::Vector2f(199.f, 323.f));
	outflower.setPoint(8, sf::Vector2f(234.f, 290.f));
	outflower.setPoint(9, sf::Vector2f(262.f, 321.f));
	outflower.setPoint(10, sf::Vector2f(305.f, 316.f));
	outflower.setPoint(11, sf::Vector2f(321.f, 285.f));
	outflower.setPoint(12, sf::Vector2f(302.f, 241.f));
	outflower.setPoint(13, sf::Vector2f(333.f, 228.f));
	outflower.setPoint(14, sf::Vector2f(344.f, 184.f));
	outflower.setPoint(15, sf::Vector2f(318.f, 160.f));
	outflower.setPoint(16, sf::Vector2f(277.f, 159.f));
	outflower.setPoint(17, sf::Vector2f(264.f, 126.f));
	outflower.setPoint(18, sf::Vector2f(233.f, 111.f));
	outflower.setPoint(19, sf::Vector2f(198.f, 130.f));


	inflower.setPointCount(8);

	inflower.setPoint(0, sf::Vector2f(235.f, 258.f));
	inflower.setPoint(1, sf::Vector2f(209.f, 249.f));
	inflower.setPoint(2, sf::Vector2f(198.f, 221.f));
	inflower.setPoint(3, sf::Vector2f(208.f, 195.f));
	inflower.setPoint(4, sf::Vector2f(236.f, 183.f));
	inflower.setPoint(5, sf::Vector2f(261.f, 194.f));
	inflower.setPoint(6, sf::Vector2f(272.f, 221.f));
	inflower.setPoint(7, sf::Vector2f(262.f, 246.f));

	line.setPointCount(4);

	line.setPoint(3, sf::Vector2f(239.f, 560.f));
	line.setPoint(2, sf::Vector2f(230.f, 560.f));
	line.setPoint(1, sf::Vector2f(230.f, 280.f));
	line.setPoint(0, sf::Vector2f(239.f, 280.f));

	petal1.setPointCount(8);

	petal1.setPoint(0, sf::Vector2f(230.f, 438.f));
	petal1.setPoint(1, sf::Vector2f(183.f, 428.f));
	petal1.setPoint(2, sf::Vector2f(155.f, 405.f));
	petal1.setPoint(3, sf::Vector2f(136.f, 375.f));
	petal1.setPoint(4, sf::Vector2f(128.f, 334.f));
	petal1.setPoint(5, sf::Vector2f(159.f, 343.f));
	petal1.setPoint(6, sf::Vector2f(196.f, 367.f));
	petal1.setPoint(7, sf::Vector2f(220.f, 397.f));

	petal2 = petal1;

	fond.setPointCount(4);
	fond.setPoint(0, sf::Vector2f(0.f, 0.f));
	fond.setPoint(1, sf::Vector2f(0.f, 600.f));
	fond.setPoint(2, sf::Vector2f(800.f, 600.f));
	fond.setPoint(3, sf::Vector2f(800.f, 0.f));

	astro.setRadius(45.f);
	astro.setPointCount(60); 
	astro.setOrigin(45.f, 45.f);
	astro.setPosition(-60.f, 90.f);
	
	
	outflower.setFillColor(sf::Color(224, 0, 138));
	inflower.setFillColor(sf::Color(245, 204, 81));
	line.setFillColor(sf::Color(1, 121, 5));
	petal1.setFillColor(sf::Color(2, 161, 8));
	petal2.setFillColor(sf::Color(2, 161, 8));
	fond.setFillColor(sf::Color(0, 220, 240));astro.setFillColor(sf::Color(255, 220, 70));

	petal2.setOrigin(179.f, 386.f);
	petal2.setRotation(90.f);
	petal2.setPosition(290.f, 420.f);

	
}

void Cvijet::draw()
{
	float elapsed = time.getElapsedTime().asSeconds();

	if (petal2.getPosition().y < 650.f)
	{
		if (elapsed > 0.016f)
		{
			time.restart();

			float random_x = ((rand() % 10) - 5) * 0.3f;
			float random_rot = random_x * -0.8f;

			float new_x = petal2.getPosition().x + random_x;
			float new_y = petal2.getPosition().y + 1.2f;

			petal2.setPosition(new_x, new_y);
			petal2.rotate(random_rot);
		}
	}

	float astroSpeed = 4.f;
	if (astroClock.getElapsedTime().asSeconds() > 0.01f)
	{
		astroClock.restart();

		astro.move(astroSpeed, 0.f);

		float x = astro.getPosition().x;
		float radius = astro.getRadius();

		if (x - radius > 800.f)
		{
			isMoon = !isMoon;

			if (isMoon)
			{
				astro.setRadius(32.f);
				astro.setOrigin(32.f, 32.f);
				astro.setFillColor(sf::Color(230, 230, 240));
				fond.setFillColor(sf::Color(15, 20, 60));
			}
			else
			{
				astro.setRadius(45.f);
				astro.setOrigin(45.f, 45.f);
				astro.setFillColor(sf::Color(255, 220, 70));
				fond.setFillColor(sf::Color(0, 220, 240));
			}

			astro.setPosition(-60.f, 90.f);
		}
	}

	windows->draw(fond);
	windows->draw(astro);
	windows->draw(line);
	windows->draw(outflower);
	windows->draw(inflower);
	windows->draw(petal1);
	windows->draw(petal2);
}