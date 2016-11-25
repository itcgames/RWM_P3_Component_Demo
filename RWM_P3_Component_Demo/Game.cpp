#include "stdafx.h"

#include <iostream>
using namespace std;


#include "EventHandler.h"
#include "LTimer.h"
#include "SpinningBox.h"
#include "Game.h"


const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


Game::Game()
{
	pause = false;
	quit = false;
}


Game::~Game()
{
}


bool Game::init() {	
	Size2D winSize(800,600);

	//creates our renderer, which looks after drawing and the window
	renderer.init(winSize,"Simple SDL App");

	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;
	float vpWidth = 20;
	Size2D vpSize(vpWidth, vpWidth /aspectRatio);
	Point2D vpBottomLeft( -vpSize.w / 2, - vpSize.h / 2);

	Rect vpRect(vpBottomLeft,vpSize);
	renderer.setViewPort(vpRect);

	
	lastTime = LTimer::gameTime();


	//want game loop to pause
	EventHandler::getInstance().AddListener("pause", this);
	EventHandler::getInstance().AddListener("quit", this);

	myClock.init();

	EventHandler::getInstance().AddListener("newbox", this);

	label1.setText("Drag Mouse to make boxes!");
	label2.setPos(300,300);


	return true;

}


void Game::destroy()
{
	//empty out the game object vector before quitting
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		delete *i;
	}
	gameObjects.clear();
	renderer.destroy();
}

//** calls update on all game entities*/
void Game::update()
{
	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;//time since last update

	//call update on all game objects
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		(*i)->update(deltaTime);
	}


	//set label2's text to current time
	label2.setText(myClock.getTimeAsString());

	rectSelComp.update(deltaTime);

	//save the curent time for next frame
	lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{
	renderer.clear(Colour(0,0,0));// prepare for new frame
	
	//render every object
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(), e= gameObjects.end(); i != e; i++) {
		(*i)->render(renderer);
	}

	label1.render(renderer.getSDLRenderer());
	label2.render(renderer.getSDLRenderer());

	rectSelComp.render(renderer.getSDLRenderer());


	renderer.present();// display the new frame (swap buffers)

	
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate

	int frameNum = 0;
	while (!quit) { //game loop
		capTimer.start();

		inputManager.ProcessInput();

		if(!pause) //in pause mode don't bother updateing
			update();
		render();

		int frameTicks = capTimer.getTicks();//time since start of frame
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time before going to next frame
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

void Game::onEvent(const Event e) {

	if (e.name == "pause") {
		pause = !pause;
	}
	
	if (e.name == "quit") {
		quit=true;
	}

	if (e.name == "newbox") {
			SDL_Rect rect_ptr = e.getData<SDL_Rect>();
			Rect worldrect = renderer.screenToWorld(Rect(rect_ptr.x, rect_ptr.y, rect_ptr.w, rect_ptr.h));
			SpinningBox* newBox = new SpinningBox(worldrect);
			newBox->col = Colour(randBetween(50,255), randBetween(50, 255), randBetween(50, 255));
			newBox->vel = { 0,randBetween(-0.01f,-0.1f) };
			//newBox->angVel =  rand-0.5+(rand() % 100 / 100.0);



			gameObjects.push_back(newBox);
	}


}
