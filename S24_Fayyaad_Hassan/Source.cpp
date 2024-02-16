#include "GlassBird.h"
#include <iostream>

class MyGame : public GlassBird::GlassBirdApplication
{
	virtual void OnUpdate() override
	{
		std::cout << "Engine is Running" << std::endl;
	}
};

START_GAME(MyGame);