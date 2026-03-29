#include "Cvijet.h"

Cvijet::Cvijet(sf::RenderWindow* pwin)
{
	win = pwin;
}

sf::RectangleShape block(int x, int y, sf::Color c) {
	sf::RectangleShape r(sf::Vector2f(25,25));
	r.setPosition(sf::Vector2f(800-x*25, 600 - y * 25));
	r.setFillColor(c);
	return r;
}

sf::RectangleShape blocksm(int x, int y, sf::Color c) {
	sf::RectangleShape r(sf::Vector2f(10, 10));
	r.setPosition(sf::Vector2f(800 - x * 10, 600 - y * 10));
	r.setFillColor(c);
	return r;
}

void Cvijet::render(std::vector<sf::RectangleShape>* art) {
	for (sf::RectangleShape r : *art)
	{
		win->draw(r);
	}
}

void move(std::vector<sf::RectangleShape>* art, int x, int y) {
	for (sf::RectangleShape& r : *art)
	{
		int mult = r.getSize().x;
		int cx = r.getPosition().x;
		int cy = r.getPosition().y;
		r.setPosition(sf::Vector2f(cx-(x*mult), cy - (y*mult)));
	}
}

void Cvijet::draw()
{
	std::vector<sf::RectangleShape> ruza;
	ruza.push_back(block(16, 1, sf::Color(38, 90, 37, 255)));
	ruza.push_back(block(15, 1, sf::Color(32, 70, 38, 255)));
	ruza.push_back(block(17, 1, sf::Color(32, 70, 38, 255)));
	ruza.push_back(block(16, 2, sf::Color(32, 70, 38, 255)));
	ruza.push_back(block(15, 2, sf::Color(32, 70, 38, 255)));
	// list ljevo
	ruza.push_back(block(18, 2, sf::Color(32, 70, 38, 255)));
	ruza.push_back(block(18, 3, sf::Color(38, 90, 37, 255)));
	ruza.push_back(block(19, 3, sf::Color(32, 70, 38, 255)));
	// list desno
	ruza.push_back(block(13, 3, sf::Color(38, 90, 37, 255)));
	ruza.push_back(block(14, 3, sf::Color(38, 90, 37, 255)));
	// stabljika
	ruza.push_back(block(16, 3, sf::Color(43, 112, 42, 255)));
	ruza.push_back(block(16, 4, sf::Color(74, 143, 40, 255)));
	ruza.push_back(block(16, 5, sf::Color(74, 143, 40, 255)));
	ruza.push_back(block(16, 6, sf::Color(74, 143, 40, 255)));
	ruza.push_back(block(16, 7, sf::Color(38, 90, 37, 255)));
	ruza.push_back(block(17, 7, sf::Color(32, 70, 38, 255)));
	//cvijet
	ruza.push_back(block(18, 7, sf::Color(191, 37, 41, 255)));
	ruza.push_back(block(18, 8, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(19, 8, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(17, 8, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(16, 8, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(15, 8, sf::Color(155, 34, 26, 255)));
	ruza.push_back(block(18, 9, sf::Color(191, 37, 41, 255)));
	ruza.push_back(block(19, 9, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(17, 9, sf::Color(116, 35, 3, 255)));
	ruza.push_back(block(16, 9, sf::Color(191, 37, 41, 255)));
	ruza.push_back(block(15, 9, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(14, 9, sf::Color(155, 34, 26, 255)));
	ruza.push_back(block(18, 10, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(17, 10, sf::Color(191, 37, 41, 255)));
	ruza.push_back(block(16, 10, sf::Color(155, 34, 26, 255)));
	ruza.push_back(block(15, 10, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(14, 10, sf::Color(191, 37, 41, 255)));
	ruza.push_back(block(16, 11, sf::Color(237, 48, 44, 255)));
	ruza.push_back(block(15, 11, sf::Color(155, 34, 26, 255)));

	std::vector<sf::RectangleShape> pcela;

	// crtamo pcelicu
	pcela.push_back(blocksm(7, 50, sf::Color(80, 80, 80, 255)));
	pcela.push_back(blocksm(6, 50, sf::Color(80, 80, 80, 255)));

	//L1
	pcela.push_back(blocksm(8, 45, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(8, 46, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(8, 47, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(8, 48, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(8, 49, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(8, 50, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(8, 51, sf::Color(45, 28, 23, 255)));

	//L2
	pcela.push_back(blocksm(9, 45, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(9, 46, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(9, 47, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(9, 48, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(9, 49, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(9, 50, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(9, 51, sf::Color(45, 28, 23, 255)));

	//L3
	pcela.push_back(blocksm(10, 45, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(10, 46, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(10, 47, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(10, 48, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(10, 49, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(10, 50, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(10, 51, sf::Color(237, 195, 67, 255)));

	//L4
	pcela.push_back(blocksm(11, 45, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(11, 46, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(11, 47, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(11, 48, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(11, 49, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(11, 50, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(11, 51, sf::Color(45, 28, 23, 255)));

	//L5
	pcela.push_back(blocksm(12, 45, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(12, 46, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(12, 47, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(12, 48, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(12, 49, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(12, 50, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(12, 51, sf::Color(237, 195, 67, 255)));

	//L6
	pcela.push_back(blocksm(13, 45, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(13, 46, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(13, 47, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(13, 48, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(13, 49, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(13, 50, sf::Color(45, 28, 23, 255)));
	pcela.push_back(blocksm(13, 51, sf::Color(45, 28, 23, 255)));

	//L7
	pcela.push_back(blocksm(14, 45, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(14, 46, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(14, 47, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(14, 48, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(14, 49, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(14, 50, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(14, 51, sf::Color(237, 195, 67, 255)));

	//L8
	pcela.push_back(blocksm(15, 45, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(15, 46, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(15, 47, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(15, 48, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(15, 49, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(15, 50, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(15, 51, sf::Color(237, 195, 67, 255)));

	//L9
	pcela.push_back(blocksm(16, 45, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(16, 46, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(16, 47, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(16, 48, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(16, 49, sf::Color(228, 174, 59, 255)));
	pcela.push_back(blocksm(16, 50, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(16, 51, sf::Color(237, 195, 67, 255)));

	//L10
	pcela.push_back(blocksm(17, 45, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(17, 46, sf::Color(40, 40, 40, 255)));
	pcela.push_back(blocksm(17, 47, sf::Color(40, 40, 40, 255)));
	pcela.push_back(blocksm(17, 48, sf::Color(40, 40, 40, 255)));
	pcela.push_back(blocksm(17, 49, sf::Color(228, 174, 59, 255)));
	pcela.push_back(blocksm(17, 50, sf::Color(237, 195, 67, 255)));
	pcela.push_back(blocksm(17, 51, sf::Color(237, 195, 67, 255)));

	//Front
	pcela.push_back(blocksm(18, 50, sf::Color(60, 60, 60, 255)));
	pcela.push_back(blocksm(19, 51, sf::Color(60, 60, 60, 255)));
	pcela.push_back(blocksm(20, 51, sf::Color(60, 60, 60, 255)));

	//Krila
	pcela.push_back(blocksm(17, 52, sf::Color(255, 255, 255, 255)));
	pcela.push_back(blocksm(16, 53, sf::Color(255, 255, 255, 255)));
	pcela.push_back(blocksm(15, 53, sf::Color(255, 255, 255, 255)));
	pcela.push_back(blocksm(14, 54, sf::Color(255, 255, 255, 255)));
	pcela.push_back(blocksm(13, 54, sf::Color(255, 255, 255, 255)));
	pcela.push_back(blocksm(12, 54, sf::Color(255, 255, 255, 255)));
	pcela.push_back(blocksm(11, 53, sf::Color(255, 255, 255, 255)));
	pcela.push_back(blocksm(10, 52, sf::Color(255, 255, 255, 255)));

	sf::Clock clock;
	int step = 0;
	while (win->isOpen()) {
		sf::Event event;
		while (win->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win->close();
		}
		if (clock.getElapsedTime().asSeconds() >= 0.35) {
			win->clear();
			render(&ruza);
			render(&pcela);
			switch (step)
			{
				case 1: move(&pcela, 6, 3); break;
				case 2: move(&pcela, 6, -3); break;
				case 3: move(&pcela, 6, 3); break;
				case 4: move(&pcela, 6, -3); break;
				case 5: move(&pcela, 6, 3); break;
				case 6: move(&pcela, 6, -3); break;
				case 7: move(&pcela, 6, 3); break;
				case 8: move(&pcela, 6, -3); break;
				case 9: move(&pcela, -48, 0); step = 0; break;
			}
			step++;
			win->display();
			clock.restart();
		}
		sf::sleep(sf::milliseconds(10));
	}
}
