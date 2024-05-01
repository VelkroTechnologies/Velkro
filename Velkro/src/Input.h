#pragma once

#include <memory>
#include <vector>

#include "Event.h"

namespace Velkro
{
	class InputLayer
	{
	public:
		virtual void OnEvent(std::unique_ptr<Event>& event) = 0;
		virtual bool PassEvent() = 0;
	};

	class InputStack
	{
	public:
		static void OnEvent(std::unique_ptr<Event>& event)
		{
			for (size_t i = 0; i < m_Layers.size(); i++)
			{
				m_Layers[i]->OnEvent(event);
				
				if (!m_Layers[i]->PassEvent())
				{
					break;
				}
			}
		}

		static void PushLayer(std::unique_ptr<InputLayer>& layer)
		{
			m_Layers.push_back(std::move(layer));
		}

		static void PopLayer()
		{
			if (!m_Layers.empty())
			{
				m_Layers.pop_back();
			}
			else
			{
				VLK_ERROR("Input Layer Stack empty! Popping layer failed.");
			}
		}

		static void Clear()
		{
			for (size_t i = 0; i < m_Layers.size(); i++)
			{
				m_Layers[i].reset();
			}

			m_Layers.clear();
		}

	private:
		static inline std::vector<std::unique_ptr<InputLayer>> m_Layers;
	};
}