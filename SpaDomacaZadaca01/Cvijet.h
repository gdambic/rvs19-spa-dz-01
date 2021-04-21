#pragma once
#include<string>
#include <SFML/Graphics.hpp>
class Cvijet
{
private:
	sf::RenderWindow& classWindow;

	sf::RectangleShape head;
	sf::RectangleShape body;

	sf::Texture headTexture;
	sf::Texture bodyTexture;

	sf::Vector2f position;
	sf::Vector2f headSize;
	sf::Vector2f bodySize;

	float angleStep = 0.5f;
	std::string defaultHeadTexture = "AlgebraFlower.png";
	std::string defaultBodyTexture = "AlgebraStem.png";

	float totalAngle{ 0.0f };
	float tiltSpeed{ 60.0f };
	bool toRight{ true };

public:
	Cvijet(sf::RenderWindow& window, float size, sf::Vector2f pos);
	void set_angleStep(float angleStep);
	void draw(float deltaTime, float& speed); //Speed ide kao referenca jer alternira kroz main
	void set_textures(std::string headFileName, std::string bodyFileName);
	void set_tiltOffstet(float angle);
};


