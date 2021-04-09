#include "Application.h"

int main() {
	Application app{};

	while (app.IsRunning()) {
		app.Update();
		app.Render();
	}
	return 0;
}