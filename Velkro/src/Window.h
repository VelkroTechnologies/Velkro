#pragma once

#include <GLFW/glfw3.h>
#include <memory>

#include "Event.h"
#include "Log.h"

namespace Velkro
{
   	typedef void (*EventCallback)(std::unique_ptr<Event> event);

   	class Window
   	{
   	public:
		Window(const char* title, int width, int height)
			: m_Title(title), m_Width(width), m_Height(height)
		{
			if (!m_Init)
			{
				if (!glfwInit())
				{
					VLK_FATAL("GLFW failed to initialize!");
				}
			}

			m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);

			glfwMakeContextCurrent(m_Window);
		}
      	~Window()
      	{
			glfwTerminate();
      	}

      	void Update()
      	{
			glfwSetKeyCallback(m_Window, OnKeyEvent);
			glfwSetMouseButtonCallback(m_Window, OnMouseButtonEvent);

			glfwSwapBuffers(m_Window);			
			glfwPollEvents();
      	} 
      	
      	void SetTitle(const char* title)
      	{
			glfwSetWindowTitle(m_Window, title);
			m_Title = title;
      	}
      	const char* GetTitle()
      	{
			return m_Title;
      	}

      	void SetSize(unsigned int width, unsigned int height)
      	{
			glfwSetWindowSize(m_Window, width, height);
			m_Width = width; m_Height = height;
      	}
      	void GetSize(unsigned int& width, unsigned int& height)
      	{
			width = m_Width;
			height = m_Height;
      	}

		bool WantClose()
		{
			return glfwWindowShouldClose(m_Window);
		}

      	static void SetEventCallback(EventCallback callback)
		{
			m_EventCallback = callback;
		}

		GLFWwindow* GetGLFWWindow()
		{
			return m_Window;
		}

   	private:
		/* Callbacks */
		static void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			m_EventCallback(std::make_unique<Velkro::KeyEvent>((Action)action, (EventCode)key));
		}
		
		static void OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
		{
			m_EventCallback(std::make_unique<Velkro::MouseButtonEvent>((Action)action, (EventCode)button));
		}

		GLFWwindow* m_Window;
		
		bool m_Init = false;

		static inline EventCallback m_EventCallback;

		const char* m_Title;
		int m_Width;
		int m_Height;
   	};
}