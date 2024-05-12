#pragma once

#include <iostream>
#include <vector>

#include <memory>

#include "Component.h"

#include "../UUID.h"

namespace Velkro
{
	class Entity
	{
	public:
		Entity(UUID uuid)
			: m_UUID(uuid)
		{			
		}

		~Entity()
		{
			for (Component* component : m_Components)
			{
				delete component;
				
				m_Components.pop_back();
			}
		}

		UUID GetUUID()
		{
			return m_UUID;
		}

		void AddComponent(Component* component)
		{
			bool found;

			for (size_t i = 0; i < m_Components.size(); i++)
			{
				if (m_Components[i] == component)
				{
					found = true;
				}
			}

			if (!found)
			{
				component->Init();

				m_Components.push_back(component);
			}
			else
			{
				VLK_ERROR("Component already exists!");
			}
		}

		Component* GetComponent(ComponentType componentType)
		{
		    for (size_t i = 0; i < m_Components.size(); i++)
		    {
		        if (m_Components[i]->GetType() == componentType)
		        {
		            return m_Components[i];
		        }
		    }
		
		    VLK_ERROR("ECS: The entity doesn't have the component you requested to get.");
		    return nullptr; // If no component found, return nullptr
		}		

		Component* RemoveComponent(ComponentType componentType)
		{
			bool success = false;

			for (size_t i = 0; i < m_Components.size(); i++)
			{
				if (m_Components[i]->GetType() == componentType)
				{
					return m_Components[i];

					success = true;

					break;
				}
			}

			if (!success)
			{
				VLK_ERROR("ECS: The entity doesn't have the component you requested to delete.");

				throw(errno);
			}
		}

		std::vector<Component*>& GetComponents()
		{
			return m_Components;
		}

		void Update()
		{
			for (size_t i = 0; i < m_Components.size(); i++)
			{
				m_Components[i]->Update(); 
			}
		}

	private:
		UUID m_UUID;

		std::vector<Component*> m_Components;
	};	

	class EntityManager
	{
	public:
		void AddEntity(Entity* entity)
		{
			m_Entities.push_back(std::move(entity));
		}

		void RemoveEntity(UUID uuid)
		{
			bool success = false;

			for (size_t i = 0; i < m_Entities.size(); i++)
			{
				if (m_Entities[i]->GetUUID() == uuid)
				{
				   	delete m_Entities[i];

					m_Entities.erase(m_Entities.begin() + i);

					success = true;

					break;
				}
			}

			if (!success)
			{
				VLK_ERROR("Entity \"%s\" (%s) can't be removed as it doesn't exist.", uuid.ID, uuid.uuid);
			}
		}

		void Update()
		{
			for (size_t i = 0; i < m_Entities.size(); i++)
			{
				m_Entities[i]->Update();
			}
		}

		void Destroy()
		{
			for (size_t i = 0; i < m_Entities.size(); i++)
			{
				delete m_Entities[i];
				
				m_Entities.erase(m_Entities.begin() + i);
			}
		}

		std::vector<Entity*>& GetEntities()
		{
			return m_Entities;
		}
	
	private:
		std::vector<Entity*> m_Entities;
	};
}