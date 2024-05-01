#pragma once

#include "Renderer/Renderer.h"

#include "Window.h"

#include "GUIinput.h"
#include "GUI.h"

#include "Input.h"

namespace Velkro
{
	class Application
	{
	public:
		Application();
		~Application();

		static void OnEvent(std::unique_ptr<Event> event);

		void Run();

	private:
		bool m_Running = true;
	};
}