#include "Scene.h"
#include "Sun.h"
#include "Moon.h"
#include "Rectangle.h"
#include "Flower.h"
#include "Rain.h"
#include "util.h"

const int Scene::WINDOW_WIDTH = 800;
const int Scene::WINDOW_HEIGHT = 600;
const float Scene::PI = 3.1415927f;
const sf::Color Scene::NOON_COLOR(135, 206, 235);

Scene::Scene(sf::RenderWindow* window) {
	this->window = window;
	this->backgroundColor = getSkyColorFromSun(PI);

	sf::Vector2f celestialOrbitCenter(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	float celestialRadius = 50.f;
	float celestialOrbitRadius = WINDOW_HEIGHT / 2 - celestialRadius;
	float celestialAngularVelocity = PI / 8;
	animatedElements.push_back(new Sun(
		celestialOrbitCenter,
		celestialRadius,
		celestialOrbitRadius,
		PI,
		celestialAngularVelocity
	));
	animatedElements.push_back(new Moon(
		this->backgroundColor,
		celestialOrbitCenter,
		celestialRadius,
		celestialOrbitRadius,
		2 * PI,
		celestialAngularVelocity
	));

	animatedElements.push_back(new Rectangle(
		sf::Vector2f(0, WINDOW_HEIGHT / 2),
		sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 2),
		sf::Color(65, 152, 10)
	));

	animatedElements.push_back(new Flower(
		sf::Vector2f(150.f, 333.f),
		sf::Vector2f(0, 0.2f),
		sf::Color::White,
		180.f
	));
	animatedElements.push_back(new Flower(
		celestialOrbitCenter,
		sf::Vector2f(0, 0.1f),
		sf::Color::Red,
		234.f
	));
	animatedElements.push_back(new Flower(
		sf::Vector2f(600.f, 320.f),
		sf::Vector2f(0, 0.3f),
		sf::Color::Yellow,
		201.f
	));

	animatedElements.push_back(new Rain());
}

Scene::~Scene() {
	for (auto& animatedElement : animatedElements) {
		delete animatedElement;
	}
	animatedElements.clear();
}

void Scene::draw() {
	window->clear(backgroundColor);

	for (auto& animatedElement : animatedElements) {
		animatedElement->draw(*window);
	}

	window->display();
}

void Scene::update(const sf::Time& deltaTime) {
	for (auto& animatedElement : animatedElements) {
		animatedElement->update(deltaTime);

		if (dynamic_cast<Sun*>(animatedElement)) {
			Sun* sun = dynamic_cast<Sun*>(animatedElement);
			backgroundColor = getSkyColorFromSun(sun->getAngle());
		} else if (dynamic_cast<Moon*>(animatedElement)) {
			Moon* moon = dynamic_cast<Moon*>(animatedElement);
			moon->setCrescentCoverColor(backgroundColor);
		}
	}
}

sf::Color Scene::getSkyColorFromSun(float angle) {
	float absoluteAngle = std::fmod(angle, 2 * PI);
	float piOver2 = PI / 2;
	float pi3Over2 = 3 * PI / 2;
	float pi2 = 2 * PI;
	float angleRatio;

	if (absoluteAngle > piOver2 && absoluteAngle < pi3Over2) {
		angleRatio = util::map(absoluteAngle, piOver2, pi3Over2, 0.f, 1.f);
	} else if (absoluteAngle >= pi3Over2 && absoluteAngle <= pi2) {
		angleRatio = util::map(absoluteAngle, pi3Over2, pi2, 1.f, 0.5f);
	} else {
		angleRatio = util::map(absoluteAngle, 0, piOver2, 0.5f, 0.f);
	}

	return sf::Color(
		NOON_COLOR.r * angleRatio,
		NOON_COLOR.g * angleRatio,
		NOON_COLOR.b * angleRatio
	);
}
