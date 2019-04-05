#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "dataContainers.h"

class World {
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture>* worldLayerTextures;
	std::vector<sf::Sprite>* worldLayerSprites, * worldLayerSpritesCopy;
	int backLayers;

public:
	World(sf::RenderWindow* parentWindow, std::string worldName, int noOfFrontLayers);
	~World();
	void draw(position* mainCharacterPosition);

};