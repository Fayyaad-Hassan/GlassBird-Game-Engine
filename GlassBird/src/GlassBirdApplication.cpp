#include "pch.h"

#include "GlassBirdApplication.h"
#include "GlassBirdWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Image.h"
#include "Shader.h"
#include "GlassBirdKeys.h"

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

		Renderer::Init();


		/// TEXTURE ///

		GlassBird::Image pic{"C:\\Users\\hassa\\Desktop\\s24\\S24_Fayyaad_Hassan\\GlassBird\\Assets\\Textures\\Test.png"};

		Initialize();

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		int x{ 50 };

		SetKeyPressedCallback([&x](const KeyPressed& event) 
			{
				if (event.GetKeyCode() == GLASSBIRD_KEY_RIGHT)
					x += 50;
			});

		while (true)
		{
			Renderer::ClearScreen();
			OnUpdate();

			Renderer::Draw(pic, x, 100);

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			GlassBirdWindow::GetWindow()->SwapBuffers();
			GlassBirdWindow::GetWindow()->PollEvents();
		}

		Shutdown();

		GlassBirdWindow::ShutDown();
	}

	void GlassBirdApplication::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		GlassBirdWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void GlassBirdApplication::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GlassBirdWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}
	
	void GlassBirdApplication::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GlassBirdWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}
}

