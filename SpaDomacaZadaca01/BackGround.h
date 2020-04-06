#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class BackGround
{
public:
	BackGround(std::string image, sf::RenderWindow* window);
	~BackGround();
	void backGroundChange();
private:
	sf::Texture texture;
	
};

