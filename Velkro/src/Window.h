#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <memory>

#include "Event.h"
#include "Log.h"

namespace Velkro
{
   	typedef void (*EventCallback)(Event* event);

   	class Window
   	{
   	public:
		Window(const char* title, glm::vec2 size)
			: m_Title(title), m_Size(size)
		{
			if (!m_Init)
			{
				if (!glfwInit())
				{
					VLK_FATAL("GLFW failed to initialize!");
				}
			}

			m_Window = glfwCreateWindow(size.x, size.y, title, nullptr, nullptr);

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

	  	void SetSize(glm::vec2& size)
	  	{
			glfwSetWindowSize(m_Window, size.x, size.y);

			m_Size = size;
	  	}
	  	glm::vec2 GetSize()
	  	{
			return m_Size;
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
			m_EventCallback(new KeyEvent((Action)action, (EventCode)key));
		}
		
		static void OnMouseButtonEvent(GLFWwindow* window, int button, int action, int mods)
		{
			m_EventCallback(new MouseButtonEvent((Action)action, (EventCode)button));
		}

		GLFWwindow* m_Window;
		
		bool m_Init = false;

		static inline EventCallback m_EventCallback;

		const char* m_Title;
		
		glm::vec2 m_Size;
   	};
}