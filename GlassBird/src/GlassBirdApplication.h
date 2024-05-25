#pragma once

#include "pch.h"
#include "Utility.h"
#include "GlassBirdEvents.h"

constexpr int GLASSBIRD_FRAME_RATE{ 60 };

namespace GlassBird
{
	class GLASSBIRD_API GlassBirdApplication
	{
	public:
		virtual void Initialize();
		virtual void OnUpdate();
		virtual void Shutdown();

		void Run();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

	private:
		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / GLASSBIRD_FRAME_RATE };
	};
}