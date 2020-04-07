#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "Cvijet.h"

void Cvijet::setup()
{
	background_setup();
	latice();
	stalak();
}

// sf::RectangleShape(sf::Vector2f(800.f, 600.f));
void Cvijet::background_setup()
{
	background = sf::RectangleShape(sf::Vector2f((float)windowsize[0] * 2, (float)windowsize[0] * 2));
	background.setOrigin((float)windowsize[0], (float)windowsize[0]);
	background.setRotation(90.f);
	background.setPosition(sf::Vector2f((float)windowsize[0] / 2, (float)windowsize[1]));
	texture_background.loadFromFile("textures/skybox.png");
	background.setTexture(&texture_background);

	sunmun = sf::RectangleShape(sf::Vector2f(58.f, 878.f));
	sunmun.setOrigin(29.f, 439.f);
	sunmun.setRotation(90.f);
	sunmun.setPosition(sf::Vector2f((float)windowsize[0] / 2, (float)windowsize[1]));
	texture_sunmun.loadFromFile("textures/sunmun-0.png");
	sunmun.setTexture(&texture_sunmun);
	sunmun.setScale(1.75f, 1.75f);
}

void Cvijet::latice()
{
	std::ifstream fin(flowerpoints);
	std::string line;
	std::string coordinate;

	while (getline(fin, line)) {
		std::vector<std::array<float, 2>> temp;
		std::array<float, 2> coords;
		std::stringstream ss(line);
		while (ss >> coords[0]) {
			ss >> coords[1];
			temp.push_back(coords);
		}
		petals.push_back(temp);
	}
	fin.close();

	petal_convex = new sf::ConvexShape[petals.size()];
	for (int i = 0; i < petals.size(); i++) {
		petal_convex[i].setPointCount(petals[i].size());
		for (int j = 0; j < petals[i].size(); j++) {
			petal_convex[i].setPoint(j, sf::Vector2f((float)petals[i][j][0], (float)petals[i][j][1]));
		}
		petal_convex[i].setScale(scale, scale);
		petal_convex[i].move(move[0], move[1]);
		petal_convex[i].setFillColor(sf::Color(255 - i/2, i*(3/2), i, 255));
	}

}

void Cvijet::stalak()
{
	std::ifstream fin(stalkpoints);
	std::string line;
	std::string coordinate;
	while (getline(fin, line)) {
		std::vector<std::array<float, 2>> temp;
		std::array<float, 2> coords;
		std::stringstream ss(line);
		while (ss >> coords[0]) {
			ss >> coords[1];
			temp.push_back(coords);
		}
		stalks.push_back(temp);
	}
	fin.close();

	stalk_convex = new sf::ConvexShape[stalks.size()];
	numbies = new sf::Text[stalks.size()];
	for (int i = 0; i < stalks.size(); i++) {
		stalk_convex[i].setPointCount(stalks[i].size());
		numbies[i].setString(char(i));
		numbies[i].setPosition(sf::Vector2f((float)stalks[i][0][0], (float)stalks[i][0][1]));
		for (int j = 0; j < stalks[i].size(); j++) {
			stalk_convex[i].setPoint(j, sf::Vector2f((float)stalks[i][j][0], (float)stalks[i][j][1]));
		}
		int size = 35;
		sf::Image gradient();
		stalk_convex[i].setScale(scale, scale);
		stalk_convex[i].move(move[0], move[1]);
		stalk_convex[i].setFillColor(sf::Color(i, 255 - i*10, i * 2, 255));
	}
}

Cvijet::Cvijet(sf::RenderWindow *window)
{
	this->window = window;
	auto size = window->getSize();
	move[0] = (size.x / 2) - (width * scale) / 2;
	move[1] = size.y - (height * scale);
	windowsize[0] = size.x;
	windowsize[1] = size.y;
	setup();
}

void Cvijet::draw(sf::Time elapsedTime)
{
	background.rotate(0.1f);
	sunmun.rotate(0.1f);
	std::stringstream to_string(background.getRotation());
	window->setTitle(to_string.str());

	if (mun && sunmun.getRotation() > 90.f && sunmun.getRotation() < 270.f) {
		texture_sunmun.loadFromFile(textures[++texture]);
		if (texture == 7)
			texture = 0;
		mun = false;
	}
	if (!mun && sunmun.getRotation() > 270.f) {

		mun = true;
	}
	window->draw(background);
	window->draw(sunmun);

	for (int i = 0; i < petals.size(); i++)
		window->draw(petal_convex[i]);

	for (int i = 0; i < stalks.size(); i++) {
		window->draw(stalk_convex[i]);
	}
}
