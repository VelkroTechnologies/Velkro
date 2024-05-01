#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Log.h"

namespace Velkro::Renderer
{
	inline glm::vec3 BackgroundColour;

	inline void Init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			VLK_FATAL("Renderer: GLAD failed to initialize!");
		}
	}

	inline void Update()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glClearColor(BackgroundColour.x, BackgroundColour.y, BackgroundColour.z, 1.0f);
	}	
}