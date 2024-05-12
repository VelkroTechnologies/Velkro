#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3_loader.h>
#include <imgui_impl_opengl3.h>

#include <filesystem>
#include <sstream>

#include "Renderer/Renderer.h"
#include "Core.h"

#include "Scene.h"

#include "Viewport.h"

#include "UUID.h"

namespace Velkro
{
	class GUI
	{
	public:
		static void Init(Window& window)
		{
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO(); (void)io;

			io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

			ImGui::StyleColorsDark();
			SetStyle();

			ImGui_ImplGlfw_InitForOpenGL(window.GetGLFWWindow(), true);
			ImGui_ImplOpenGL3_Init("#version 460");
			
			std::stringstream path;
			path << VLK_ASSETS_DIR << "font/Roboto-Regular.ttf";
			
			m_Font = io.Fonts->AddFontFromFileTTF(path.str().c_str(), 18);
		}

		static void Update()
		{
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);

			ImGui::PushFont(m_Font);

			ImGui::BeginMainMenuBar(); /* Menu Bar */

			if (ImGui::BeginMenu("File"))
			{
				ImGui::TextDisabled("Save");
				ImGui::TextDisabled("Export");
				ImGui::TextDisabled("Open");

				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("View"))
			{
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Edit"))
			{
				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();

			ViewportGUI::Update();
			SceneHierarchy::Update();
			Properties::Update();

			ImGui::PopFont();

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

			ImGui::EndFrame();
		}
		
		static void Destroy()
		{
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();
			ImGui::DestroyContext();
		}

	private:
		static inline ImFont* m_Font;
		static void SetStyle()
		{
			ImVec4* colors = ImGui::GetStyle().Colors;
			colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
			colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
			colors[ImGuiCol_WindowBg]               = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
			colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_PopupBg]                = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
			colors[ImGuiCol_Border]                 = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
			colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
			colors[ImGuiCol_FrameBg]                = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
			colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
			colors[ImGuiCol_FrameBgActive]          = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
			colors[ImGuiCol_TitleBg]                = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
			colors[ImGuiCol_TitleBgActive]          = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
			colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
			colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
			colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
			colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
			colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
			colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
			colors[ImGuiCol_CheckMark]              = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
			colors[ImGuiCol_SliderGrab]             = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
			colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
			colors[ImGuiCol_Button]                 = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
			colors[ImGuiCol_ButtonHovered]          = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
			colors[ImGuiCol_ButtonActive]           = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
			colors[ImGuiCol_Header]                 = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
			colors[ImGuiCol_HeaderHovered]          = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
			colors[ImGuiCol_HeaderActive]           = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
			colors[ImGuiCol_Separator]              = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
			colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
			colors[ImGuiCol_SeparatorActive]        = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
			colors[ImGuiCol_ResizeGrip]             = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
			colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
			colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
			colors[ImGuiCol_Tab]                    = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
			colors[ImGuiCol_TabHovered]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
			colors[ImGuiCol_TabActive]              = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
			colors[ImGuiCol_TabUnfocused]           = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
			colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
			colors[ImGuiCol_DockingPreview]         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
			colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
			colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
			colors[ImGuiCol_TableBorderLight]       = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
			colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
			colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
			colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
			colors[ImGuiCol_DragDropTarget]         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
			colors[ImGuiCol_NavHighlight]           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
			colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
			colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
			colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);
			
			ImGuiStyle& style = ImGui::GetStyle();
			style.WindowPadding                     = ImVec2(8.00f, 8.00f);
			style.FramePadding                      = ImVec2(5.00f, 2.00f);
			style.CellPadding                       = ImVec2(6.00f, 6.00f);
			style.ItemSpacing                       = ImVec2(6.00f, 6.00f);
			style.ItemInnerSpacing                  = ImVec2(6.00f, 6.00f);
			style.TouchExtraPadding                 = ImVec2(0.00f, 0.00f);
			style.IndentSpacing                     = 25;
			style.ScrollbarSize                     = 15;
			style.GrabMinSize                       = 10;
			style.WindowBorderSize                  = 1;
			style.ChildBorderSize                   = 1;
			style.PopupBorderSize                   = 1;
			style.FrameBorderSize                   = 1;
			style.TabBorderSize                     = 1;
			style.WindowRounding                    = 7;
			style.ChildRounding                     = 4;
			style.FrameRounding                     = 3;
			style.PopupRounding                     = 4;
			style.ScrollbarRounding                 = 9;
			style.GrabRounding                      = 3;
			style.LogSliderDeadzone                 = 4;
			style.TabRounding                       = 4;
		}

