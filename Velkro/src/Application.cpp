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

	void Application::OnEvent(Event* event)
	{
		InputStack::OnEvent(event);

		delete event;
	}

	void Application::Run()
	{
		Window window = Window("Velkro Engine", glm::vec2(800, 600));

		GUI::Init(window);
		Renderer::Init();

		std::unique_ptr<InputLayer> GUIlayer = std::make_unique<GUIinput>();
		InputStack::PushLayer(GUIlayer);		

		SceneManager::AddScene(new Scene("Scene"));
		SceneManager::AddScene(new Scene("Scene2"));

		SceneManager::SetActiveScene("Scene");

		Viewport::Init(glm::vec2(1.0f));
		
		Entity* dirt = new Entity(UUID::GenUUID("dirt"));
		dirt->AddComponent(new SpriteComponent(glm::vec2(100.0f, 100.0f), glm::vec2(100, 100), 0.0f, VLK_ASSETS_DIR + "textures/dirt.png"));

		SpriteComponent* spriteComponent = (SpriteComponent*)dirt->GetComponent(VLK_SPRITE_COMPONENT);
		spriteComponent->Position = glm::vec2(200.0f, 200.0f);

		SceneManager::GetScene("Scene")->AddEntity(dirt);
		
		while (m_Running)
		{
			Viewport::Bind();

			Renderer::ClearColourBuffer(); /* In order for GUI viewport to show background colour */
			
			SceneManager::Update();

			Viewport::Unbind();

			GUI::Update();

			window.Update();			

			Renderer::Update();

			if (window.WantClose())
			{
				break;
			}
		}

		GUI::Destroy();
		
		SceneManager::Destroy();
	}
}