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
					newevent.name = "pause";
					EventHandler::getInstance().dispatch(newevent);
					break;

				case SDLK_r:
					newevent.name = "reverse";
					EventHandler::getInstance().dispatch(Event("sds"));
					break;

				}
				break;

			
			/* SDL_QUIT event (window close) */
			case SDL_QUIT:
				newevent.name="quit";
				EventHandler::getInstance().dispatch(newevent);
				break;

			default:
				break;
			}
		
		
	
	}
	//check for exit
}
