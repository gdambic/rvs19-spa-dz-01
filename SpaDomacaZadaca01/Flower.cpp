#include "Flower.h"

using namespace std;
Flower::Flower(RenderWindow* window, struct colors* c, Weather* weather) {
	this->window = window;
	this->c = c;
	this->weather = weather;
}
void Flower::draw() {
	Time elapsed1 = clock.getElapsedTime();
	if (elapsed1.asMilliseconds() >= 50)
	{
		updateScale();
		drawStem(c->green);
		drawPetal(c->blue);
		drawMainPart(c->yellow);
		drawLeaf(c->green);
	}
}
void Flower::updateScale() {
	float growRate = 0.02f;
	if (weather->getRain())
		incWater();
	else
		decWater();
	if (getScale() <= 2 && weather->getDay() && water >0)
		setScale(getScale() + growRate);
	if(getScale() > 1 && water <= 0)
		setScale(getScale() - growRate);
	
}
void Flower::drawStem(sf::Color c) {
	float h = stemHeight * scale;
	sf::RectangleShape rectangle(Vector2f(stemWidth * scale, h));
	rectangle.setFillColor(c);
	rectangle.setPosition(Vector2f(x, window->getSize().y-h));
	window->draw(rectangle);
}
void Flower::drawMainPart(sf::Color c) {

	sf::CircleShape shape(mainPartSize * scale);
	shape.setPosition(Vector2f(x + ((stemWidth * scale) / 2) - (mainPartSize*scale), window->getSize().y - (stemHeight + mainPartSize) * scale));
	shape.setFillColor(c);
	shape.setOutlineThickness(mainPartSize / 10.f);
	shape.setOutlineColor(Color(254, 56, 1));
	window->draw(shape);
	
}
void Flower::drawPetal(sf::Color c) {
	for (int i = 0; i < nbPetal; i++)
	{
		sf::CircleShape shape(petalSize * scale);
		shape.setFillColor(c);
		shape.setPosition(Vector2f(x + (stemWidth * scale) / 2, window->getSize().y - (stemHeight + mainPartSize/petalSize) * scale));
		shape.rotate((360/nbPetal) * i);
		shape.setOutlineThickness(petalSize/10.f);
		shape.setOutlineColor(sf::Color(1, 199, 254));
		window->draw(shape);
	}
}
void Flower::setScale(float scale)
{
	if (scale < 3 && scale > -1) {
		this->scale = scale;
	}
	
}
float Flower::getScale()
{
	return scale;
}
float Flower::getWater()
{
	return water;
}
void Flower::incWater()
{
	if(water<10)
		water += 0.1f;
}
void Flower::decWater()
{
	if(water>0)
		water -= 0.1f;
}
void Flower::drawLeaf(sf::Color c)
{
	sf::ConvexShape convex;
	convex.setPointCount(4);
	convex.setPoint(0, sf::Vector2f(0.f * scale, 10.f * scale));
	convex.setPoint(1, sf::Vector2f(50.f * scale, 0.f * scale));
	convex.setPoint(2, sf::Vector2f(100.f * scale, 10.f * scale));
	convex.setPoint(3, sf::Vector2f(50.f * scale, 20.f * scale));
	convex.setFillColor(c);
	convex.setPosition(Vector2f(x + (stemWidth * scale)-10.f, window->getSize().y - (stemHeight* scale)/2));
	window->draw(convex);
}

