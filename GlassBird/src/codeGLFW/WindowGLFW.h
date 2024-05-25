#pragma once

#include"../WindowImpl.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace GlassBird
{
	class WindowGLFW : public WindowImpl
	{
	public:
		WindowGLFW();
		virtual void Create(int width, int height) override;
		virtual void SwapBuffers() override;
		virtual void PollEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~WindowGLFW();

	private:
		GLFWwindow* mWindow{ nullptr };
	};
}