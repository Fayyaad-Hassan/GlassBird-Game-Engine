#pragma once

#define START_GAME(className) \
int main()\
{\
	className _game;\
	_game.Run();\
	return 0;\
}

#ifdef GLASSBIRD_MS_COMPILER
	#ifdef GLASSBIRD_LIB
		#define GLASSBIRD_API __declspec(dllexport)
	#else 
		#define GLASSBIRD_API __declspec(dllimport)
	#endif 
#else
		#define GLASSBIRD_API
#endif


#if GLASSBIRD_DEBUG == 2
	#define GLASSBIRD_ERROR(x) std::cout << x << std::endl;
	#define GLASSBIRD_LOG(x) std::cout << x << std::endl;
#elif GLASSBIRD_DEBUG == 1
	#define GLASSBIRD_ERROR(x) std::cout << x << std::endl;
	#define GLASSBIRD_LOG(x)
#else
	#define GLASSBIRD_ERROR(x)
	#define GLASSBIRD_LOG(x)

#endif