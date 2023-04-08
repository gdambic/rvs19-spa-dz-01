#include "Cvijet.h"
#include <Windows.h>
#include <iostream>

void Cvijet::draw(RenderWindow& window)
{
	// central part of peach flower

	PEACH_FLOWER_BASE.setPosition(300, 150);
	PEACH_FLOWER_BASE.setRadius(70);
	PEACH_FLOWER_BASE.setFillColor(Color(222, 130, 134));
	PEACH_FLOWER_BASE.setOutlineColor(Color(137, 36, 65));
	PEACH_FLOWER_BASE.setOutlineThickness(5);

	// inner circles for central part of peach flower

	INNER_CIRCLE_01.setPosition(340, 180);
	INNER_CIRCLE_01.setRadius(5);
	INNER_CIRCLE_01.setFillColor(Color(110, 44, 0));

	INNER_CIRCLE_02.setPosition(380, 180);
	INNER_CIRCLE_02.setRadius(5);
	INNER_CIRCLE_02.setFillColor(Color(110, 44, 0));

	INNER_CIRCLE_03.setPosition(330, 230);
	INNER_CIRCLE_03.setRadius(5);
	INNER_CIRCLE_03.setFillColor(Color(110, 44, 0));

	INNER_CIRCLE_04.setPosition(370, 260);
	INNER_CIRCLE_04.setRadius(5);
	INNER_CIRCLE_04.setFillColor(Color(110, 44, 0));

	INNER_CIRCLE_05.setPosition(400, 230);
	INNER_CIRCLE_05.setRadius(5);
	INNER_CIRCLE_05.setFillColor(Color(110, 44, 0));

	// peach flower petals

	PEACH_FLOWER_CIRCLE_01.setPosition(218, 100);
	PEACH_FLOWER_CIRCLE_01.setRadius(55);
	PEACH_FLOWER_CIRCLE_01.setFillColor(Color(222, 130, 134));

	PEACH_FLOWER_CIRCLE_02.setPosition(218, 210);
	PEACH_FLOWER_CIRCLE_02.setRadius(60);
	PEACH_FLOWER_CIRCLE_02.setFillColor(Color(222, 130, 134));

	PEACH_FLOWER_CIRCLE_03.setPosition(415, 100);
	PEACH_FLOWER_CIRCLE_03.setRadius(50);
	PEACH_FLOWER_CIRCLE_03.setFillColor(Color(222, 130, 134));

	PEACH_FLOWER_CIRCLE_04.setPosition(410, 200);
	PEACH_FLOWER_CIRCLE_04.setRadius(60);
	PEACH_FLOWER_CIRCLE_04.setFillColor(Color(222, 130, 134));

	PEACH_FLOWER_CIRCLE_05.setPosition(308, 40);
	PEACH_FLOWER_CIRCLE_05.setRadius(60);
	PEACH_FLOWER_CIRCLE_05.setFillColor(Color(222, 130, 134));

	/*
	PEACH_FLOWER_CIRCLE_06.setPosition(325, 280);
	PEACH_FLOWER_CIRCLE_06.setRadius(45);
	PEACH_FLOWER_CIRCLE_06.setFillColor(Color(222, 130, 134));
	*/
	

	// support branch for the peach flower
	
	PEACH_BRANCH.setPosition(360, 290);
	PEACH_BRANCH.setSize(Vector2f(20, 300));
	PEACH_BRANCH.setFillColor(Color(110, 44, 0));

	// sun animation

	SUN.setPosition(10, 10);
	SUN.setRadius(30.0);
	SUN.setFillColor(Color(253, 218, 13));

	if (rast_sunca)
	{
		velicina_sunca += 0.01;
		if (velicina_sunca >= 2.5)
		{
			rast_sunca = false;
		}
	}
	else
	{
		SUN.setFillColor(Color(255, 234, 0));
		velicina_sunca -= 0.01;
		if (velicina_sunca <= 1.0)
		{
			rast_sunca = true;
		}
	}

	SUN.setScale(velicina_sunca, velicina_sunca);

	
	// all draw functions

	window.draw(PEACH_FLOWER_BASE);
	window.draw(PEACH_FLOWER_CIRCLE_01);
	window.draw(PEACH_FLOWER_CIRCLE_02);
	window.draw(PEACH_FLOWER_CIRCLE_03);
	window.draw(PEACH_FLOWER_CIRCLE_04);
	window.draw(PEACH_FLOWER_CIRCLE_05);
	// window.draw(PEACH_FLOWER_CIRCLE_06);
	window.draw(PEACH_BRANCH);
	window.draw(INNER_CIRCLE_01);
	window.draw(INNER_CIRCLE_02);
	window.draw(INNER_CIRCLE_03);
	window.draw(INNER_CIRCLE_04);
	window.draw(INNER_CIRCLE_05);
	window.draw(SUN);
	
}
