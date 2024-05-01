#pragma once

#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include "Log.h"

namespace Velkro
{
	class AssetPackage
	{
	public:
		AssetPackage()
		{
		}

		~AssetPackage()
		{
		}

		/* Data Pushing to Data Vector */

	private:
		/* Data Vector */
	};

	class Scene
	{
	public:
		Scene(std::string ID)
			: ID(ID)
		{
		}
		~Scene()
		{
		}

		void Update()
		{
		}

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

		static Scene* GetActiveScene()
		{
			return m_Scenes[m_ActiveSceneIndex];
		}

		static std::vector<Scene*>& GetScenes()
		{
			return m_Scenes;
		}

		static void Update()
		{
			for (Scene* scene : m_Scenes)
			{
				scene->Update();
			}
		}

		static void Destroy()
		{
			for (auto it = m_Scenes.begin(); it != m_Scenes.end(); ++it)
			{
				delete* it;
				m_Scenes.erase(it);
			}
		}

	private:
		static inline std::vector<Scene*> m_Scenes;

		static inline std::string m_ActiveScene;
		static inline size_t m_ActiveSceneIndex;
	};
}