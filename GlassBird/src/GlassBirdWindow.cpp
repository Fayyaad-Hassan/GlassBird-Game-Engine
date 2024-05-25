#include"pch.h"
#include"GlassBirdWindow.h"
#include"codeGLFW/WindowGLFW.h"

namespace GlassBird
{
	GlassBirdWindow::GlassBirdWindow()
	{
#ifdef GLASSBIRD_GLFW_WINDOW
		mWindow = std::unique_ptr<WindowImpl>{ new WindowGLFW };
#else 
	#definition_GLASSBIRD_GLFW_is_missing
#endif
	}



	void GlassBirdWindow::Init()
	{
		if (!mInstance)
			mInstance = new GlassBirdWindow;
	}

	GlassBirdWindow* GlassBirdWindow::GetWindow()
	{
		return mInstance;
	}

	void GlassBirdWindow::ShutDown()
	{
		if (mInstance)
			delete mInstance;
	}



	void GlassBirdWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GlassBirdWindow::PollEvents()
	{
		mWindow->PollEvents();
	}

	void GlassBirdWindow::Create(int width, int height)
	{
		mWindow->Create(width, height);
	}

	int GlassBirdWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int GlassBirdWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}

	void GlassBirdWindow::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow->SetKeyPressedCallback(callbackFunc);
	}

	void GlassBirdWindow::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow->SetKeyReleasedCallback(callbackFunc);
	}

	void GlassBirdWindow::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		mWindow->SetWindowCloseCallback(callbackFunc);
	}

}