#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow& window)
{
	//head
	glavaCvijeta.setOutlineThickness(10.f);
	glavaCvijeta.setRadius(90);
	glavaCvijeta.setFillColor(Color(100, 250, 50));
	glavaCvijeta.setPosition(170, 90);

	//stabljika
	tijeloCvijeta.setOutlineThickness(10.f);
	tijeloCvijeta.setFillColor(Color(250, 150, 100));
	tijeloCvijeta.setSize(Vector2f(20, 400));
	tijeloCvijeta.setPosition(245, 280);


}
void Cvijet::draw(sf::RenderWindow& window)
{
	window.draw(glavaCvijeta);
	window.draw(tijeloCvijeta);

}