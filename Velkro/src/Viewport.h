#pragma once

#include "Renderer/Buffer.h"

namespace Velkro
{
	class Viewport
	{
	public:
		static void Init(glm::vec2 size)
		{
			m_Framebuffer = Renderer::Framebuffer(size);
		}

		static void SetSize(glm::vec2 size)
		{
			m_Size = size;

			m_Framebuffer.Resize(size);
		}

		static glm::vec2 GetSize()
		{
			return m_Size;
		}

		static uint32_t GetTexture()
		{
			return m_Framebuffer.GetTexture();
		}

		static void Bind()
		{
			m_Framebuffer.Bind();
		}
		static void Unbind()
		{
			m_Framebuffer.Unbind();
		}		

	private:
		static inline glm::vec2 m_Size;
		
		static inline Renderer::Framebuffer m_Framebuffer;
	};
}