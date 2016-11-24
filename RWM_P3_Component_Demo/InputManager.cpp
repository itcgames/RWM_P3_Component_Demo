#include "stdafx.h"
#include "InputManager.h"

//Generate events
void InputManager::ProcessInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type) {
			/* Keyboard event */
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_SPACE:
					
					EventHandler::getInstance().Dispatch("pause");
					break;

				case SDLK_r:

					EventHandler::getInstance().Dispatch("reverse");
					break;

				}
				break;

			
			/* SDL_QUIT event (window close) */
			case SDL_QUIT:

				EventHandler::getInstance().Dispatch("quit");
				break;

			default:
				break;
			}
		
		
	
	}
	//check for exit
}
