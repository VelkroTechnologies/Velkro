#include "Application.h"

#include <iostream>

int main()
{
	std::cout << "Welcome to Velkro Engine =D" << '\n';

	Velkro::Application* app = new Velkro::Application();
	
	app->Run();

	delete app;

	return 0;
}