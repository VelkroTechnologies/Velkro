#pragma once

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Log.h"

namespace Velkro::Renderer
{
	struct Vertex
	{
		Vertex(glm::vec3 position, glm::vec4 colour, glm::vec2 texCoords)
			: position(position), colour(colour), texCoords(texCoords)
		{			
		}

		glm::vec3 position;
		glm::vec4 colour;
		glm::vec2 texCoords;
	};

	class Buffer
	{
	public:
		Buffer()
		{
		}

		Buffer(const std::vector<Vertex> vertices, const std::vector<uint32_t> indices)
			: m_IndexCount(indices.size())
		{
			// Create and bind the vertex array object (VAO)
			glGenVertexArrays(1, &m_VAO);
			glBindVertexArray(m_VAO);

			// Create and bind the vertex buffer object (VBO)
			glGenBuffers(1, &m_VBO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_DYNAMIC_DRAW);

			// Create and bind the element buffer object (EBO)
			glGenBuffers(1, &m_EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), GL_DYNAMIC_DRAW);

			// Set the vertex attribute pointers
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, colour));
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
			glEnableVertexAttribArray(2);

			// Unbind the VAO
			glBindVertexArray(0);
		}

		~Buffer()
		{
		}

		void Render()
		{
			// Bind the VAO
			glBindVertexArray(m_VAO);

			// Render the elements
			glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, 0);

			// Unbind the VAO
			glBindVertexArray(0);
		}

		void Destroy()
		{
			// Delete the VAO, VBO, and EBO
			glDeleteVertexArrays(1, &m_VAO);
			glDeleteBuffers(1, &m_VBO);
			glDeleteBuffers(1, &m_EBO);
		}

	private:
		GLuint m_VAO;
		GLuint m_VBO;
		GLuint m_EBO;
		GLsizei m_IndexCount;
	};

	class Framebuffer
	{
	public:
		Framebuffer()
		{
		}
		Framebuffer(glm::vec2 size)
		{
			m_Size = size;

			glGenFramebuffers(1, &m_Framebuffer);
			glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
			
			glGenTextures(1, &m_Texture);
			glBindTexture(GL_TEXTURE_2D, m_Texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, size.x, size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBindTexture(GL_TEXTURE_2D, 0);

			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture, 0);

			glGenRenderbuffers(1, &m_RBO);
			glBindRenderbuffer(GL_RENDERBUFFER, m_RBO); 
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);  
			glBindRenderbuffer(GL_RENDERBUFFER, 0);

			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);

			if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
				VLK_ERROR("Renderer: Framebuffer isn't complete!");
			
			glBindFramebuffer(GL_FRAMEBUFFER, 0);  
		}
		~Framebuffer()
		{
		}

		void Resize(glm::vec2 size)
		{
			m_Size = size;

			glBindTexture(GL_TEXTURE_2D, m_Texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, size.x, size.y, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_Texture, 0);

			glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, size.x, size.y);
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);
		}

		void Bind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, m_Framebuffer);
		}
		void Unbind()
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}

		uint32_t GetTexture()
		{
			return m_Texture;
		}
		
		glm::vec2 GetSize()
		{
			return m_Size;
		}
	
	private:
		uint32_t m_Framebuffer;
		uint32_t m_Texture;
		uint32_t m_RBO;

		glm::vec2 m_Size;
	};
}
