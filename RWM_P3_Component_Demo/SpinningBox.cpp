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
	
	//apply a rotation about the box's centre
	//rect.pos.x = (float)cos(angle)*p.x - (float)sin(angle)*p.y;
	//rect.pos.y = (float)sin(angle)*p.x + (float)cos(angle)*p.y;

	//drop the box
	rect.pos.x += vel.x;
	rect.pos.y += vel.y;

}

void SpinningBox::onEvent(const Event e)
{
	if (e.type == Events::reverse) {
		angVel *= -1;
	}
}
