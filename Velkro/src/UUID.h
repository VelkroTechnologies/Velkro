#pragma once

#include <random>
#include <chrono>

#include <iostream>
#include <sstream>

#include <map>

namespace Velkro
{
	class UUID
	{
	public:
		std::string uuid;
		std::string ID;

		UUID()
		{
		}

		UUID(std::string ID, std::string UUID)
			: ID(ID), uuid(UUID)
		{
		}

		static UUID GenUUID(std::string ID)
		{
			// Get current time since epoch in milliseconds
			auto now = std::chrono::system_clock::now().time_since_epoch();
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();

			// Generate a random number using a random device
			
			std::mt19937 gen(m_RandomDevice());
			std::uniform_int_distribution<> dis(0, 255);
			int randomNum1 = dis(gen);
			int randomNum2 = dis(gen);

			// Combine timestamp and random numbers to create a unique identifier
			std::stringstream ss;
			ss << std::hex << ms << randomNum1 << randomNum2;
			std::string uuidStr = ss.str();

			UUID uuid(ID, uuidStr);

			m_UUIDMap[ID] = uuid;

			return uuid;
		}

		static UUID GetUUID(std::string ID)
		{
			return m_UUIDMap[ID];
		}

		bool operator==(UUID other)
		{
			return other.ID == ID && other.uuid == other.uuid;
		}

		std::string& operator()()
		{
			return uuid;
		}
		
	private:
		static inline std::random_device m_RandomDevice;

		static inline std::map<std::string /* ID */, UUID /* UUID */> m_UUIDMap;
	};
}