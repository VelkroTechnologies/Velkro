#pragma once

#include "Input.h"

#include <imgui.h>

namespace Velkro
{
	class GUIinput : public InputLayer
	{
	public:
		void OnEvent(std::unique_ptr<Event>& event) override
		{
			switch (event->GetEventType())
			{
			case VLK_MOUSE_EVENT:
				ImGuiIO& io = ImGui::GetIO();
				io.AddMouseButtonEvent((int)event->GetEventCode(), event->GetAction() == VLK_PRESS);
				
				if (io.WantCaptureMouse)
					m_PassEvent = false;

				break;
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