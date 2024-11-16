#pragma once

#include <iostream>
#include <cstdint>

#include <GLFW/glfw3.h>

#include "Event.h"

namespace Velkro
{
	typedef void(*EventFunction)(Event* event);

	class Window
	{
	public:
		Window() = default;
		Window(const char* title, uint32_t width, uint32_t height);
		~Window();

		const char* GetTitle();
		std::pair<uint32_t, uint32_t> GetSize();
		std::pair<uint32_t, uint32_t> GetPos();

		bool WindowClosed();

		static void SetEventCallback(EventFunction eventCallback);

		void Update();
		void Destroy();

	private:
		static void m_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void m_CharCallback(GLFWwindow* window, unsigned int codepoint);
		static void m_MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		static void m_MouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
		static void m_MouseMoveCallback(GLFWwindow* window, double xPos, double yPos);
		static void m_WindowResizeCallback(GLFWwindow* window, int width, int height);
		static void m_WindowMoveCallback(GLFWwindow* window, int xPos, int yPos);
		static void m_WindowMaximizeCallback(GLFWwindow* window, int maximized);
		static void m_WindowFocusCallback(GLFWwindow* window, int focused);
		static void m_WindowIconifyCallback(GLFWwindow* window, int iconified);

		GLFWwindow* m_Window;

		static inline EventFunction m_EventCallback;
	};
}