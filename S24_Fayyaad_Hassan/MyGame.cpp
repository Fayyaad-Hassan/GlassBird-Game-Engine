#include "MyGame.h"


	MyGame::MyGame()
	{
		SetKeyPressedCallback([this](const GlassBird::KeyPressed& kP) {OnKeyPressed(kP); });
	}

	void MyGame::Initialize()
	{

	}

	void MyGame::OnUpdate()
	{

		if (turkCaught)
		{
			GlassBird::Renderer::Draw(Win);
		}
		else
		{
			GlassBird::Renderer::Draw(Void);
			GlassBird::Renderer::Draw(Turkey);
			GlassBird::Renderer::Draw(Scope);
		}

		checkCollision();

	}

	void MyGame::Shutdown()
	{
	}

	void MyGame::OnKeyPressed(const GlassBird::KeyPressed& kP)
	{
		switch (kP.GetKeyCode()) 
		{
		case GLASSBIRD_KEY_LEFT : 
			Scope.UpdateXCoord(-30);
			break;
		case GLASSBIRD_KEY_UP:
			Scope.UpdateYCoord(30);
			break;
		case GLASSBIRD_KEY_DOWN:
			Scope.UpdateYCoord(-30);
			break;
		case GLASSBIRD_KEY_RIGHT:
			Scope.UpdateXCoord(30);
			break;
		case GLASSBIRD_KEY_SPACE:
			if (GlassBird::UnitsOverlap(Scope, Turkey))
			{
				turkCaught = true;
				Turkey.SetCoords(2000, 2000);
			}
			break;
		}
	}


	void MyGame::spawnTurkey()
	{
		int turkX = rand() % (GlassBird::GlassBirdWindow::GetWindow()->GetWidth() - 75) + 10 ;
		int turkY = rand() % (GlassBird::GlassBirdWindow::GetWindow()->GetHeight() -75) + 10 ;

		Void.SetCoords(turkX - 25, turkY - 25);
		Turkey.SetCoords(turkX, turkY);
	}

	void MyGame::checkCollision()
	{

		if (GlassBird::UnitsOverlap(Scope, Void))
		{
			int chance = rand() % 100;

			if (chance > 50)
			{
				spawnTurkey();
			}

		}
	}
