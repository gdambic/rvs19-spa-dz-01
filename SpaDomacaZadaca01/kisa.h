#pragma once
#include<SFML/Graphics.hpp>
class kisa
{
private:
	sf::Texture texture;
	sf::RenderWindow* window;

	
public:
	kisa();
	void prozor(sf::RenderWindow* window);

	sf::Sprite crtaj( int x, int y);
};

