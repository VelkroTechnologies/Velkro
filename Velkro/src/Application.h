#pragma once

#include "Core.h"
#include "Log.h"

#include "Input.h"
#include "ExampleInputLayer.h"

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