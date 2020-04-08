#include "Okolina.h"

Okolina::Okolina(RenderWindow* window)
{
	this->window = window;
	sunce.push_back(Sunce(window, window->getSize().x / 2, 2 * window->getSize().y, 2 * window->getSize().y - window->getSize().y / 12, 38));
	int grid_size = 8;
	for (int i = 0; i < 200; i++) {
		int x = grid_size * (rand() % (window->getSize().x / grid_size));
		int y = grid_size * (rand() % ((7 * window->getSize().y / 12) / grid_size));
		zvijezde.push_back(Zvijezda(window, x, y));
	}
}

void Okolina::draw()
{
	sunce[0].draw();
	float kut = sunce[0].get_kut();
	ConvexShape tint;
	tint.setPointCount(4);
	tint.setPoint(0, Vector2f(0.f, 0.f));
	tint.setPoint(1, Vector2f(window->getSize().x, 0.f));
	tint.setPoint(2, Vector2f(window->getSize().x, window->getSize().y));
	tint.setPoint(3, Vector2f(0.f, window->getSize().y));
	tint.setFillColor(Color(0, 0, 0, 0));
	if (kut > 292.4) {
		tint.setFillColor(Color(0, 0, 0, 255 * (kut - 292.4) / 67.6));
	}
	if (kut < 247.2) {
		tint.setFillColor(Color(0, 0, 0, 255 - 255 * (kut - 247.6) / 67.6));
	}

	window->draw(tint);

	if (kut > 292.4) {
		for (int i = 0; i < zvijezde.size(); i++) {
			zvijezde[i].draw(255 * (kut - 292.4) / 67.6);
		}
	}
	if (kut < 247.2) {
		for (int i = 0; i < zvijezde.size(); i++) {
			zvijezde[i].draw(255 - 255 * (kut - 247.6) / 67.6);
		}
	}
}
