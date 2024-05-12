#pragma once

#include "Input.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>

namespace Velkro
{
	class GUIinput : public InputLayer
	{
	public:
		void OnEvent(Event* event) override
		{
			ImGuiIO& io = ImGui::GetIO();

			switch (event->GetEventType())
			{
				case VLK_MOUSE_EVENT:
				{
					MouseButtonEvent* mouseButtonEvent = (MouseButtonEvent*)event;

					io.AddMouseButtonEvent((int)mouseButtonEvent->GetMouseButtonEventCode(), mouseButtonEvent->GetAction() == VLK_PRESS);
					
					if (io.WantCaptureMouse)
						m_PassEvent = false;

					break;
				}				
				case VLK_KEY_EVENT:
				{
					KeyEvent* keyEvent = (KeyEvent*)event;

					io.AddKeyEvent(ImGui_ImplGlfw_KeyToImGuiKey(keyEvent->GetKeyCode()), keyEvent->GetAction() == VLK_PRESS);

					if (io.WantCaptureKeyboard)
						m_PassEvent = false;

					break;
				}				
			}
		}

		bool PassEvent() override
		{
			return m_PassEvent;
		}

	private:
		bool m_PassEvent = true;
	};
}