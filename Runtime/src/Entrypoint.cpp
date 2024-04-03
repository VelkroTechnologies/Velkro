#include "Application.h"

#include <iostream>

int main()
{
	Velkro::VLK_INFO("lalala");

	Velkro::Application* app = new Velkro::Application();
	
	app->Run();

	delete app;

	return 0;
}