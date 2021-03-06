#pragma once

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "InputManager.h"
#include "ClockComponent.h"
#include "SDLLabelComponent.h"
#include "RectangleSelectionComponent.h"


/** The game object which manages the game loop*/
class Game:public EventListener
{
	InputManager inputManager;
	Renderer renderer;

	std::vector<GameObject*> gameObjects;


	ClockComponent myClock;
	SDLLabelComponent label1, label2;
	RectangleSelectionComponent rectSelComp;

	unsigned int lastTime;//time of last update;

	bool pause;
	bool quit;

public:
	Game();
	~Game();

	bool init();
	void destroy();

	void update();
	void render();
	void loop();

	void onEvent(const Event);
};

