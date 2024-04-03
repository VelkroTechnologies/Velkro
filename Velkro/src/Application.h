#pragma once

#include "Core.h"
#include "Log.h"

namespace Velkro
{
	class Application
	{
	public:
		void Run();

	private:
		bool m_Running = true;
	};
}