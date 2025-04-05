#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
	this->texture.loadFromFile("pngs/petal.png");
	this->rhombusi = 
	{
		{ sf::Vector2f(404.f, 461.f), sf::Vector2f(444.f, 473.f), sf::Vector2f(475.f, 457.f), sf::Vector2f(433.f, 444.f) },
		{ sf::Vector2f(404.f, 461.f), sf::Vector2f(419.f, 429.f), sf::Vector2f(448.f, 440.f), sf::Vector2f(428.f, 460.f) },
		{ sf::Vector2f(404.f, 461.f), sf::Vector2f(424.f, 477.f), sf::Vector2f(451.f, 469.f), sf::Vector2f(437.f, 454.f) },
	};

	this->CurrentAnimation = 0;
}

void Cvijet::draw() 
{

	sf::Time deltatime = clock.restart();

	const sf::Time timePerFrame = sf::seconds(1.f / targetFPS);

	this->FramesSinceUpdate++;
	if (FramesSinceUpdate == FramesPerAnimation) {
		FramesSinceUpdate = 0;
		CurrentAnimation++;
		if (CurrentAnimation >= this->rhombusi.size())
			CurrentAnimation = 0;
	}


	sf::ConvexShape rhombus;


	rhombus.setPointCount(rhombusi[this->CurrentAnimation].size());
	for (int i = 0; i < this->rhombusi[this->CurrentAnimation].size(); i++) {
		rhombus.setPoint(i, rhombusi[this->CurrentAnimation][i]);
	}
	rhombus.setFillColor(sf::Color(0, 255, 0));





	sf::CircleShape circle(15.f);
	circle.setFillColor(sf::Color(0, 0, 0));
	circle.setPosition(383, 285);
	circle.setOutlineThickness(2.f);
	circle.setOutlineColor(sf::Color(255, 255, 0));
	

	sf::CircleShape outline(100.f);
	outline.setPosition(300, 200);
	outline.setTexture(&texture);

	sf::RectangleShape line(sf::Vector2f(5.f, 200.f));
	line.setPosition(400, 330);
	line.setFillColor(sf::Color(0, 255, 0));
	
	this->window->draw(line);
	this->window->draw(circle);
	this->window->draw(outline);
	this->window->draw(rhombus);

	sf::Time frameTime = clock.getElapsedTime();
	if (frameTime < timePerFrame) {
		sf::sleep(timePerFrame - frameTime);  // Delay to maintain the target FPS
	}
	
}
