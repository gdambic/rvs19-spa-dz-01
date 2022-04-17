#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Cvijet : public sf::Drawable, public sf::Transformable
{
private:
	std::vector<sf::CircleShape> dijelovi;
public:

	Cvijet(sf:: Color boja, unsigned int latice, float radijus, float radijusLatice) :
		dijelovi(latice + 1)
	{
		dijelovi[0].setRadius(radijus);
		dijelovi[0].setFillColor(sf::Color::Yellow);
		dijelovi[0].setOrigin(radijus, radijus);
		dijelovi[0].setOutlineColor(sf::Color::Cyan);
		dijelovi[0].setOutlineThickness(5);


		// ugao izmedju pojedinacnih latica
		float delta = 2 * 3.1415 / latice;

		for (unsigned int i = 1; i <= latice; ++i) {

			
			sf::CircleShape& latice(dijelovi[i]);

			latice.setRadius(radijusLatice);
			latice.setFillColor(boja);
			latice.setOrigin(radijusLatice + (radijusLatice + radijus) * std::sin(i * delta), radijusLatice + (radijusLatice + radijus) * std::cos(i * delta));
			latice.setOutlineColor(sf::Color::Yellow);
			latice.setOutlineThickness(3);
			
		}
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const {

		// Transform ( sf::Transformable)
		states.transform *= getTransform();

		// Iscrtavanje dijelova
		for (const sf::CircleShape& part : dijelovi)
			target.draw(part, states);
	}

};

