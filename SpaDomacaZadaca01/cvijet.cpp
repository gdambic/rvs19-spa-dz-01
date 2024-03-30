#include "cvijet.h"
#include <SFML/Graphics.hpp>

cvijet::cvijet(sf::RenderWindow* window)
{
	this->window = window;
	ustaWidth = 40.0f; 
	sirenje = true;    

	frameClock.restart();
}

void cvijet::draw()
{
	float time = frameClock.getElapsedTime().asSeconds();

	float smileySize;
	if (sirenje) {
		
		smileySize = 30.0f + 10.0f * time;
	}
	else {
	
		smileySize = 30.0f - 10.0f * time;
	}

	
	
	if (time >= 2.0f) {
		
		frameClock.restart();
		
		sirenje = !sirenje;
	}

	
	if (sirenje) {
		
		ustaWidth = 20.0f + 10.0f * time;
	}
	else {
		
		ustaWidth = 30.0f - 10.0f * time;
	}

	sf::RectangleShape stab(sf::Vector2f(15, 200)); 
	stab.setFillColor(sf::Color(0, 128, 0)); 
	stab.setPosition(680, 420); 
	window->draw(stab);

	sf::CircleShape lat1(50);
	lat1.setFillColor(sf::Color::Green);
	lat1.setPosition(565, 390); 
	window->draw(lat1);

	sf::CircleShape lat2(40); 
	lat2.setFillColor(sf::Color::Green);
	lat2.setPosition(700, 420); 
	window->draw(lat2);

	sf::CircleShape lat3(50); 
	lat3.setFillColor(sf::Color::Green);
	lat3.setPosition(565, 330); 
	window->draw(lat3);

	sf::CircleShape lat4(45);
	lat4.setFillColor(sf::Color::Green);
	lat4.setPosition(600, 300); 
	window->draw(lat4);

	sf::CircleShape lat5(60); 
	lat5.setFillColor(sf::Color::Green);
	lat5.setPosition(680,320); 
	window->draw(lat5);

	sf::CircleShape lat6(40); 
	lat6.setFillColor(sf::Color::Green);
	lat6.setPosition(650, 280);
	window->draw(lat6);

	sf::CircleShape lat7(50); 
	lat7.setFillColor(sf::Color::Green);
	lat7.setPosition(580, 420); 
	window->draw(lat7);

	sf::CircleShape lat8(50); 
	lat8.setFillColor(sf::Color::Green);
	lat8.setPosition(620, 420); 
	window->draw(lat8);

	sf::CircleShape cvijet(70);
	cvijet.setFillColor(sf::Color::Cyan);
	cvijet.setPosition(600, 350);
	cvijet.setOutlineThickness(10.8);
	cvijet.setOutlineColor(sf::Color::Magenta);
	window->draw(cvijet);

	sf::ConvexShape zraka;
	zraka.setPointCount(8);
	zraka.setFillColor(sf::Color::Yellow);

	zraka.setPoint(0, sf::Vector2f(425, 300));
	zraka.setPoint(1, sf::Vector2f(450, 275));
	zraka.setPoint(2, sf::Vector2f(500, 300));
	zraka.setPoint(3, sf::Vector2f(450, 325));
	window->draw(zraka);

	sf::ConvexShape zrakac;
	zrakac.setPointCount(4);
	zrakac.setFillColor(sf::Color::Yellow);

	zrakac.setPoint(0, sf::Vector2f(305, 320));
	zrakac.setPoint(1, sf::Vector2f(410, 375));
	zrakac.setPoint(2, sf::Vector2f(350, 300));

	window->draw(zrakac);

	sf::ConvexShape zrakab;
	zrakab.setPointCount(5);
	zrakab.setFillColor(sf::Color::Yellow);

	zrakab.setPoint(0, sf::Vector2f(100, 435));
	zrakab.setPoint(1, sf::Vector2f(267, 475));
	zrakab.setPoint(2, sf::Vector2f(180, 360));

	window->draw(zrakab);

	sf::ConvexShape zrakad;
	zrakad.setPointCount(6);
	zrakad.setFillColor(sf::Color::Yellow);

	zrakad.setPoint(0, sf::Vector2f(500, 150));
	zrakad.setPoint(1, sf::Vector2f(580, 290));
	zrakad.setPoint(2, sf::Vector2f(560, 200));
	window->draw(zrakad);

	sf::ConvexShape zrakae;
	zrakae.setPointCount(8);
	zrakae.setFillColor(sf::Color::Yellow);

	zrakae.setPoint(0, sf::Vector2f(100, 150));
	zrakae.setPoint(1, sf::Vector2f(180, 290));
	zrakae.setPoint(2, sf::Vector2f(260, 300));
	window->draw(zrakae);

	sf::ConvexShape zrakaf;
	zrakaf.setPointCount(8);
	zrakaf.setFillColor(sf::Color::Yellow);

	zrakaf.setPoint(0, sf::Vector2f(800, 100));   // Top right of the screen
	zrakaf.setPoint(1, sf::Vector2f(600, 135)); // Adjusted second point
	
	window->draw(zrakaf);

	sf::CircleShape sunce(140);
	sunce.setFillColor(sf::Color::Yellow);
	sunce.setPosition(0, 0); 
	sunce.setOutlineThickness(21.5);

	sunce.setOutlineColor(sf::Color::Red);
	window->draw(sunce);

	sf::RectangleShape naochale(sf::Vector2f(40, 20));
	naochale.setFillColor(sf::Color::Black);
	naochale.setPosition(40, 40); 

	window->draw(naochale);

	sf::RectangleShape naochale2(sf::Vector2f(40, 20));
	naochale2.setFillColor(sf::Color::Black);
	naochale2.setPosition(100, 40); 

	window->draw(naochale2);

	sf::RectangleShape naochale3(sf::Vector2f(20, 5));
	naochale3.setFillColor(sf::Color::Black);
	naochale3.setPosition(80, 50); 
	window->draw(naochale3);

	
	sf::CircleShape oko1(10); 
	oko1.setFillColor(sf::Color::Black);
	oko1.setPosition(685, 390); 
	window->draw(oko1);

	sf::CircleShape oko2(10); 
	oko2.setFillColor(sf::Color::Black);
	oko2.setPosition(710, 390); 
	window->draw(oko2);

	
	sf::CircleShape smiley(smileySize);
	smiley.setFillColor(sf::Color::Black);
	smiley.setPosition(60, 80);
	window->draw(smiley);

	sf::RectangleShape usta(sf::Vector2f(ustaWidth, 5.0f));
	usta.setFillColor(sf::Color::Black);
	usta.setPosition(655, 450);
	window->draw(usta);


	
}