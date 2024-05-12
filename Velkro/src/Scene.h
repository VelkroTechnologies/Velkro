#pragma once

#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include "Log.h"

namespace Velkro
{
	class Scene
	{
	public:
		Scene(std::string ID)
			: ID(ID)
		{
		}
		~Scene()
		{
			entityManager.Destroy();
		}
		
		void AddEntity(Entity* entity)
		{
			entityManager.AddEntity(entity);
		}

		void RemoveEntity(UUID ID)
		{
			entityManager.RemoveEntity(ID);
		}

		void Update()
		{
			entityManager.Update();
		}

		EntityManager entityManager;

		std::string ID;
	};

	class SceneManager
	{
	public:
		static void AddScene(Scene* scene)
		{
			bool dontDuplicate = false;

			for (Scene* otherScene : m_Scenes)
			{
				if (otherScene->ID == scene->ID)
				{
					dontDuplicate = true;
				}
			}

			if (!dontDuplicate)
			{
				m_Scenes.push_back(scene);
			}
		}

		static void RemoveScene(std::string ID)
		{
			for (auto it = m_Scenes.begin(); it != m_Scenes.end(); ++it)
			{
				if ((*it)->ID == ID)
				{
					delete* it;
					m_Scenes.erase(it);

					break;
				}
			}
		}

		static Scene* GetScene(std::string ID)
		{
			for (Scene* scene : m_Scenes)
			{
				if (scene->ID == ID)
				{
					return scene;
				}
			}

			VLK_ERROR("Scene Manager: You cannot access scene \"%o\" as it doesn't exist!", ID.c_str());

			return nullptr;
		}

		static void SetActiveScene(std::string ID)
		{
			bool success = false;

			for (size_t i = 0; i < m_Scenes.size(); i++)
			{
				if (m_Scenes[i]->ID == ID)
				{
					m_ActiveSceneIndex = i;

					success = true;

					break;
				}
			}

			if (!success)
			{
				VLK_ERROR("Can't set active scene as it doesn't exist!");
			}
		}
		static void SetStartupScene(std::string ID)
		{
			bool success = false;

			for (size_t i = 0; i < m_Scenes.size(); i++)
			{
				if (m_Scenes[i]->ID == ID)
				{
					m_StartupSceneIndex = i;

					success = true;

					break;
				}
			}

			if (!success)
			{
				VLK_ERROR("Can't set startup scene as it doesn't exist!");
			}
		}

		static Scene* GetActiveScene()
		{
			return m_Scenes[m_ActiveSceneIndex];
		}
		static Scene* GetStartupScene()
		{
			return m_Scenes[m_StartupSceneIndex];
		}

		static std::vector<Scene*>& GetScenes()
		{
			return m_Scenes;
		}

		static void Update()
		{
			for (size_t i = 0; i < m_Scenes.size(); i++)
			{
				if (m_ActiveSceneIndex == i)
				{
					m_Scenes[i]->Update();
				}
			}
		}

		static void Destroy()
		{
			for (size_t i = 0; i < m_Scenes.size(); i++)
			{
				delete m_Scenes[i];

				m_Scenes.erase(m_Scenes.begin() + i);
			}
		}

	private:
		static inline std::vector<Scene*> m_Scenes;

		static inline std::string m_ActiveScene;
		static inline size_t m_ActiveSceneIndex;
		static inline size_t m_StartupSceneIndex;
	};
}