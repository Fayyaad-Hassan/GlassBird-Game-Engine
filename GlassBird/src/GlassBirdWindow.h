#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "Utility.h"

namespace GlassBird
{
	class GLASSBIRD_API GlassBirdWindow
	{
	public:
		static void Init();
		static GlassBirdWindow* GetWindow();
		static void ShutDown();


		void SwapBuffers();
		void PollEvents();
		void Create(int width, int height);
		int GetWidth() const;
		int GetHeight() const;

	private:
		inline static GlassBirdWindow* mInstance{ nullptr };

		std::unique_ptr<WindowImpl> mWindow{nullptr};

		GlassBirdWindow();

	};


}