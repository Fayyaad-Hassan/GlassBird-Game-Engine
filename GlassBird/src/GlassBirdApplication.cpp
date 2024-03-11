#include "pch.h"

#include "GlassBirdApplication.h"
#include "GlassBirdWindow.h"

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
		GlassBirdWindow::Init();
		GlassBirdWindow::GetWindow()->Create(1000, 800);

		Initialize();

		while (true)
		{
			OnUpdate();

			GlassBirdWindow::GetWindow()->SwapBuffers();
			GlassBirdWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		GlassBirdWindow::ShutDown();
	}
	
}

