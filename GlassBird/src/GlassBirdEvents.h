#pragma once

#include "Utility.h"

namespace GlassBird
{
	class GLASSBIRD_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class GLASSBIRD_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};
}
