#include "Cvijet.h"



Cvijet::Cvijet(sf::RenderWindow* window)
{
	this->window = window;
}

void Cvijet::draw()
{
	delta += move;
	

	sf::CircleShape circle(40);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f((800 / 2) - (2*40), (600 / 2) - (2*40)));
	circle.setOutlineThickness(10);
	circle.setOutlineColor(sf::Color::White);
	
	sf::CircleShape circle1(40);
	circle1.setFillColor(sf::Color::Red);
	circle1.setPosition(sf::Vector2f(800 / 2, 600 / 2));
	circle1.setOutlineThickness(10);
	circle1.setOutlineColor(sf::Color::White);

	sf::CircleShape circle2(40);
	circle2.setFillColor(sf::Color::Black);
	circle2.setPosition(sf::Vector2f((800 / 2) - 40, (600 / 2) - 40));
	circle2.setOutlineThickness(10);
	circle2.setOutlineColor(sf::Color::White);

	sf::CircleShape circle3(40);
	circle3.setFillColor(sf::Color::Red);
	circle3.setPosition(sf::Vector2f((800 / 2) - (2 * 40), (600 / 2)));
	circle3.setOutlineThickness(10);
	circle3.setOutlineColor(sf::Color::White);

	sf::CircleShape circle4(40);
	circle4.setFillColor(sf::Color::Red);
	circle4.setPosition(sf::Vector2f(800 / 2, (600 / 2) - (2 * 40)));
	circle4.setOutlineThickness(10);
	circle4.setOutlineColor(sf::Color::White);

	sf::CircleShape circle5(40);
	circle5.setFillColor(sf::Color::Red);
	circle5.setPosition(sf::Vector2f((800 / 2) - 80, (600 / 2) - 40));
	circle5.setOutlineThickness(10);
	circle5.setOutlineColor(sf::Color::White);

	sf::CircleShape circle6(40);
	circle6.setFillColor(sf::Color::Red);
	circle6.setPosition(sf::Vector2f((800 / 2) -40  , (600 / 2) -80 ));
	circle6.setOutlineThickness(10);
	circle6.setOutlineColor(sf::Color::White);

	sf::CircleShape circle7(40);
	circle7.setFillColor(sf::Color::Red);
	circle7.setPosition(sf::Vector2f((800 / 2) , (600 / 2)- 40));
	circle7.setOutlineThickness(10);
	circle7.setOutlineColor(sf::Color::White);

	sf::CircleShape circle8(40);
	circle8.setFillColor(sf::Color::Red);
	circle8.setPosition(sf::Vector2f((800 / 2)- 40, (600 / 2) ));
	circle8.setOutlineThickness(10);
	circle8.setOutlineColor(sf::Color::White);

	sf::RectangleShape rectangle(sf::Vector2f(20, 300));
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setPosition(sf::Vector2f(400-20+10,600-300 + 20));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color::Black);

	sf::ConvexShape convex;
	convex.setPointCount(5);
	convex.setPoint(0, sf::Vector2f(390,400 ));
	convex.setPoint(1, sf::Vector2f(420, 350));
	convex.setPoint(2, sf::Vector2f(460, 410));
	convex.setPoint(3, sf::Vector2f(400, 430));
	convex.setPoint(4, sf::Vector2f(390, 400));
	convex.setFillColor(sf::Color::Green);
	convex.setOutlineThickness(1);
	convex.setOutlineColor(sf::Color::Black);

	sf::ConvexShape convex1;
	convex1.setPointCount(5);
	convex1.setPoint(0, sf::Vector2f(390, 400));
	convex1.setPoint(1, sf::Vector2f(360, 350));
	convex1.setPoint(2, sf::Vector2f(330, 410));
	convex1.setPoint(3, sf::Vector2f(380, 430));
	convex1.setPoint(4, sf::Vector2f(450, 400));
	convex1.setFillColor(sf::Color::Green);
	convex1.setOutlineThickness(1);
	convex1.setOutlineColor(sf::Color::Black);


	sf::CircleShape octagon(80, 8);
	octagon.setFillColor(sf::Color{ 146, 119, 92, 255 });
	octagon.setPosition(sf::Vector2f(400-80, 520));
	octagon.setOutlineThickness(1);
	octagon.setOutlineColor(sf::Color::Black);

	sf::RectangleShape rectangle1(sf::Vector2f(800, 600));
	rectangle1.setFillColor(sf::Color{ 171, 219, 227 });
	rectangle1.setPosition(sf::Vector2f(0, 0));

	sf::RectangleShape rectangle2(sf::Vector2f(800, 500));
	rectangle2.setFillColor(sf::Color{ 73, 199, 19});
	rectangle2.setPosition(sf::Vector2f(0, 500));

	sf::CircleShape cloud1(40);
	cloud1.setFillColor(sf::Color::White);
	cloud1.setPosition(sf::Vector2f(100 + 400, 100));

	sf::CircleShape cloud2(40);
	cloud2.setFillColor(sf::Color::White);
	cloud2.setPosition(sf::Vector2f(130 + 400, 130));

	sf::CircleShape cloud3(40);
	cloud3.setFillColor(sf::Color::White);
	cloud3.setPosition(sf::Vector2f(120 + 400, 70));
	
	sf::CircleShape cloud4(40);
	cloud4.setFillColor(sf::Color::White);
	cloud4.setPosition(sf::Vector2f(160 + 400, 90));
	
	sf::CircleShape cloud5(40);
	cloud5.setFillColor(sf::Color::White);
	cloud5.setPosition(sf::Vector2f(170 + 400, 90));

	sf::CircleShape Sun(120);
	Sun.setFillColor(sf::Color::Yellow);
	Sun.setPosition(sf::Vector2f(-180 + delta, -60));

	sf::CircleShape ccloud1(40);
	ccloud1.setFillColor(sf::Color::White);
	ccloud1.setPosition(sf::Vector2f(100 - 20, 100));

	sf::CircleShape ccloud2(40);
	ccloud2.setFillColor(sf::Color::White);
	ccloud2.setPosition(sf::Vector2f(130 - 20, 130));

	sf::CircleShape ccloud3(40);
	ccloud3.setFillColor(sf::Color::White);
	ccloud3.setPosition(sf::Vector2f(120 - 20, 70));

	sf::CircleShape ccloud4(40);
	ccloud4.setFillColor(sf::Color::White);
	ccloud4.setPosition(sf::Vector2f(160 - 20, 90));

	sf::CircleShape ccloud5(40);
	ccloud5.setFillColor(sf::Color::White);
	ccloud5.setPosition(sf::Vector2f(170 - 20, 90));

	sf::CircleShape ccloud6(40);
	ccloud6.setFillColor(sf::Color::White);
	ccloud6.setPosition(sf::Vector2f(90 - 20, 80));

	sf::CircleShape ccloud7(40);
	ccloud7.setFillColor(sf::Color::White);
	ccloud7.setPosition(sf::Vector2f(80 - 20, 125));
	



	
	(*window).draw(rectangle1);
	(*window).draw(rectangle2);
	
	(*window).draw(Sun);

	//Cloud right
	(*window).draw(cloud1);
	(*window).draw(cloud2);
	(*window).draw(cloud3);
	(*window).draw(cloud4);
	(*window).draw(cloud5);

	//Cloud left
	(*window).draw(ccloud1);
	(*window).draw(ccloud2);
	(*window).draw(ccloud3);
	(*window).draw(ccloud4);
	(*window).draw(ccloud5);
	(*window).draw(ccloud6);
	(*window).draw(ccloud7);

	//Stabiljka
	(*window).draw(octagon);
	(*window).draw(rectangle);
	(*window).draw(convex);
	(*window).draw(convex1);

	
	(*window).draw(circle);
	(*window).draw(circle1);
	(*window).draw(circle3);
	(*window).draw(circle4);
	(*window).draw(circle5);
	(*window).draw(circle6);
	(*window).draw(circle7);
	(*window).draw(circle8);
	(*window).draw(circle2);

	
	
	
	if (delta>=920)
	{
		delta = 0;
		(*window).clear();

			
	}
	 
}
