#pragma once

#include "Cvijet.h"

class Application {
private:
	sf::VideoMode sf_video_mode;
	std::shared_ptr<sf::RenderWindow> sf_render_window;
	sf::Event sf_event;
	sf::Clock clock_;
	Cvijet cvijet;

	void _InitVariables();
	void _InitWindow();

	void _PoolEvents();

public:
	Application();

	const bool IsRunning() const;
	void Update();
	void Render();

};

