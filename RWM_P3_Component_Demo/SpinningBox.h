#pragma once

#include "GameObject.h"
#include "BasicTypes.h"
#include "Event.h"

/**define a box that spins around the centre*/
class SpinningBox:public GameObject, public EventListener
{
	
public:
	SpinningBox(Rect r) :rect(r) { angVel = .0f; };
	SpinningBox();
	~SpinningBox();

	Rect rect;
	Colour col;

	float angVel; //control rate of spin
	Vector2D vel;

	void render(Renderer & r);

	void update(unsigned int deltaTime);

	void onEvent(const Event);
};

