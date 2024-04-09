#pragma once

#include "Input.h"

namespace Velkro
{
	class ExampleClass : public InputLayer
	{
	public:
		void OnEvent(std::unique_ptr<Event>& event) override
		{
			switch (event->GetAction())
			{
			case VLK_RELEASE:
				VLK_INFO("Key released");
				break;
			case VLK_PRESS:
				VLK_INFO("Key pressed");
				break;
			case VLK_HELD:
				VLK_INFO("Key held");
				break;
			}
		}
		
		bool PassEvent() override
		{
			return true;
		}
	};

	class ExampleClass2 : public InputLayer
	{
	public:
		void OnEvent(std::unique_ptr<Event>& event) override
		{
			switch (event->GetAction())
			{
			case VLK_RELEASE:
				VLK_ERROR("Key released");
				break;
			case VLK_PRESS:
				VLK_ERROR("Key pressed");
				break;
			case VLK_HELD:
				VLK_ERROR("Key held");
				break;
			}
		}

		bool PassEvent() override
		{
			return true;
		}
	};
}