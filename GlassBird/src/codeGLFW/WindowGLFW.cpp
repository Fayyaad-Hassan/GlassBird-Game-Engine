#include "pch.h"

#include "WindowGLFW.h"

namespace GlassBird
{
	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	void WindowGLFW::Create(int width, int height)
	{
		mWindow = glfwCreateWindow(width, height, "MyGame", NULL, NULL);
		assert(mWindow != NULL);
		glfwMakeContextCurrent(mWindow);
	}

	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}

	int WindowGLFW::GetWidth() const
	{
		int width, height; 
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}

	int WindowGLFW::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}

	WindowGLFW::~WindowGLFW()
	{
		glfwTerminate();
	}
}