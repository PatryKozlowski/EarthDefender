#include "Application.hpp"

int main()
{
	Application* app = new Application(WindowConfig::WIDTH, WindowConfig::HEIGHT, WindowConfig::TITLE, WindowConfig::STYLE);

	app->Run();

	delete app;
}