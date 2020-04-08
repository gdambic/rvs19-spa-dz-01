#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
using namespace sf;

class Animation
{
public:
	Animation(Texture* texture, Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);

	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;

	float totalTime;
	float switchTime;
};

