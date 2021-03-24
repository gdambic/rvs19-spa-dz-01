#pragma once
#include <SFML/Graphics.hpp>



class Cvijet 
{
public:

	Cvijet(sf::RenderWindow& window,sf::Texture* texture,sf::Vector2u imageCount,float switchTime);
	
	void update(int row, float deltaTime);
	void draw(sf::RenderWindow& window);
public:
	sf::IntRect uvRect;

private:
	sf::RenderWindow& m_window;
	sf::RectangleShape flower;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;




	

	
};