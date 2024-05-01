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

		if (event->GetEventCode() == VLK_KEY_0)
		{
			VLK_INFO("yooohoooo");
		}
	}

	void Application::Run()
	{
		Window window = Window("Velkro Engine", 800, 600);

		GUI::Init(window);
		Renderer::Init();

		std::unique_ptr<InputLayer> GUIlayer = std::make_unique<GUIinput>();
		InputStack::PushLayer(GUIlayer);		

		Scene testScene("a homeee");
		Scene testScene2("a bankkkk");

		SceneManager::AddScene(&testScene);
		SceneManager::AddScene(&testScene2);

		SceneManager::SetActiveScene(testScene2.ID);

		while (m_Running)
		{
			Renderer::Update();			

			GUI::Update();

			window.Update();

			if (window.WantClose())
			{
				break;
			}
		}

		GUI::Destroy();
	}
}