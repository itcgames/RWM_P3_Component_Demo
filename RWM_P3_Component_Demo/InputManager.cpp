#include "stdafx.h"
#include "InputManager.h"

//Generate events
void InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		Event newevent;
		switch (e.type) {
			/* Keyboard event */
			case SDL_KEYDOWN:
				
				switch (e.key.keysym.sym) {
				case SDLK_SPACE:
					newevent.type = Events::pause;
					break;

				case SDLK_r:
					newevent.type = Events::pause;
					break;

				}
				break;

			
			/* SDL_QUIT event (window close) */
			case SDL_QUIT:
				newevent.type=Events::quit;
				break;

			default:
				break;
			}
		
		
	
	}
	//check for exit
}
