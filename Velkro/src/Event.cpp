#include "Event.h"

namespace Velkro
{
	KeyEvent::KeyEvent(int code, int scancode, int action, int mods)
		: m_Code(code), m_Scancode(scancode), m_Action(action), m_Mods(mods)
	{
	}

	const EventType KeyEvent::GetType()
	{		
		return Key;
	}
	const int KeyEvent::GetCode()
	{
		return m_Code;
	}
	const int KeyEvent::GetScancode()
	{
		return m_Scancode;
	}
	const int KeyEvent::GetAction()
	{
		return m_Action;
	}
	const int KeyEvent::GetMods()
	{
		return m_Mods;
	}

	CharacterEvent::CharacterEvent(uint32_t codepoint)
		: m_Codepoint(codepoint)
	{
	}

	const EventType CharacterEvent::GetType()
	{
		return Character;
	}
	const int CharacterEvent::GetCodepoint()
	{
		return m_Codepoint;
	}

	MouseButtonEvent::MouseButtonEvent(int code, int action, int mods)
		: m_Code(code), m_Action(action), m_Mods(mods)
	{
	}

	const EventType MouseButtonEvent::GetType()
	{
		return MouseButton;
	}
	const int MouseButtonEvent::GetCode()
	{
		return m_Code;
	}
	const int MouseButtonEvent::GetAction()
	{
		return m_Action;
	}
	const int MouseButtonEvent::GetMods()
	{
		return m_Mods;
	}

	MouseScrollEvent::MouseScrollEvent(double xOffset, double yOffset)
		: m_XOffset(xOffset), m_YOffset(yOffset)
	{
	}

	const EventType MouseScrollEvent::GetType()
	{
		return MouseScroll;
	}
	const double MouseScrollEvent::GetXOffset()
	{
		return m_XOffset;
	}
	const double MouseScrollEvent::GetYOffset()
	{
		return m_YOffset;
	}

	MouseMoveEvent::MouseMoveEvent(double xPos, double yPos)
		: m_XPos(xPos), m_YPos(yPos)
	{
	}

	const EventType MouseMoveEvent::GetType()
	{
		return MouseMove;
	}
	const double MouseMoveEvent::GetXPos()
	{
		return m_XPos;
	}
	const double MouseMoveEvent::GetYPos()
	{
		return m_YPos;
	}

	WindowResizeEvent::WindowResizeEvent(int width, int height)
		: m_Width(width), m_Height(height)
	{
	}

	const EventType WindowResizeEvent::GetType()
	{
		return WindowResize;
	}
	const int WindowResizeEvent::GetWidth()
	{
		return m_Width;
	}
	const int WindowResizeEvent::GetHeight()
	{
		return m_Height;
	}

	WindowMoveEvent::WindowMoveEvent(int xPos, int yPos)
		: m_XPos(xPos), m_YPos(yPos)
	{
	}

	const EventType WindowMoveEvent::GetType()
	{
		return WindowMove;
	}
	const int WindowMoveEvent::GetXPos()
	{
		return m_XPos;
	}
	const int WindowMoveEvent::GetYPos()
	{
		return m_YPos;
	}

	WindowMaximizeEvent::WindowMaximizeEvent(int maximized)
		: m_Maximized(maximized)
	{
	}

	const EventType WindowMaximizeEvent::GetType()
	{
		return WindowMaximize;
	}
	const int WindowMaximizeEvent::GetMaximized()
	{
		return m_Maximized;
	}

	WindowFocusEvent::WindowFocusEvent(int focused)
		: m_Focused(focused)
	{
	}

	const EventType WindowFocusEvent::GetType()
	{
		return WindowFocus;
	}
	const int WindowFocusEvent::GetFocused()
	{
		return m_Focused;
	}

	WindowIconifyEvent::WindowIconifyEvent(int iconified)
		: m_Iconified(iconified)
	{
	}

	const EventType WindowIconifyEvent::GetType()
	{
		return WindowIconify;
	}
	const int WindowIconifyEvent::GetFocused()
	{
		return m_Iconified;
	}
}