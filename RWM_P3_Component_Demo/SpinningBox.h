#pragma once

#include "GameObject.h"
#include "BasicTypes.h"
#include "EventListener.h"

/**define a box that spins aronf the centre*/
class SpinningBox:public GameObject, public EventListener
{
	
public:
	SpinningBox(Rect r) :rect(r) { angVel = .0f; };
	SpinningBox();
	~SpinningBox();

	Rect rect;
	Colour col;

	float angVel; //control rate of spin

	void render(Renderer & r);

	void update(unsigned int deltaTime);

	void onEvent(const Event);
};

