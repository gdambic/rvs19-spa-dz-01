#include "Scene.h"
#include "Sun.h"

const int Scene::WINDOW_WIDTH = 800;
const int Scene::WINDOW_HEIGHT = 600;
const sf::Color Scene::BACKGROUND_COLOR = sf::Color(0x87ceeb); // sky blue

Scene::Scene(sf::RenderWindow* window) {
	this->window = window;

	animatedElements.push_back(new Sun(
		sf::Vector2f(0, 0),
		sf::Vector2f(75, 0)
	));
}

Scene::~Scene() {
	for (auto& animatedElement : animatedElements) {
		delete animatedElement;
	}
	animatedElements.clear();
}

void Scene::draw() {
	window->clear(BACKGROUND_COLOR);

	for (auto& animatedElement : animatedElements) {
		animatedElement->draw(*window);
	}

	window->display();
}

void Scene::update(const sf::Time& deltaTime) {
	for (auto& animatedElement : animatedElements) {
		animatedElement->update(deltaTime);
	}
}
