#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Cvijet
{
private:
	RenderWindow *mWindow;
	CircleShape circle;
	RectangleShape rectangle;
	ConvexShape shape;
	Texture pTextureShrek;
	Sprite pSpriteShrek;
	Texture pTextureFiona;
	Sprite pSpriteFiona;
	Texture pTextureDonkie;
	Sprite pSpriteDonkie;
	Font font;
	Text text;
	float xShrek;
	float yShrek;
	int x = 500;
	int y = 500;
	int pomagac = 0;
public:
	Cvijet();
	Cvijet(string imgDirectoryShrek, string imgDirectoryFiona, string imgDirectoryDonkie, RenderWindow *window);
	float get_xShrek();
	float get_yShrek();
	void drawCvijet();
	void drawShrek();
	void moveShrek(char direction, float speed);
	void drawText(string fontDirectory);
	void drawFiona();
	void drawDonkie();
	void moveDonkie();
};

