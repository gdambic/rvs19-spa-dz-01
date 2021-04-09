#include "Application.h"

constexpr unsigned MODE_WIDTH_U = 800U;
constexpr unsigned MODE_HEIGHT_U = 800U;
constexpr unsigned FREMERATE_LIMIT = 60U;
constexpr float CENTER = 400.F;
const char* WINDOW_NAME = "Application - Karlo Bratko, 1RP3";

void Application::_InitVariables() {
	sf_video_mode = sf::VideoMode{ MODE_WIDTH_U, MODE_HEIGHT_U };
}

void Application::_InitWindow() {
	sf_render_window = std::make_shared<sf::RenderWindow>(
		sf_video_mode,
		sf::String{ WINDOW_NAME },
		sf::Style::Titlebar | sf::Style::Close
	);
	sf_render_window->setFramerateLimit(FREMERATE_LIMIT);
}

void Application::_PoolEvents() {
	while (sf_render_window->pollEvent(sf_event)) {
		switch (sf_event.type)
		{
		case sf::Event::Closed:
			sf_render_window->close();
			break;
		case sf::Event::KeyPressed:
			if (sf_event.key.code == sf::Keyboard::Escape)
				sf_render_window->close();
			break;
		default:
			break;
		}
	}
}

Application::Application() {
	_InitVariables();
	_InitWindow();
}

const bool Application::IsRunning() const {
	return sf_render_window->isOpen();
}

void Application::Update() {
	_PoolEvents();
	cvijet.Update(clock_);
}

void Application::Render() {
	sf_render_window->clear();
	cvijet.Render(sf_render_window);
	sf_render_window->display();
}
