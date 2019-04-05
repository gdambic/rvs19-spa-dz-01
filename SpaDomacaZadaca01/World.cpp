#include "World.h"


World::World(sf::RenderWindow* parentWindow, std::string worldName, int noOfBackLayers) {
	window = parentWindow;
	backLayers = noOfBackLayers;

	worldLayerTextures = new std::vector<sf::Texture>;
	worldLayerSprites = new std::vector<sf::Sprite>;

	sf::Texture textureTmp;
	sf::Sprite spriteTmp;

	int layerNo = 0;
	while (textureTmp.loadFromFile("Assets\\Worlds\\" + worldName + "\\" + std::to_string(layerNo) + ".png")) {
		worldLayerTextures->push_back(textureTmp);
		layerNo++;
	}
	// SFML bug detected here?
	for (auto i = worldLayerTextures->begin(); i != worldLayerTextures->end(); ++i) {
		spriteTmp.setTexture(*i);
		worldLayerSprites->push_back(spriteTmp);
	}
	worldLayerSpritesCopy = new std::vector<sf::Sprite>(*worldLayerSprites);
}

World::~World() {
	delete worldLayerTextures;
	delete worldLayerSprites;
	delete worldLayerSpritesCopy;
}


void World::draw(position* mainCharacterPosition)
{
	double parallaxCoefficient = 1.0 / backLayers;
	int counter = 0;
	for (auto i = worldLayerSprites->begin(); i != worldLayerSprites->end(); ++i) {
		long posx = (long)(-mainCharacterPosition->get_x() * (1 + (counter - backLayers) * parallaxCoefficient)) % 1920;
		long posy = (long)(-mainCharacterPosition->get_y() * (1 + (counter - backLayers) * parallaxCoefficient)) % 1080;
		i->setPosition(posx, posy % 1080);
		worldLayerSpritesCopy->at(counter).setPosition(posx % 1920 + 1920, posy % 1080);
		window->draw(*i);
		window->draw(worldLayerSpritesCopy->at(counter));
		counter++;
	}
}