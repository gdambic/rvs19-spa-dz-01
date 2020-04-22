#include "Cvijet.h"





Cvijet::Cvijet(RenderWindow * Window)
{
	this->Window = Window;
	this->clock = Clock::Clock();
}

void Cvijet::draw()
{
	RectangleShape line(Vector2f(300, 5));
	line.rotate(90);
	line.setPosition(145, 130);
	line.setFillColor(Color::Green);
	Window->draw(line);

	ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, Vector2f(140, 350));
	convex.setPoint(1, Vector2f(230, 160));
	convex.setPoint(2, Vector2f(280, 170));
	convex.setPoint(3, Vector2f(270, 210));
	convex.setFillColor(Color::Green);
	Window->draw(convex);

	CircleShape circle1(25);
	circle1.setPosition(120, 30);
	circle1.setFillColor(Color::Yellow);
	Window->draw(circle1);

	CircleShape circle2(25);
	circle2.setFillColor(Color::Yellow);
	circle2.setPosition(85, 50);
	Window->draw(circle2);

	CircleShape circle3(25);
	circle3.setFillColor(Color::Yellow);
	circle3.setPosition(75, 90);
	Window->draw(circle3);

	CircleShape circle4(25);
	circle4.setFillColor(Color::Yellow);
	circle4.setPosition(155, 50);
	Window->draw(circle4);

	CircleShape circle5(25);
	circle5.setFillColor(Color::Yellow);
	circle5.setPosition(170, 90);
	Window->draw(circle5);

	CircleShape circle6(25);
	circle6.setFillColor(Color::Yellow);
	circle6.setPosition(140, 120);
	Window->draw(circle6);

	CircleShape circle7(25);
	circle7.setFillColor(Color::Yellow);
	circle7.setPosition(100, 120);
	Window->draw(circle7);

	CircleShape circle(50);
	circle.setFillColor(Color::Blue);
	circle.setPosition(95, 50);
	Window->draw(circle);

	Int32 t = clock.getElapsedTime().asMilliseconds();

	if (t > 500)
	{
		if (velicina == true)
		{
			radijus = radijus + 5.f;
		}
		else
		{
			radijus = radijus - 5.f;
		}
		if (radijus > 35)
		{
			velicina = false;
		}
		else if (radijus < 5)
		{
			velicina = true;
		}
		clock.restart();
	}

	CircleShape circ(radijus);
	circ.setPosition(107, 65);
	circ.setFillColor(Color::Yellow);
	Window->draw(circ);

}



