#pragma once
#include <SFML/Graphics.hpp>

class EllipseShape : public sf::Shape
{
public:

	explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0.f, 0.f)) :
		m_radius(radius)
	{
		update();
	}

	void setRadius(const sf::Vector2f& radius)
	{
		m_radius = radius;
		update();
	}

	const sf::Vector2f& getRadius() const
	{
		return m_radius;
	}

	virtual std::size_t getPointCount() const
	{
		return 30; // fixed, but could be an attribute of the class if needed
	}

	virtual sf::Vector2f getPoint(std::size_t index) const
	{
		static const float pi = 3.141592654f;

		float angle = index * 2 * pi / getPointCount() - pi / 2;
		float x = std::cos(angle) * m_radius.x;
		float y = std::sin(angle) * m_radius.y;

		return sf::Vector2f(m_radius.x + x, m_radius.y + y);
	}

private:
	sf::Vector2f m_radius;
};

class Cvijet
{
private:
	sf::RenderWindow* window;
	sf::CircleShape circle{ 50.f };
	EllipseShape elipsaGore{ sf::Vector2f(60.f, 25.f) };
	EllipseShape elipsaLijevo{ sf::Vector2f(60.f, 25.f) };
	EllipseShape elipsaDesno{ sf::Vector2f(60.f, 25.f) };
	EllipseShape elipsaDolje{ sf::Vector2f(60.f, 25.f) };
	sf::RectangleShape stabljika{ sf::Vector2f(10.f, 295.f) };
	EllipseShape listStabljikeDesno{ sf::Vector2f(30.f, 17.5f) };
	EllipseShape listStabljikeLijevo{ sf::Vector2f(25.f, 12.5f) };

	sf::RectangleShape pod{ sf::Vector2f(800.f, 75.f) };
	sf::RectangleShape platforma1{ sf::Vector2f(50.f, 10.f) };
	sf::RectangleShape platforma2{ sf::Vector2f(50.f, 10.f) };
	sf::RectangleShape platforma3{ sf::Vector2f(50.f, 10.f) };
	sf::RectangleShape platforma4{ sf::Vector2f(50.f, 10.f) };
	sf::RectangleShape platforma5{ sf::Vector2f(50.f, 10.f) };
	sf::RectangleShape platforma6{ sf::Vector2f(50.f, 10.f) };

	sf::CircleShape oblak11{ 25.f };
	sf::CircleShape oblak12{ 30.f };
	sf::CircleShape oblak13{ 25.f };
	
	sf::CircleShape oblak21{ 20.f };
	sf::CircleShape oblak22{ 25.f };
	sf::CircleShape oblak23{ 20.f };
	
	sf::CircleShape oblak31{ 23.f };
	sf::CircleShape oblak32{ 28.f };
	sf::CircleShape oblak33{ 23.f };

	sf::RectangleShape pepe{ sf::Vector2f(100.f, 100.f) };

	unsigned windowWidth;
	unsigned windowHeight;
public:
	Cvijet(sf::RenderWindow* window);
	sf::Vector2f getPlatformPos(sf::RectangleShape platforma);
	void setWindowWidthHeight(unsigned &windowWidth, unsigned &windowHeight);
	void draw();
};