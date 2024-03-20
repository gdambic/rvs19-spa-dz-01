#ifndef CVIJET_H
#define CVIJET_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Cvijet
{
	private:
		// Window
		RenderWindow* m_window;

		// Shapes
		CircleShape m_sun;
		CircleShape m_leaf;
		RectangleShape m_stem;

		vector<CircleShape> m_heads;
		vector<CircleShape> m_petals;

		// Petals Infos
		tuple<int, int, int> m_color;

		// Update
		int m_trigg = 0;
		Clock clock;

		float status();
		
		void init_sun();
		void init_head();
		void init_stem();
		void init_leaf();
		void init_petals();

		void update_default();
		void update_petals();
		void update_sun();

	public:
		Cvijet(RenderWindow* window);
		void update();
		void draw();
};

#endif // CVIJET_H