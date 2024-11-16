#include "Window.h"

namespace Velkro
{
	Window::Window(const char* title, uint32_t width, uint32_t height)
	{
		m_Window = glfwCreateWindow(width, height, title, NULL, NULL);

		glfwMakeContextCurrent(m_Window);

		glfwSetKeyCallback(m_Window, m_KeyCallback);
		glfwSetCharCallback(m_Window, m_CharCallback);
		glfwSetMouseButtonCallback(m_Window, m_MouseButtonCallback);
		glfwSetScrollCallback(m_Window, m_MouseScrollCallback);
		glfwSetCursorPosCallback(m_Window, m_MouseMoveCallback);
		glfwSetWindowSizeCallback(m_Window, m_WindowResizeCallback);
		glfwSetWindowPosCallback(m_Window, m_WindowMoveCallback);
		glfwSetWindowMaximizeCallback(m_Window, m_WindowMaximizeCallback);
		glfwSetWindowFocusCallback(m_Window, m_WindowFocusCallback);
		glfwSetWindowIconifyCallback(m_Window, m_WindowIconifyCallback);
	}
	Window::~Window()
	{
	}

	const char* Window::GetTitle()
	{
		return glfwGetWindowTitle(m_Window);
	}
	std::pair<uint32_t, uint32_t> Window::GetSize()
	{
		int width = 0;
		int height = 0;

		glfwGetWindowSize(m_Window, &width, &height);

		return std::make_pair(width, height);
	}
	std::pair<uint32_t, uint32_t> Window::GetPos()
	{
		int x = 0;
		int y = 0;

		glfwGetWindowPos(m_Window, &x, &y);

		return std::make_pair(x, y);
	}

	bool Window::WindowClosed()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::SetEventCallback(EventFunction eventCallback)
	{
		m_EventCallback = eventCallback;
	}

	void Window::Update()
	{
		glfwSwapBuffers(m_Window);
	}
	void Window::Destroy()
	{
		glfwDestroyWindow(m_Window);
	}

	void Window::m_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		KeyEvent* keyEvent = new KeyEvent(key, scancode, action, mods);
		
		m_EventCallback(keyEvent);
	}
	void Window::m_CharCallback(GLFWwindow* window, unsigned int codepoint)
	{
		CharacterEvent* charEvent = new CharacterEvent(codepoint);

		m_EventCallback(charEvent);
	}
	void Window::m_MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		MouseButtonEvent* mouseButtonEvent = new MouseButtonEvent(button, action, mods);

		m_EventCallback(mouseButtonEvent);
	}
	void Window::m_MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		MouseScrollEvent* mouseScrollEvent = new MouseScrollEvent(xOffset, yOffset);

		m_EventCallback(mouseScrollEvent);
	}
	void Window::m_MouseMoveCallback(GLFWwindow* window, double xPos, double yPos)
	{
		MouseMoveEvent* mouseMoveEvent = new MouseMoveEvent(xPos, yPos);

		m_EventCallback(mouseMoveEvent);
	}
	void Window::m_WindowResizeCallback(GLFWwindow* window, int width, int height)
	{
		WindowResizeEvent* windowResizeEvent = new WindowResizeEvent(width, height);

		m_EventCallback(windowResizeEvent);
	}
	void Window::m_WindowMoveCallback(GLFWwindow* window, int xPos, int yPos)
	{
		WindowMoveEvent* windowMoveEvent = new WindowMoveEvent(xPos, yPos);

		m_EventCallback(windowMoveEvent);
	}
	void Window::m_WindowMaximizeCallback(GLFWwindow* window, int maximized)
	{
		WindowMaximizeEvent* windowMaximizeEvent = new WindowMaximizeEvent(maximized);

		m_EventCallback(windowMaximizeEvent);
	}
	void Window::m_WindowFocusCallback(GLFWwindow* window, int focused)
	{
		WindowFocusEvent* windowFocusEvent = new WindowFocusEvent(focused);

		m_EventCallback(windowFocusEvent);
	}
	void Window::m_WindowIconifyCallback(GLFWwindow* window, int iconified)
	{
		WindowIconifyEvent* windowIconifyEvent = new WindowIconifyEvent(iconified);

		m_EventCallback(windowIconifyEvent);
	}
}