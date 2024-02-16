#include "pch.h"

#include "GlassBirdApplication.h"

namespace GlassBird
{
	void GlassBirdApplication::Initialize()
	{
	}

	void GlassBirdApplication::OnUpdate()
	{
	}

	void GlassBirdApplication::Shutdown()
	{
	}

	void GlassBirdApplication::Run()
	{
		Initialize();
		while (true)
		{
			OnUpdate();
		}

		Shutdown();
	}
	
}

