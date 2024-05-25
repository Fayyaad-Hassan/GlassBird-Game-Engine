#pragma once

#include "GlassBird.h"


	class MyGame : public GlassBird::GlassBirdApplication
	{


	public:
		MyGame();

		virtual void Initialize() override;
		virtual void OnUpdate() override;
		virtual void Shutdown() override;

		void OnKeyPressed(const GlassBird::KeyPressed& kP);

		void spawnTurkey();
		void checkCollision();

	private:
		GlassBird::Unit Turkey{ "../Assets/turkey.png", 800, 400 };
		GlassBird::Unit Scope{ "../Assets/scope.png", 100, 100 };
		GlassBird::Unit Void{ "../Assets/void.png", 800, 400 };
		GlassBird::Unit Win{ "../Assets/winner.png", 200, 300 };


		bool turkCaught = false;
	};