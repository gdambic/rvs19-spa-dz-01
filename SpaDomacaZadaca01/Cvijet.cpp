#include "Cvijet.h"
#define PI 3.14159265358979323846

double lerpNumber(double a, double b, double t) {
	return a + (b - a) * t;
}

Color lerpColor(Color* ColorA, Color* ColorB, double t) {
	return Color(lerpNumber(ColorA->r, ColorB->r, t),
		lerpNumber(ColorA->g, ColorB->g, t),
		lerpNumber(ColorA->b, ColorB->b, t));
}

int randomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

double toRadians(double degrees) {
	return degrees * (PI / 180);
}

Cvijet::Cvijet(RenderWindow* Window)
{
	this->Window = Window;
	this->sunAngle = PI / 6;
	this->moonAngle = PI + PI / 6;
	this->sunSpeed = 1;
}

void Cvijet::draw()
{
	// Variables

	Color dayColor(113, 172, 255);
	Color nightColor(23, 34, 50);

	Vector2u windowSize = Window->getSize();
	Vector2f screenMiddle(windowSize.x / 2, windowSize.y / 2);
	Vector2f sunPathCenter(screenMiddle.x, 400);

	// Sun

	int sunRadius = 30;
	int sunDistanceToCenter = 330;

	Vector2f sunOffset(sunDistanceToCenter * -cos(sunAngle), sunDistanceToCenter * -sin(sunAngle));

	CircleShape sun(sunRadius);
	sun.setFillColor(Color(253, 217, 34));
	sun.setOrigin(sunRadius, sunRadius);
	sun.setPosition(sunPathCenter + sunOffset);

	// Sun animation

	sunAngle += toRadians(1 * sunSpeed);
	if (sunAngle > 2 * PI) { sunAngle -= 2 * PI; }

	sunSpeed = 0.5 + 0.5 * pow(cos(sunAngle), 2);
	sun.setRadius(sunRadius * (0.5 + pow(sin(sunAngle), 2)));

	// Moon

	int moonRadius = 30;
	int moonDistanceToCenter = 330;

	Vector2f moonOffset(moonDistanceToCenter * -cos(moonAngle), moonDistanceToCenter * -sin(moonAngle));

	CircleShape moon(moonRadius);
	moon.setFillColor(Color(200,200,200));
	moon.setOrigin(moonRadius, moonRadius);
	moon.setPosition(sunPathCenter + moonOffset);

	// Moon animation

	moonAngle += toRadians(1 * sunSpeed);
	if (moonAngle > 2 * PI) { moonAngle -= 2 * PI; }

	sunSpeed = 0.5 + 0.5 * pow(cos(moonAngle), 2);
	moon.setRadius(moonRadius * (0.5 + pow(sin(moonAngle), 2)));

	// Sky

	double nightProgression = max(0.0, sin(sunAngle));

	RectangleShape sky(Vector2f(1000, 1000));
	sky.setFillColor(lerpColor(&nightColor, &dayColor, nightProgression));
	sun.setFillColor(Color(253, 217, 34, nightProgression * 255));
	moon.setFillColor(Color(200, 200, 200, 255 - nightProgression * 255));

	// Floor

	RectangleShape floor(Vector2f(1000, 300));
	floor.setFillColor(Color(0, 255, 0));
	floor.setOrigin(500, 0);
	floor.setPosition(screenMiddle.x, 500);

	// Inner circle

	int innerCircleRadius = 60;

	CircleShape innerCircle(innerCircleRadius);
	innerCircle.setFillColor(Color(255, 255, 0));
	innerCircle.setOrigin(innerCircleRadius, innerCircleRadius);
	innerCircle.setPosition(screenMiddle);

	// Stem

	RectangleShape stem(Vector2f(10, 300));
	stem.setFillColor(Color(0, 255, 0));
	stem.setOrigin(5, 0);
	stem.setPosition(screenMiddle);

	// Petals

	int numberOfPetals = 6;
	CircleShape* petals = new CircleShape[numberOfPetals];

	int petalRadius = 50;

	for (unsigned int i = 0; i < 6; i++)
	{
		double angle = PI / 3 * i;

		double offsetX = 1.5 * cos(angle);
		double offsetY = 1.5 * sin(angle);

		CircleShape petal(petalRadius);
		petal.setFillColor(Color(255, 255, 255));
		petal.setOrigin(petalRadius + petalRadius * offsetX, petalRadius + petalRadius * offsetY);
		petal.setPosition(screenMiddle);

		petals[i] = petal;
	}

	// Draw to window

	Window->draw(sky);
	Window->draw(sun);
	Window->draw(moon);
	Window->draw(floor);
	Window->draw(stem);
	for (unsigned int i = 0; i < numberOfPetals; i++) { Window->draw(petals[i]); }
	Window->draw(innerCircle);

	// Cleanup

	delete[] petals;
}
