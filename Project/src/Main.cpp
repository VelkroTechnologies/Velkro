#include <Application.h>

#include <iostream>
#include <chrono>

namespace Project
{
	using namespace Velkro;

	static ExitCode Entry()
	{
		return ExitCode::Success;
	}

	static ExitCode Loop()
	{
		uint64_t time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

		VLK_INFO(std::to_string(time));

		return ExitCode::Success;
	}

	static Velkro::ExitCode Exit()
	{
		return ExitCode::Exit;
	}
}

int main()
{
	Velkro::Application* application = new Velkro::Application();	

	application->Initialize(Project::Entry, Project::Loop, Project::Exit);

	return 0;
}