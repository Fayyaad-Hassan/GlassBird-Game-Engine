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
	GlassBirdApplication::GlassBirdApplication()
	{
		GlassBirdWindow::Init();
		GlassBirdWindow::GetWindow()->Create(1000, 800);

		Renderer::Init();

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

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

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;


		while (mShouldContinue)
		{
			Renderer::ClearScreen();
			OnUpdate();

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

	void GlassBirdApplication::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}
}

