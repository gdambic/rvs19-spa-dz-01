#include "Droplet.h"
#include "util.h"
#include "Scene.h"

const float Droplet::MIN_WIDTH = 1.f;
const float Droplet::MAX_WIDTH = 4.f;
const float Droplet::MIN_HEIGHT = 15.f;
const float Droplet::MAX_HEIGHT = 45.f;
const float Droplet::MIN_VELOCITY = 3.f;
const float Droplet::MAX_VELOCITY = 12.f;
const float Droplet::MIN_GRAVITY = 0.2f;
const float Droplet::MAX_GRAVITY = 0.8f;

float Droplet::nextFloat(float origin, float bound) {
	return origin + (bound - origin) * dis(gen);
}

Droplet::Droplet(
	std::default_random_engine& gen
) : AnimatedElement(sf::Vector2f(0, 0), sf::Vector2f(0, 0)),
	gen(gen), dis(0.f, 1.f) {
	width = nextFloat(MIN_WIDTH, MAX_WIDTH);
	float height = util::map(width, MIN_WIDTH, MAX_WIDTH, MIN_HEIGHT, MAX_HEIGHT);
	position.x = nextFloat(0.0, Scene::WINDOW_WIDTH - width);
	position.y = -MAX_HEIGHT * 2;
	velocity.y = util::map(width, MIN_WIDTH, MAX_WIDTH, MIN_VELOCITY, MAX_VELOCITY);
	gravity = util::map(width, MIN_WIDTH, MAX_WIDTH, MIN_VELOCITY, MAX_VELOCITY);
	fallHeight = util::map(width, MIN_WIDTH, MAX_WIDTH, Scene::WINDOW_HEIGHT / 2, Scene::WINDOW_HEIGHT);
	
	droplet.setPosition(position);
	droplet.setSize(sf::Vector2f(width, height));
	droplet.setFillColor(sf::Color::Cyan);
}

void Droplet::draw(sf::RenderWindow& window) {
	window.draw(droplet);
}

void Droplet::update(const sf::Time& deltaTime) {
	position.y += velocity.y * deltaTime.asSeconds();
	velocity.y += gravity;
	droplet.setPosition(position);
}

bool Droplet::hasFallen() const {
	return position.y > fallHeight;
}
