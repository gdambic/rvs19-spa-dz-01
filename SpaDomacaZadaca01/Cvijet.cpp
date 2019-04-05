#include "Cvijet.h"


const std::string Cvijet::TEXTURE_PNG_PATH = "Assets\\Characters\\MainCharacter\\MainCharacter_tex.png";
const std::string Cvijet::TEXTURE_JSON_PATH = "Assets\\Characters\\MainCharacter\\MainCharacter_tex.json";
const std::string Cvijet::ARMATURE_JSON_PATH = "Assets\\Characters\\MainCharacter\\MainCharacter_ske.json";
const int Cvijet::WALKING_SPEED = 2;


Cvijet::Cvijet(sf::RenderWindow* parentWindow, float initialX, float initialY)
{
	window = parentWindow;

	texture.loadFromFile(TEXTURE_PNG_PATH);
	factory.loadDragonBonesData(ARMATURE_JSON_PATH);
	factory.loadTextureAtlasData(TEXTURE_JSON_PATH, &texture);

	armatureDisplay = new dragonBones::SFMLArmatureDisplay("Armature");
	setToStartingPosition(initialX, initialY);
}

Cvijet::~Cvijet() {
	delete armatureDisplay;
}

position* Cvijet::get_worldPosition()
{
	return &worldPosition;
}

position* Cvijet::get_rasterPosition()
{
	return &rasterPosition;
}

std::string Cvijet::get_currentAnimation() {
	return animation;
}

void Cvijet::moveForward() {
	worldPosition.set_x(worldPosition.get_x() + WALKING_SPEED);
	rasterPosition.set_x(rasterPosition.get_x() + WALKING_SPEED);
	//armatureDisplay->setPosition({ (float)(rasterPosition.get_x()), (float)(rasterPosition.get_y()) });
}

void Cvijet::moveBackward() {
	worldPosition.set_x(worldPosition.get_x() - WALKING_SPEED);
	rasterPosition.set_x(rasterPosition.get_x() - WALKING_SPEED);
	//armatureDisplay->setPosition({ (float)(rasterPosition.get_x()), (float)(rasterPosition.get_y()) });
}

void Cvijet::updateFactory(float deltaTime) {
	factory.update(deltaTime);
}

void Cvijet::draw()
{
	window->draw(*armatureDisplay);
}

void Cvijet::setToStartingPosition(float x, float y)
{
	animation = "Still";
	armatureDisplay->getAnimation()->play(animation);
	worldPosition.set(0, 0);
	rasterPosition.set((int)x, (int)y);
	armatureDisplay->setPosition({ x, y });
}

void Cvijet::changeAnimation(std::string newAnimation, bool flip) {
	int repetition = -1;
	std::string currentAnimation = armatureDisplay->getAnimation()->getLastAnimationName();
	bool animationCompleted = armatureDisplay->getAnimation()->getLastAnimationState()->isCompleted();
	if ((currentAnimation == "Jump" || currentAnimation == "WalkJump") && !animationCompleted) return;
	if (newAnimation == "Jump" || newAnimation == "WalkJump") {
		repetition = 1;
	}
	animation = newAnimation;
	armatureDisplay->getArmature()->setFlipX(flip);
	armatureDisplay->getAnimation()->play(animation, repetition);
}