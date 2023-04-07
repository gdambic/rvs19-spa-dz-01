#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include <iostream>

using namespace std;

int main(void){

	//options block ranging from 1(lowest) to 5(highest) graphics
	//included so the program can run on PCs with no or low-end GPUs
	int options;
	sf::ContextSettings instructions;
options_jmp: //goto is fast and memory efficient so I prefer it over flag loops
	try {
		cout << "Set graphics options (1,2,3,4,5): ";
		cin >> options;
		if (options < 1 || options > 5)
			throw invalid_argument("Choose a valid option!");
	}catch (invalid_argument g_options_err) { cout << g_options_err.what() << endl; goto options_jmp; }
	switch (options) {
	case 2: instructions.antialiasingLevel = 2; break;
	case 3: instructions.antialiasingLevel = 4; break;
	case 4: instructions.antialiasingLevel = 8; break;
	case 5: instructions.antialiasingLevel = 16; break;
	default: break; //1 also redirects here, as option 1 means no AA
	}

	//window initializitaion using the defined settings
	sf::RenderWindow window(sf::VideoMode(1440, 1080), "SPA_DZ1_DDespot_1RP3", sf::Style::Default,instructions); 
	window.setFramerateLimit(60);
	Cvijet cvijet(&window); //forwarding the window address to object cvijet of class Cvijet

		cvijet.draw(); //executing the main (draw) function of object cvijet


	return 0;
}