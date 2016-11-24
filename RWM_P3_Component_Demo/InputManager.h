#pragma once

#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
#endif



#include "EventHandler.h"

/*Convert input into logical events*/
class InputManager
{
public:
	void ProcessInput();
};

