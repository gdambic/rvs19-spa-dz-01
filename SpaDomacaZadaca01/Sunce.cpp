#include "Sunce.h"
#include <math.h>

Sunce::Sunce()
{
	this->window = window;
	this->os_x = os_x;
	this->os_y = os_y;
	this->R = R;
	this->r = r;
	this->mode = true;
	kut = 180;
}

Sunce::Sunce(RenderWindow* window, int os_x, int os_y, int R, int r)
{
	this->window = window;
	this->os_x = os_x;
	this->os_y = os_y;
	this->R = R;
	this->r = r;
	this->mode = true;
	kut = 180;
}

void Sunce::draw()
{
	Time t1 = clock.getElapsedTime();
	if (t1.asMilliseconds() > 10) {
		//if (kut > 292.4) kut = 247.6;
		if (kut > 360) kut = 180;
		kut += 0.2;
		clock.restart();
	}
	
	#define PI 3.14159265
	x = os_x + (R * cos(kut * PI / 180));
	y = os_y + (R * sin(kut * PI / 180));
	for (float i = 0; i < 720; i += 0.5) {
		RectangleShape line(Vector2f(20, 3 * window->getSize().x));
		line.setFillColor(Color(255, 255, 200, 5));
		line.setPosition(x, y);
		line.rotate(i);
		window->draw(line);
	}
	for (int i = r; i > 0; i--) {
		CircleShape sunce(i);
		sunce.setPosition(x + (r-i) -r, y + (r - i) - r);
		sunce.setFillColor(Color(255, 240, 255 * (r - i) / r));
		window->draw(sunce);
	}
	
}

float Sunce::get_kut()
{
	return kut;
}
