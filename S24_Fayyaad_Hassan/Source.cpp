#include "GlassBird.h"
#include <iostream>

class MyGame : public GlassBird::GlassBirdApplication
{
	virtual void Initialize() override
	{

	}

	virtual void OnUpdate() override
	{
		std::cout << "window width " << GlassBird::GlassBirdWindow::GetWindow()->GetWidth() << std::endl;
	}

private:

};

START_GAME(MyGame);