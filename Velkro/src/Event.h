#pragma once

/* US Keyboard */

typedef unsigned int EventCode;

namespace Velkro
{
	enum EventType
	{
		VLK_KEY_EVENT, VLK_MOUSE_EVENT
	};

	enum Action
	{
		VLK_RELEASE, VLK_PRESS, VLK_HELD
	};

	class Event
	{
	public:
		virtual EventType GetEventType() = 0;
		virtual Action GetAction() = 0;
		virtual EventCode GetEventCode() = 0;
	};

	class KeyEvent : public Event
	{
	public:
		KeyEvent(Action action, EventCode code)
			: m_Action(action), m_Code(code)
		{
		}
		~KeyEvent()
		{
		}

		EventType GetEventType() override
		{
			return VLK_KEY_EVENT;
		}
		Action GetAction() override
		{
			return m_Action;
		}
		EventCode GetEventCode() override
		{
			return m_Code;
		}

	private:
		Action m_Action;
		EventCode m_Code;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent(Action action, EventCode code)
			: m_Action(action), m_Code(code)
		{
		}
		~MouseButtonEvent()
		{
		}

		EventType GetEventType() override
		{
			return VLK_MOUSE_EVENT;
		}
		Action GetAction() override
		{
			return m_Action;
		}
		EventCode GetEventCode() override
		{
			return m_Code;
		}

	private:
		Action m_Action;
		EventCode m_Code;
	};
}