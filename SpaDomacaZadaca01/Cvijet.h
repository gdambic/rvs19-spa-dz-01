#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Cvijet
{
private:
	struct Cloud {
		int x;
		int y; 
		int sizex; 
		int sizey;
	};
	struct WaveGroup {
		int x, y;
	};
	sf::RenderWindow* window;
	float x, y;
	std::vector<Cloud> clouds;
	std::vector<WaveGroup> wavegroups;
	void generateClouds();
	void generateWaves();
public:
	Cvijet(sf::RenderWindow* window);
	void draw();
};

