#include "Application.h"

namespace Velkro
{
	void Application::Run()
	{
		Window window = Window("lalalallaa", 800, 600);

		while (m_Running)
		{
			window.Update();

			Log::Info("1,2,3 Now spit out the rest! YOU: %d, %d, %d", 4, 5, 6);
		}
	}
}