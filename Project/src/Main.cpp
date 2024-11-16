#include <Application.h>

#include <iostream>
#include <chrono>

namespace Project
{
	using namespace Velkro;

	Window window;

	static void OnEvent(Event* event)
	{
		if (event->GetType() == Character)
		{
			VLK_INFO(std::string(1, static_cast<CharacterEvent*>(event)->GetCodepoint()));
		}
	}

	ExitCode Entry()
	{
		window = Window("Project", 800, 600);

		window.SetEventCallback(OnEvent);

		return ExitCode::Success;
	}

	ExitCode Loop()
	{		
		window.Update();

		if (window.WindowClosed())
		{
			return ExitCode::Exit;
		}

		return ExitCode::Success;
	}

	ExitCode Exit()
	{
		window.Destroy();

		VLK_INFO("Look! The window closed!");

		return ExitCode::Exit;
	}	
}

int main()
{
	Velkro::Application* application = new Velkro::Application();	

	application->Initialize(Project::Entry, Project::Loop, Project::Exit);

	return 0;
}