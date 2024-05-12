#pragma once

#include <glm/glm.hpp>

#include "../Renderer/Buffer.h"
#include "../Renderer/Shader.h"
#include "../Renderer/Texture2D.h"

#include "../Log.h"
#include "../Core.h"
#include "../Viewport.h"

namespace Velkro
{
	enum ComponentType
	{
		VLK_SPRITE_COMPONENT,
	};

	class Component
	{
	public:
		Component()
		{
		}
		virtual ~Component()
		{
		}

		virtual void Init() = 0;

		virtual void Update() = 0;
		virtual ComponentType GetType() = 0;
	};

	class SpriteComponent : public Component
	{
	public:
		SpriteComponent(glm::vec2 position, glm::vec2 size, float rotation,
						std::string textureFilePath = VLK_ASSETS_DIR + "textures/defaultTexture.png", bool linearInterpolation = false)
			: Position(position), Size(size), Rotation(rotation), m_TextureFilePath(textureFilePath), m_LinearInterpolation(linearInterpolation)
		{
		}
		~SpriteComponent()
		{
			m_Buffer.Destroy();
			m_Shader.Destroy();
			m_Texture.Destroy();
		}

		void Init() override
		{
			m_Shader = Renderer::Shader::LoadGLSLFile(VLK_ASSETS_DIR + "shaders/spriteShader.vert.glsl",
													  VLK_ASSETS_DIR + "shaders/spriteShader.frag.glsl");
			// Vertices coordinates

			std::vector<Renderer::Vertex> vertices =
			{
				// Positions      -	Texture Coordinates
				Renderer::Vertex(glm::vec3(-0.5f,-0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
				Renderer::Vertex(glm::vec3( 0.5f,-0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
				Renderer::Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
				Renderer::Vertex(glm::vec3( 0.5f, 0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
			};

			// Indices for vertices order
			std::vector<uint32_t> indices =
			{
				0, 1, 2, // Lower left triangle
				1, 2, 3,
			};

			m_Buffer = Renderer::Buffer(vertices, indices);
			
			m_Texture = Renderer::Texture2D::CreateTextureFromFile(m_TextureFilePath);
		}

		void Update() override
		{
			m_Shader.Bind();

			glm::mat4 projection = glm::ortho(0.0f, Viewport::GetSize().x * (Viewport::GetSize().x / Viewport::GetSize().y), 0.0f, 
													Viewport::GetSize().y * (Viewport::GetSize().x / Viewport::GetSize().y), -1.0f, 1.0f);
			
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(Position, 0.0f));
			model = glm::translate(model, glm::vec3(0.5f * Size.x, 0.5f * Size.y, 0.0f));			
			model = glm::translate(model, glm::vec3(-0.5f * Size.x, -0.5f * Size.y, 0.0f));
			model = glm::scale(model, glm::vec3(Size, 1.0f)); 
			model = glm::rotate(model, glm::radians(Rotation), glm::vec3(0.0f, 0.0f, 1.0f)); 

			glUniformMatrix4fv(glGetUniformLocation(m_Shader.GetID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
			glUniformMatrix4fv(glGetUniformLocation(m_Shader.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(model));

			m_Texture.Bind();

			m_Buffer.Render();

			m_Shader.UnBind();
		}

		ComponentType GetType() override
		{
			return VLK_SPRITE_COMPONENT;
		}

		glm::vec2 Position = glm::vec2(100, 100);
		glm::vec2 Size = glm::vec2(100, 100);
		float Rotation = 0;
		
	private:
		std::string m_TextureFilePath;
		bool m_LinearInterpolation;

		Renderer::Shader m_Shader;
		Renderer::Buffer m_Buffer;
		Renderer::Texture2D m_Texture;

		std::vector<Renderer::Vertex> m_Vertices =
		{
			// Positions      -	Texture Coordinates
			Renderer::Vertex(glm::vec3(-0.5f,-0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)),
			Renderer::Vertex(glm::vec3( 0.5f,-0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)),
			Renderer::Vertex(glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)),
			Renderer::Vertex(glm::vec3( 0.5f, 0.5f, 0.0f), glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)),
		};
		
		std::vector<uint32_t> m_Indices =
		{
			0, 1, 2,
			1, 2, 3,
		};
	};
}