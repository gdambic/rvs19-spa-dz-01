#define _USE_MATH_DEFINES // Used for PI

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Cvijet.h"

using namespace std;
using namespace sf;


// ========== Defines ========== \\


// Colors
#define HUE		rand()% 256
#define YELLOW	255, 255,   0
#define GREEN	  0, 255,   0
#define BLACK	  0,   0,   0

// Framerate
#define FPS 60

// Window Params
#define W_X float(m_window->getSize().x)
#define W_Y float(m_window->getSize().y)

// Sun params
#define SUN_RADIUS float(W_Y/20)


// ========== Constructor ========== \\


/// <summary>
///		Initiates drawings that will be displayed on the given window
///		Draws : Sun
///		Draws : Flower
/// </summary>
/// <param name="window"> The window on which it will be displayed </param>
Cvijet::Cvijet(RenderWindow* window) {
	m_window = window;

	init_sun();
	init_petals();
	init_head();
	init_stem();
	init_leaf();

	m_trigg = 2;
}


// ========== Initialisation ========== \\


/// <summary>
///		Initialise sun size, position & color
/// </summary>
void Cvijet::init_sun() {
	m_sun.setRadius(SUN_RADIUS);
	m_sun.setFillColor(Color(YELLOW));
	m_sun.setPosition(W_X / 100, W_Y / 100);
}

/// <summary>
///		Initialise petals with random values, color and size
/// </summary>
void Cvijet::init_petals() {

	int nb_petals = ((rand() % 6) + 2) * 4;		// [   8;  28]
	int len		  = (rand() % 31) + 50;			// [  50;  80]
	int raw_count = (rand() % 3) + 3;			// [   3;   6]
	double wid	  = ((rand() % 3) + 3) / 10.f;	// [ 0.3; 0.5]

	m_petals.clear();
	
	get<0>(m_color) = HUE; // Red
	get<1>(m_color) = HUE; // Green
	get<2>(m_color) = HUE; // Blue

	double delta = 2 * M_PI / nb_petals;

	for (int layer = 0; layer < raw_count; ++layer){
		for (double angle = 0; angle < 2 * M_PI; angle += delta) {

			CircleShape petal;
			petal.setRadius(len);
			petal.setScale(Vector2f(1, wid));

			float x = W_X / 2 + len * cos(angle + wid * layer);
			float y = W_Y / 2 + len * sin(angle + wid * layer);
			petal.setPosition(x, y);
		
			petal.setRotation(angle * 180 / M_PI);
			petal.setFillColor(Color(0, 0, 0));
			petal.setOutlineThickness(layer + 1);
			petal.setOutlineColor(Color::Black);

			m_petals.push_back(petal);
		}
		len = len * 0.75;
	}
}

/// <summary>
///		Initialise the head of the flower
/// </summary>
void Cvijet::init_head() {

	int nb_petals = 10;
	double len = m_petals[0].getRadius();
	double delta = 2 * M_PI / nb_petals;
	double wid = 0.25;

	CircleShape center(len);
	center.setPosition(W_X / 2.0f - len, W_Y / 2.0f - len);
	center.setFillColor(Color(YELLOW));
	m_heads.push_back(center);

	for (double angle = 0; angle < 2 * M_PI; angle += delta) {

		CircleShape head;
		head.setRadius(len);
		head.setScale(Vector2f(0.5, wid));

		float x = W_X / 2;
		float y = W_Y / 2;
		head.setPosition(x, y);

		head.setRotation(angle * 180 / M_PI);
		head.setFillColor(Color(0, 0, 0, 0));
		head.setOutlineThickness(2);
		head.setOutlineColor(Color(BLACK));

		m_heads.push_back(head);
	}
}

/// <summary>
///		Initialise the stem of the flower
/// </summary>
void Cvijet::init_stem() {
	double x = W_X / 50;
	double y = W_Y / 2;

	m_stem.setSize(Vector2f(x, y));
	m_stem.setPosition((W_X - x) / 2, W_Y / 2);
	m_stem.setFillColor(Color(GREEN));
}

/// <summary>
///		Initialise the leaf of the flower
/// </summary>
void Cvijet::init_leaf() {
	double x = m_stem.getPosition().x;
	double y = m_stem.getPosition().y;
	double sx = m_stem.getSize().x;

	m_leaf.setRadius(sx * 3);
	m_leaf.setScale(Vector2f(1, 0.3));
	m_leaf.setPosition(x + sx / 3, y * 1.85);
	m_leaf.setRotation(-30);
	m_leaf.setFillColor(Color(GREEN));
}


// ========== Animation ========== \\


/// <summary>
///		Calculates the update time for animations based on the position of the sun
/// </summary>
/// <returns> The time of actualisation of the animations </returns>
float Cvijet::status() {
	return (1 - cos((2 * m_sun.getPosition().x * M_PI) / W_X));
}


// ========== Update ========== \\


/// <summary>
///		Update sun position
/// </summary>
void Cvijet::update_sun() {

	// Calculate new position
	m_sun.setPosition(m_sun.getPosition().x + W_X / (2*FPS), m_sun.getPosition().y);

	// Calculate new size
	double new_size = status() / 4;
	m_sun.setRadius(SUN_RADIUS * float(1 - new_size));

	// For Flower color switch
	if (m_trigg != 1 && m_sun.getPosition().x < 0) {
		m_trigg = 0;
	} else {
		m_trigg = 1;
	}

	// Update position when out of border
	if (m_sun.getPosition().x > W_X + SUN_RADIUS) {
		m_sun.setPosition(-2 * static_cast<float>(SUN_RADIUS), m_sun.getPosition().y);
		m_sun.setRadius(SUN_RADIUS);
		m_trigg = 2;
	}
}

/// <summary>
///		Update petals color, position & rotation
/// </summary>
void Cvijet::update_petals(){

	float factor = status() / 2;
	float r = get<0>(m_color) * factor;
	float g = get<1>(m_color) * factor;
	float b = get<2>(m_color) * factor;

	if (m_trigg == 1){
		for (size_t i = 0; i < m_petals.size(); i++){
			m_petals[i].setFillColor(Color(r, g, b, 253 + factor * 2));
			m_petals[i].setOutlineColor(Color(BLACK, 253 + factor * 2));
		}
	}

	for (size_t i = 0; i < m_petals.size(); i++) {
		m_petals[i].rotate(1.0f);
	}


	// Update position when out of border
	if (m_trigg == 2) {
		m_trigg = 0;
		init_petals();
	}
}

/// <summary>
///		Update others color element
/// </summary>
void Cvijet::update_default(){

	double factor = status() / 2;

	if (m_trigg == 1) {
		m_heads[0].setFillColor(Color(200 * factor, 200 * factor, 10 * factor));
		m_stem.setFillColor(Color(0, factor * 254, 0));
		m_leaf.setFillColor(Color(0, factor * 254, 0));
	}
}


/// <summary>
///		Main update function
/// </summary>
void Cvijet::update() {

	if (clock.getElapsedTime().asSeconds() >= 1.0f / FPS)
	{
		update_default();
		update_petals();
		update_sun();

		clock.restart();
	}
}

/// <summary>
///		Draw elements on the window
/// </summary>
void Cvijet::draw() {
	m_window->draw(m_sun);
	m_window->draw(m_stem);
	m_window->draw(m_leaf);

	for (size_t i = 0; i < m_heads.size(); i++)
	{
		m_window->draw(m_heads[i]);
	}

	for (size_t i = 0; i < m_petals.size(); i++)
	{
		m_window->draw(m_petals[i]);
	}
}