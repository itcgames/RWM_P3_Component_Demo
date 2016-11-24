#include "stdafx.h"

#include "SpinningBox.h"


SpinningBox::SpinningBox()
{
}

SpinningBox::~SpinningBox()
{
}

void SpinningBox::render(Renderer& r) {
	r.drawWorldRect(rect,col);
}


void SpinningBox::update(unsigned int deltaTime) {

	float angle = angVel*deltaTime/1000;
	Point2D p = rect.pos;//current position
	
	//apply a rotation about the origin transform
	rect.pos.x = (float)cos(angle)*p.x- (float)sin(angle)*p.y;
	rect.pos.y = (float)sin(angle)*p.x + (float)cos(angle)*p.y;

}

void SpinningBox::onEvent(std::string eventname)
{
	if (eventname == "reverse") {
		angVel *= -1;
	}
}
