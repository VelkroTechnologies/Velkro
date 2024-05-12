#pragma once

#include <glad/glad.h>
#include <stb_image.h>

#include <iostream>

#include "../Log.h"

namespace Velkro::Renderer
{
	enum ImageType
	{
		VLK_JPEG,
		VLK_PNG
	};

	class Texture2D
	{
	public:
		Texture2D()
		{
		}
		Texture2D(uint32_t ID, uint32_t width, uint32_t height)
			: m_ID(ID), m_Width(width), m_Height(height)
		{
		}
		
		~Texture2D()
		{
		}

		static Texture2D CreateTextureFromFile(std::string path, bool linear = false)
		{
			uint32_t texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			
			GLuint glFilter = GL_NEAREST;

			if (linear)
			{
				glFilter = GL_LINEAR;
			}

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, glFilter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, glFilter);
			
			stbi_set_flip_vertically_on_load(true);

			int width, height, nrChannels;
			uint8_t* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

			if (data)
			{
				GLenum pixelFormat;

				switch (nrChannels)
				{
				case 3:
					pixelFormat = GL_RGB;
					break;
				case 4:
					pixelFormat = GL_RGBA;
					break;
				}

				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, pixelFormat, GL_UNSIGNED_BYTE, data);
				glGenerateMipmap(GL_TEXTURE_2D);
			}
			else
			{
				VLK_ERROR("Failed to load texture. File path: %s", path.c_str());
			}

			stbi_image_free(data);

			return Texture2D(texture, width, height);
		}

		void Bind()
		{
			glBindTexture(GL_TEXTURE_2D, m_ID);
		}

		void UnBind()
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		float GetWidth()
		{
			return m_Width;
		}

		float GetHeight()
		{
			return m_Height;
		}
		
		void Destroy()
		{
			glDeleteTextures(1, &m_ID);
		}

	private:
		float m_Width;
		float m_Height;

		uint32_t m_ID;
	};
}