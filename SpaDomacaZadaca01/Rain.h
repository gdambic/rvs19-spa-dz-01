#pragma once

#include "Droplet.h"

class Rain : public AnimatedElement {
private:
	static const int RAIN_DENSITY;

	std::vector<Droplet*> rain;
	std::default_random_engine gen;

public:
	Rain();
	~Rain();
	void addToRain();
	void draw(sf::RenderWindow& window) override;
	void update(const sf::Time& deltaTime) override;
};
