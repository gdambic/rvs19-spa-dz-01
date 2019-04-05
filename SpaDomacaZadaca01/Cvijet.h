#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "dragonBones/SFMLFactory.h"
#include "dragonBones/SFMLArmatureDisplay.h"
#include "dataContainers.h"

class Cvijet {
private:
	// dragonBones asset paths
	static const std::string TEXTURE_PNG_PATH;
	static const std::string TEXTURE_JSON_PATH;
	static const std::string ARMATURE_JSON_PATH;
	static const int WALKING_SPEED;

	// SFML and DB object pointers
	sf::RenderWindow* window;
	dragonBones::SFMLFactory factory;
	sf::Texture texture;
	dragonBones::SFMLArmatureDisplay* armatureDisplay;

	// other vars
	std::string animation;
	position rasterPosition;
	position worldPosition;

	//private methods
	void setToStartingPosition(float x, float y);

public:
	Cvijet(sf::RenderWindow* window, float initialX, float initialY);
	~Cvijet();
	position* get_worldPosition();
	position* get_rasterPosition();
	std::string get_currentAnimation();
	void moveForward();
	void moveBackward();
	void changeAnimation(std::string animation, bool flip);
	void updateFactory(float deltaTime);
	void draw();
};