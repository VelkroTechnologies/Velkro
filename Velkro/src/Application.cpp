#include "Application.h"

namespace Velkro
{
	Application::Application()
	{
		Window::SetEventCallback(OnEvent);
	}
	Application::~Application()
	{
	}

	void Application::OnEvent(std::unique_ptr<Event> event)
	{
		InputStack::OnEvent(event);
	}

	void Application::Run()
	{
		Window window = Window("Velkro Engine", 800, 600);

		std::unique_ptr<InputLayer> inputClass = std::make_unique<ExampleClass>();
		std::unique_ptr<InputLayer> inputClass2 = std::make_unique<ExampleClass2>();

		InputStack::PushLayer(inputClass);
		InputStack::PushLayer(inputClass2);

		while (m_Running)
		{
			window.Update();
		}
	}
}