		static inline bool m_ViewportClosed = false;
		static inline bool m_SceneHierarchyClosed = false;

		class ViewportGUI
		{
		public:
			static void Update()
			{
				std::stringstream windowTitle;
				windowTitle << "Viewport - " << SceneManager::GetActiveScene()->ID << "###"; 

				ImGui::Begin(windowTitle.str().c_str());			

				float windowWidth = ImGui::GetContentRegionAvail().x;
				float windowHeight = ImGui::GetContentRegionAvail().y;

				Viewport::SetSize(glm::vec2(windowWidth, windowHeight));
				glViewport(0, 0, windowWidth, windowHeight);

				ImVec2 windowPos = ImGui::GetCursorScreenPos();

				ImGui::GetWindowDrawList()->AddImage
				(
					(void *)Viewport::GetTexture(), 
					ImVec2(windowPos.x, windowPos.y), 
					ImVec2(windowPos.x + windowWidth, windowPos.y + windowHeight),
					ImVec2(0, 1), 
					ImVec2(1, 0)
				);

				ImGui::End();
			}

		private:
		};

		class SceneHierarchy
		{
		public:
			static void Update()
			{
				ImGui::Begin("Scene Hierarchy");

				m_Size = glm::vec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y);

				//TODO: Add objects to render and add to scenes.
				for (Scene* scene : SceneManager::GetScenes())
				{
					if (ImGui::TreeNode(scene->ID.c_str()))
					{
						if (ImGui::Button("Set Startup Scene")) 
							SceneManager::SetStartupScene(scene->ID);
						if (ImGui::Button("View Scene")) 
							SceneManager::SetActiveScene(scene->ID);

						if (ImGui::TreeNode("Entities"))
						{
							for (Entity* entity : scene->entityManager.GetEntities())
							{
								if (ImGui::TreeNode(entity->GetUUID().ID.c_str()))
								{
									ImGui::TextDisabled("UUID: %s", entity->GetUUID()().c_str());

									for (Component* component : entity->GetComponents())
									{
										const char* componentType;

										switch (component->GetType())
										{
										case VLK_SPRITE_COMPONENT:
											componentType = "Sprite Component";
										break;
										}

										if (ImGui::Selectable(componentType))
										{
											m_SelectedComponent	= component;
										}									
									}

									ImGui::TreePop();
								}
							}

							ImGui::TreePop();
						}						

						ImGui::TreePop();
					}
				}						

				ImGui::End();
			}

			static Component* GetSelectedComponent()
			{
				return m_SelectedComponent;
			}

		private:
			static inline glm::vec2 m_Position;
			static inline glm::vec2 m_Size;

			static inline Component* m_SelectedComponent = nullptr;
		};

		class Properties
		{
		public:
			static void Update()
			{
				ImGui::Begin("Properties");
				
				if (SceneHierarchy::GetSelectedComponent() != nullptr)
				{
					switch (SceneHierarchy::GetSelectedComponent()->GetType())
					{
						case VLK_SPRITE_COMPONENT:
						{
							SpriteComponent* component = (SpriteComponent*)SceneHierarchy::GetSelectedComponent();

							ImGui::PushID(1);
							ImGui::Text("Position");
							ImGui::InputFloat2("##", glm::value_ptr(component->Position));
							ImGui::PopID();

							ImGui::PushID(2);
							ImGui::Text("Size");
							ImGui::InputFloat2("##", glm::value_ptr(component->Size));
							ImGui::PopID();

							ImGui::PushID(3);
							ImGui::Text("Rotation");
							ImGui::InputFloat("##", &component->Rotation);
							ImGui::PopID();
						}
					}
				}				

				ImGui::End();
			}
		};
	};
}