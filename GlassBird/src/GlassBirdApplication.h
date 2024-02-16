#pragma once

#include "Utility.h"

namespace GlassBird
{
	class GLASSBIRD_API GlassBirdApplication
	{
	public:
		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();

	private:

	};
}
