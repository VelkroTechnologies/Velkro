#pragma once

#include <iostream>

namespace Velkro
{		
	enum EventType
	{
		Key,
		Character,
		MouseButton, MouseScroll, MouseMove, 
		WindowResize, WindowMove, WindowMaximize, WindowFocus, WindowIconify
	};

	class Event
	{
	public:
		Event() = default;
		~Event() = default;

		virtual const EventType GetType() = 0;
	};

	class KeyEvent : public Event
	{
	public:
		KeyEvent() = default;
		KeyEvent(int code, int scancode, int action, int mods);
		~KeyEvent() = default;

		const EventType GetType() override;
		const int GetCode();
		const int GetScancode();
		const int GetAction();
		const int GetMods();

	private:
		int m_Code, m_Scancode, m_Action, m_Mods;
	};

	class CharacterEvent : public Event
	{
	public:
		CharacterEvent() = default;
		CharacterEvent(uint32_t codepoint);
		~CharacterEvent() = default;

		const EventType GetType() override;
		const int GetCodepoint();

	private:
		int m_Codepoint;
	};

	class MouseButtonEvent : public Event
	{
	public:
		MouseButtonEvent() = default;
		MouseButtonEvent(int code, int action, int mods);
		~MouseButtonEvent() = default;

		const EventType GetType() override;
		const int GetCode();
		const int GetAction();
		const int GetMods();

	private:
		int m_Code, m_Action, m_Mods;
	};
	
	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent() = default;
		MouseScrollEvent(double xOffset, double yOffset);
		~MouseScrollEvent() = default;

		const EventType GetType() override;
		const double GetXOffset();
		const double GetYOffset();

	private:
		double m_XOffset, m_YOffset;
	};

	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent() = default;
		MouseMoveEvent(double xpos, double ypos);
		~MouseMoveEvent() = default;

		const EventType GetType() override;
		const double GetXPos();
		const double GetYPos();

	private:
		double m_XPos, m_YPos;
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent() = default;
		WindowResizeEvent(int width, int height);
		~WindowResizeEvent() = default;

		const EventType GetType() override;
		const int GetWidth();
		const int GetHeight();

	private:
		int m_Width, m_Height;
	};

	class WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent() = default;
		WindowMoveEvent(int xPos, int yPos);
		~WindowMoveEvent() = default;

		const EventType GetType() override;
		const int GetXPos();
		const int GetYPos();

	private:
		int m_XPos, m_YPos;
	};

	class WindowMaximizeEvent : public Event
	{
	public:
		WindowMaximizeEvent() = default;
		WindowMaximizeEvent(int maximized);
		~WindowMaximizeEvent() = default;

		const EventType GetType() override;
		const int GetMaximized();

	private:
		int m_Maximized;
	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() = default;
		WindowFocusEvent(int focused);
		~WindowFocusEvent() = default;

		inline const EventType GetType() override;
		inline const int GetFocused();

	private:
		int m_Focused;
	};

	class WindowIconifyEvent : public Event
	{
	public:
		WindowIconifyEvent() = default;
		WindowIconifyEvent(int iconified);
		~WindowIconifyEvent() = default;

		const EventType GetType() override;
		const int GetFocused();

	private:
		int m_Iconified;
	};
}