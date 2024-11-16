#include "Application.h"

namespace Velkro
{
	void Application::Initialize(EntrypointFunction entrypoint, LoopFunction loop, ExitpointFunction exitpoint)
	{
		if (!glfwInit())
		{
			VLK_CORE_FATAL("GLFW initialization failed.");
		}

		int entryExitCode = entrypoint();

		if (entryExitCode == Error)
		{
			VLK_CORE_FATAL("Error in entrypoint. Exiting program.");

			exit(entryExitCode);
		}
		else if (entryExitCode == Exit)
		{
			VLK_CORE_DEBUG("Exiting program (In entrypoint).");

			exit(0);
		}
		else
		{
			VLK_CORE_DEBUG("Entering program.");
		}

		int loopExitCode = 0;

		while (m_Running)
		{
			loopExitCode = loop();

			if (loopExitCode == Error)
			{
				VLK_CORE_FATAL("Error in loop. Exiting program.");

				exit(1);
			}
			else if (loopExitCode == Exit)
			{
				VLK_CORE_DEBUG("Exiting loop.");

				break;
			}

			glfwPollEvents();
		}

		VLK_CORE_DEBUG("Exiting program.");

		int exitCode = exitpoint();

		if (exitCode == Error)
		{
			VLK_CORE_FATAL("Error in exitpoint. Exiting program.");

			exit(exitCode);
		}
		else if (exitCode == Exit || exitCode == Success)
		{
			VLK_CORE_DEBUG("Exiting program (In exitpoint).");
		}

		glfwTerminate();
	}
}